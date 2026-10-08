typedef struct DataBlock {
    struct { unsigned char data[0x20]; } queue0;
    unsigned char pad20[0xC];
    struct { unsigned char data[0x20]; } queue1;
    unsigned char pad4C[0xC];
    struct { unsigned char data[0x20]; } queue2;
    unsigned char pad78[0x18];
    struct { unsigned char data[0x20]; } queue3;
    unsigned char padB0[0x18];
    unsigned char queue1Storage[0x10];
    unsigned char queue3Storage[0x10];
    unsigned char queue0Storage[0x10];
    struct { unsigned char data[0x20]; } queue4;
    unsigned char thread[0x310];
    unsigned long stack[0x800];
} DataBlock;

extern DataBlock lbl_80304060;

extern int lbl_8064C7C4;
extern int lbl_8064C7C8;
extern int lbl_8064C7CC;
extern int lbl_8064C7D0;
extern unsigned short lbl_8064C7E4;
extern unsigned short lbl_8064C7EC;
extern int lbl_8064C7F8;

extern void fn_800433FC(void);
extern void fn_8020D1F0(void*, void*, int);
extern void fn_8020F84C(void*, void*, void*, void*, int, int, int);
extern void fn_8020FC0C(void*);

void fn_800432F4(void)
{
    register DataBlock* block = &lbl_80304060;

    lbl_8064C7D0 = 0;
    lbl_8064C7C8 = 0;
    lbl_8064C7CC = -1;
    lbl_8064C7F8 = 0;

    if (lbl_8064C7C4 == 0) {
        fn_8020D1F0((void*)((unsigned long)block + 0x2C),
                    (void*)((unsigned long)block + 0xC8), 4);
        fn_8020D1F0((void*)((unsigned long)block + 0x90),
                    (void*)((unsigned long)block + 0xD8), 4);
        {
            register void* queue;
            /* ASM: addi preserves the retail zero-offset address operation;
             * the C optimizer canonicalizes this expression to mr. */
            asm {
                addi queue, block, 0
            }
            fn_8020D1F0(queue, (void*)((unsigned long)block + 0xE8), 4);
        }
        fn_8020D1F0((void*)((unsigned long)block + 0x58), &lbl_8064C7EC, 2);
        fn_8020D1F0((void*)((unsigned long)block + 0xF8), &lbl_8064C7E4, 2);
        fn_8020F84C(block->thread, fn_800433FC, 0,
                    &block->stack + 1, 0x2000, 0x1D, 1);
        /* ASM: an empty compiler barrier prevents reuse of the thread address
         * across calls; retail recomputes it for the resume operation. */
        asm {
        }
        fn_8020FC0C((void*)((unsigned long)block + 0x118));
        lbl_8064C7C4 = 1;
    }
}
