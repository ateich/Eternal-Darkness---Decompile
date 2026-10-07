typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Entry {
    void* value;
    u32 type;
} Entry;

typedef struct Table {
    u32 count;
    u32 magic;
    Entry entries[1];
} Table;

extern char* lbl_8023EA18[];
extern void* lbl_8064C528;
extern int lbl_8064C7C0;
extern Table* lbl_8064C7D4[2];

extern void fn_80042C38(Table*);
extern int fn_8015D458(void*, int*, void*);
extern void fn_801E85A8(Table*);
extern void* fn_801E86A0(Table*, u32);
extern void* fn_80125788(void*);
extern void fn_8012B954(u8*);
extern u32 fn_801E88E4(Table*);
extern void fn_801E86D8(Table*, Table*);

void fn_80042CAC(int index, int initialize)
{
    u32 i;
    Table* table;
    void* entry;
    void* object;

    if (lbl_8064C7C0 & 0x10) {
        fn_80042C38(lbl_8064C7D4[lbl_8064C7C0 & 1]);
    }
    if (lbl_8064C7C0 & 1) {
        lbl_8064C7C0 |= 0x10;
    }

    table = lbl_8064C7D4[lbl_8064C7C0 & 1];
    fn_8015D458(lbl_8023EA18[index], (int*)table, (void*)0x83A70);
    fn_801E85A8(table);
    for (i = 0; i < fn_801E88E4(table); i++) {
        entry = fn_801E86A0(table, i);
        if (entry != 0) {
            object = fn_80125788(entry);
            if (initialize != 0) {
                fn_8012B954(object);
            }
        }
    }
    fn_801E86D8(lbl_8064C528, table);
    lbl_8064C7C0 ^= 1;
}
