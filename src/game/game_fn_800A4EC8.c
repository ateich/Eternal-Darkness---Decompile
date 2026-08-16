typedef unsigned char u8;

typedef struct Entry800A4EC8 {
    u8 pad0[0x198];
    int index;
} Entry800A4EC8;

typedef struct Values800A4EC8 {
    u8 pad0[0xEA];
    short values[1];
} Values800A4EC8;

typedef struct Runtime800A4EC8 {
    u8 pad0[0x64];
    Entry800A4EC8* entry;
    u8 pad68[0x24];
    Values800A4EC8* values;
} Runtime800A4EC8;

extern int fn_801A7590(void*);
extern void *fn_80201B8C();

int fn_800A4EC8(void* object, void* value)
{
    int mask = fn_801A7590(value);
    int result = 0;
    Runtime800A4EC8* runtime = ((Runtime800A4EC8*)fn_80201B8C(object));
    Entry800A4EC8* entry = runtime->entry;
    Values800A4EC8* values = runtime->values;

    if (entry->index != -1 && (mask & (1 << entry->index)) != 0) {
        result = values->values[entry->index];
    }
    return result;
}
