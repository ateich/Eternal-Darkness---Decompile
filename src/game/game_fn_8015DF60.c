typedef unsigned int u32;

typedef struct StreamState {
    unsigned char pad0[0x14];
    u32 end;
    u32 cursor;
    u32 read;
    u32 write;
    u32 boundary;
    u32 limit;
} StreamState;

extern volatile StreamState lbl_805BB1E0;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

/* NonMatching: size-exact; retail uses r4 for one dead volatile load, generated uses r3. */
u32 fn_8015DF60(void)
{
    int interrupts;
    int amount;
    int unused;

    interrupts = OSDisableInterrupts();
    if (lbl_805BB1E0.read == lbl_805BB1E0.limit) {
        OSRestoreInterrupts(interrupts);
        return 0;
    }
    if (lbl_805BB1E0.read == lbl_805BB1E0.boundary) {
        OSRestoreInterrupts(interrupts);
        return 0;
    }

    if (lbl_805BB1E0.write > lbl_805BB1E0.cursor) {
        amount = 0x10000U < lbl_805BB1E0.write - lbl_805BB1E0.cursor
                     ? 0x10000
                     : lbl_805BB1E0.write - lbl_805BB1E0.cursor;
        unused = 0x10000U < lbl_805BB1E0.boundary - lbl_805BB1E0.read
                     ? 0x10000
                     : lbl_805BB1E0.boundary - lbl_805BB1E0.read;
    } else {
        amount = 0x10000U < lbl_805BB1E0.end - lbl_805BB1E0.cursor
                     ? 0x10000
                     : lbl_805BB1E0.end - lbl_805BB1E0.cursor;
    }

    unused = lbl_805BB1E0.limit - lbl_805BB1E0.read;
    amount = amount < unused ? amount : lbl_805BB1E0.limit - lbl_805BB1E0.read;
    OSRestoreInterrupts(interrupts);
    return (amount + 31) & ~31;
}
