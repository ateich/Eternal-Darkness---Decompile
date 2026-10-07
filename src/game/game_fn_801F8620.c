typedef struct SavedState {
    float first_value;
    float second_value;
    unsigned int first_handle;
    unsigned int second_handle;
    unsigned int token;
} SavedState;

typedef struct LiveState {
    unsigned char pad0[0x30];
    float value;
    unsigned char pad34[0x3C];
    unsigned int handle;
    unsigned char pad74[0x14];
} LiveState;

typedef struct Globals {
    LiveState states[26];
    SavedState saved[5];
} Globals;

extern Globals lbl_8063C6B8;
extern volatile int lbl_8064D7BC;
extern unsigned int fn_801FA44C(void);

void fn_801F8620(void)
{
    register volatile SavedState* saved;
    register volatile LiveState* first;
    register volatile LiveState* second;
    register Globals* globals;
    register int count;

    count = lbl_8064D7BC;
    globals = &lbl_8063C6B8;
    saved = globals->saved;
    /* ASM: mulli/addi/addi/stw/lfs/addi/add/lwz preserve the retail snapshot
       address calculation and load schedule, which MWCC folds under C alias analysis. */
    asm {
        mulli r5, count, 0x14
        addi r0, count, 1
        addi first, globals, 0xCC0
        stw r0, lbl_8064D7BC(r13)
        lfs f0, 0x30(first)
        addi second, globals, 0xD48
        add saved, saved, r5
        lwz r3, 0x70(first)
    }
    /* ASM: stfs/lfs/lwz/stfs/stw/stw retain the paired value/handle transfer order. */
    asm {
        stfs f0, 0(saved)
        lfs f0, 0x30(second)
        lwz r0, 0x70(second)
        stfs f0, 4(saved)
        stw r3, 8(saved)
        stw r0, 0xC(saved)
    }
    saved->token = fn_801FA44C();
}
