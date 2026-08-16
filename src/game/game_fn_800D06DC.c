typedef unsigned char u8;

typedef struct Status {
    u8 pad_000[0xEA];
    short slot0;
    short slot1;
    u8 pad_0EE[0x18];
    short slot14;
} Status;

typedef struct Context {
    u8 pad_000[0x8C];
    Status *status;
} Context;

extern int fn_800D00C0(int);
extern void fn_800A4AC4(void *, int, int, int);

void fn_800D06DC(void *object, Context *context)
{
    Status *status = context->status;

    if (status->slot0 == 0) {
        int value = fn_800D00C0(0);
        fn_800A4AC4(object, 0, value, 0);
    }
    if (status->slot1 == 0) {
        fn_800A4AC4(object, 1, fn_800D00C0(1), 0);
    }
    if (status->slot14 == 0) {
        fn_800A4AC4(object, 14, fn_800D00C0(14), 0);
    }
}
