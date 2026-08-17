typedef unsigned char u8;
typedef signed char s8;

typedef struct Runtime {
    char pad_0[0x1C8];
    int counter;
    char pad_1CC[0xF];
    s8 mode;
} Runtime;

typedef struct Manager {
    char pad_0[0x34];
    int limit;
} Manager;

extern Runtime lbl_8030F540;
extern int fn_8015E4B4(void);
extern Manager* fn_8015E4A4(void);
extern void fn_80133510(Manager*);
extern void fn_8015E1A8(int);
extern void fn_8005391C(int, int);
extern void fn_80131388(int);

int fn_80133300(void)
{
    int result = 1;

    if (fn_8015E4B4()) {
        Manager* manager = fn_8015E4A4();
        Runtime* runtime = &lbl_8030F540;

        runtime->counter = runtime->counter + 1;
        if (runtime->counter == 0) {
            fn_80133510(manager);
        }
        if ((runtime->counter >> 1) < manager->limit) {
            fn_8015E1A8(runtime->counter >> 1);
        } else if (lbl_8030F540.mode == 2) {
            runtime->counter--;
            fn_8015E1A8(runtime->counter >> 1);
        } else {
            fn_8005391C(2, 0);
            result = 0;
        }
        fn_80131388(runtime->counter >> 1);
    }
    return result;
}
