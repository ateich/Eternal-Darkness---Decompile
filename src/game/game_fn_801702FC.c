extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern double fn_8016A694(void*, int);
extern void fn_801F70B0(void*, float);
extern const char lbl_8024FF00[];
extern unsigned char lbl_8063CD18[];

typedef struct TargetOwner {
    unsigned char padding[0x110];
    unsigned char target;
} TargetOwner;

int fn_801702FC(void* state)
{
    unsigned char* target;

    target = &((TargetOwner*)lbl_8063CD18)->target;

    if (fn_8016A598(state) != 1) {
        fn_80163BB4(state, lbl_8024FF00, 1, fn_8016A598(state));
        return 0;
    }

    fn_801F70B0(target, (float)fn_8016A694(state, 1));
    return 0;
}
