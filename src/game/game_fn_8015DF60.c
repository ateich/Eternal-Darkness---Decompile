typedef unsigned int u32;

typedef struct StreamState {
    unsigned char pad0[0x14];
    unsigned char* volatile end;
    unsigned char* volatile cursor;
    unsigned char* volatile read;
    unsigned char* volatile write;
    unsigned char* volatile limit;
} StreamState;

extern StreamState lbl_805BB1E0;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

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
    if (lbl_805BB1E0.read == lbl_805BB1E0.write) {
        OSRestoreInterrupts(interrupts);
        return 0;
    }

    if (lbl_805BB1E0.write > lbl_805BB1E0.cursor) {
        amount = 0x10000 < lbl_805BB1E0.write - lbl_805BB1E0.cursor
                     ? 0x10000
                     : lbl_805BB1E0.write - lbl_805BB1E0.cursor;
        unused = 0x10000 < lbl_805BB1E0.write - lbl_805BB1E0.read
                     ? 0x10000
                     : lbl_805BB1E0.write - lbl_805BB1E0.read;
    } else {
        amount = 0x10000 < lbl_805BB1E0.end - lbl_805BB1E0.cursor
                     ? 0x10000
                     : lbl_805BB1E0.end - lbl_805BB1E0.cursor;
    }

    unused = lbl_805BB1E0.limit - lbl_805BB1E0.read;
    amount = amount < unused ? amount : lbl_805BB1E0.limit - lbl_805BB1E0.read;
    OSRestoreInterrupts(interrupts);
    return (amount + 31) & ~31;
}
