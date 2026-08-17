typedef unsigned char u8;
typedef signed char s8;

typedef struct Runtime {
    char pad_0[0x1DF];
    u8 active_mask;
} Runtime;

extern Runtime lbl_8030F540;
extern void fn_801E5FB0(void*);

void fn_80132D50(void)
{
    char* cursor;
    int mask;
    int i;
    Runtime* runtime;

    runtime = &lbl_8030F540;
    i = 0;
    cursor = (char*)runtime;

    do {
        mask = 1 << i;
        if ((s8)runtime->active_mask & mask) {
            void* object = *(void**)cursor;
            if (object != 0) {
                fn_801E5FB0(object);
            }
            *(void**)cursor = 0;
            runtime->active_mask &= ~mask;
        }
        i++;
        cursor += 0x10;
    } while (i < 5);
}
