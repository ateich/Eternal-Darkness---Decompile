typedef unsigned char u8;
typedef signed char s8;

typedef struct Entry {
    char pad_0[4];
    void* object;
    int type;
    s8 active;
    char pad_D[3];
} Entry;

typedef struct Manager {
    char pad_0[0xC];
    Entry* entries;
} Manager;

typedef struct Command {
    char pad_0[0x20];
    s8 index;
    u8 active;
    char pad_22[2];
} Command;

typedef struct CommandList {
    char pad_0[0x68];
    Command* commands;
    char pad_6C[0x18];
    u8 count;
} CommandList;

extern void fn_80133FA8(Command*, Entry*);
extern void fn_8013430C(Command*, Entry*);
extern void fn_8013454C(Command*, Entry*);
extern void fn_80134770(Command*, Entry*);
extern void fn_801349BC(Command*, Entry*);
extern void fn_80134210(Manager*);

void fn_80133EC0(Manager* manager, CommandList* list)
{
    int offset = 0;
    int i = 0;

    while (i < list->count) {
        Command* command = (Command*)((char*)list->commands + offset);
        Entry* entry = manager->entries + command->index;

        entry->active = command->active;
        if (entry->active != 0) {
            switch (entry->type) {
            case 35:
            case 36:
            case 37:
            case 38:
            case 40:
            case 43:
                fn_80133FA8(command, entry);
                break;
            case 39:
                fn_8013430C(command, entry);
                break;
            case 41:
                fn_8013454C(command, entry);
                break;
            case 42:
                fn_80134770(command, entry);
                break;
            case 44:
                fn_801349BC(command, entry);
                break;
            }
        }
        offset += 0x24;
        i++;
    }
    fn_80134210(manager);
}
