typedef signed short s16;

typedef struct Runtime {
    unsigned char pad[0xEC];
    s16 first;
    unsigned char padEE[0x18];
    s16 second;
} Runtime;

typedef struct Context {
    unsigned char pad[0x8C];
    Runtime *runtime;
} Context;

extern void fn_8012C478(void *, int, int);
extern int fn_800D6A28(int);
extern void fn_800A4AC4(void *, int, int, int);

void fn_800D8E30(void *object, Context *context)
{
    Runtime *runtime = context->runtime;
    int value;

    fn_8012C478(object, 0, 0);
    if (runtime->first == 0) {
        value = fn_800D6A28(1);
        fn_800A4AC4(object, 1, value, 0);
    }
    if (runtime->second == 0) {
        fn_800A4AC4(object, 14, fn_800D6A28(14), 0);
    }
}
