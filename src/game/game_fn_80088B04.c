typedef unsigned char u8;
typedef signed short s16;

typedef struct Context {
    u8 pad[8];
    s16 counter;
} Context;

extern int fn_80070CD8(int);
extern Context* fn_8006ED3C(void*, int, int*);
extern void fn_801F74C8(int, int);
extern int fn_801A98F4(int, int);
extern void fn_801441C0(int, int, int);
extern void fn_8006BEE4(Context*, void (*)(void));
extern void fn_8006EA4C(void);

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int fn_80088B04(Context* work)
{
    int result = 0;
    u8 volume;

    if (fn_80070CD8(0) != 0) {
        int index;
        int value;
        int count;

        work = fn_8006ED3C(work, 8, &index);
        work->counter++;
        count = work->counter;
        value = count * 16;
        volume = MIN(MAX(value, 0), 127);
        if (count <= 6) {
            fn_801F74C8(30, 1);
            fn_801A98F4(181, volume);
            fn_801441C0(1, 1, 22);
        } else {
            fn_801A98F4(182, 127);
            work->counter = 0;
            fn_8006BEE4(work, fn_8006EA4C);
            result = 1;
        }
    }
    return result;
}
