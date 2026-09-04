typedef unsigned char u8;
typedef unsigned int u32;

typedef struct PoolEntry {
    void* object;
    void* aux;
    u8 pad08[0xEC];
} PoolEntry;

typedef struct ArenaEntry {
    void* small;
    u8 pad04[0x24];
    void* arena;
    u8 pad2C[0x90];
} ArenaEntry;

extern u8 lbl_8064D4E5;
extern u8 lbl_8064D4E4;
extern void* lbl_8064D498;
extern void* lbl_8064D4A0;
extern void* lbl_8064D4A4;
extern void* lbl_8064D4A8;
extern PoolEntry* lbl_8064D4AC;
extern ArenaEntry lbl_80628CB0[];

extern void fn_801CE358(void*);

int fn_801C44B0(void)
{
    u8 i;

    fn_801CE358(lbl_8064D4A0);
    for (i = 0; i < lbl_8064D4E5; i++) {
        fn_801CE358(lbl_8064D4AC[i].object);
        fn_801CE358(lbl_8064D4AC[i].aux);
    }

    for (i = 0; i < lbl_8064D4E4; i++) {
        fn_801CE358(lbl_80628CB0[i].small);
        fn_801CE358(lbl_80628CB0[i].arena);
    }

    fn_801CE358(lbl_8064D4A8);
    fn_801CE358(lbl_8064D4AC);
    fn_801CE358(lbl_8064D4A4);
    fn_801CE358(lbl_8064D498);
    return 1;
}
