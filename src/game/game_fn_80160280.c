typedef struct Entry {
    int type;
    char pad4[4];
    void* child;
    char padC[4];
} Entry;

typedef struct List {
    char pad0[4];
    Entry* entries;
} List;

typedef struct Link2 { void* root; } Link2;
typedef struct Link1 { Link2* link; } Link1;
typedef struct Root {
    char pad0[8];
    char** items;
} Root;

extern Entry* fn_8015FEB8(List*, int, Entry*);
extern int fn_8015FE80(Entry*);
extern int fn_8015FFE8(Entry*);
extern unsigned int fn_801600AC(Root*, int, int);
extern char* fn_801613C8(Root*, int, int);
extern char lbl_8064BA40;
extern char lbl_8064BA48;
extern char lbl_8064BA50;

char* fn_80160280(List* list, Entry* position, char** output)
{
    Entry* entry = fn_8015FEB8(list, 0, position);
    Root* root;
    int ordinal;
    unsigned int token;

    if (!fn_8015FE80(entry))
        return 0;

    root = (Root*)((Link1*)entry->child)->link->root;
    ordinal = fn_8015FFE8(entry);
    token = fn_801600AC(root, ordinal, (position - (entry + 1)));

    switch (token & 0x3f) {
    case 12:
        *output = *(char**)((char*)root->items +
                           ((token >> 4) & 0x0ffffffc)) + 0x14;
        return &lbl_8064BA40;
    case 11:
        *output = fn_801613C8(root, (token >> 6) + 1, ordinal);
        return &lbl_8064BA48;
    case 14:
    case 16:
        *output = *(char**)((char*)root->items +
                           ((token >> 4) & 0x0ffffffc)) + 0x14;
        return &lbl_8064BA50;
    default:
        return 0;
    }
}
