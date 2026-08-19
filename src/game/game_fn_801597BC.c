typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u32 lbl_8064C4E4;
extern int lbl_8064C4F4;
extern int lbl_8064C5C0;
extern int lbl_8064D18C;
extern float lbl_80650630;
extern float lbl_80650634;
extern float lbl_80650638;
extern char lbl_8063CD18[];

extern void fn_80046774(int);
extern int fn_8004610C(int);
extern void fn_80159440(int, u32);
extern void fn_80046C98(int);
extern void* fn_8016BA38(int);
extern void* fn_8015C4A4(int, int);
extern void* fn_80158ABC(void*, int, float*);
extern void fn_80179DB0(Vec3*, void*);
extern void fn_801379E4(int, Vec3*, float);
extern u32 fn_80201B44(void);
extern u64 fn_8020123C(int, u32, u32, int);
extern void fn_8012B7A0(int, float);
extern void fn_80046430(int, int, int, int);
extern void fn_800BC74C(int);
extern void fn_80045980(void);
extern void fn_800459A0(void);
extern void fn_80180C94(void);
extern void fn_80200EAC(int, int, int, float, int);
extern int fn_801FA250(int, int, int);
extern void fn_801FA01C(void*, int, int, int, int, int, int, int, int, int);
extern void fn_801F8598(void);
extern void fn_801FA410(int);
extern void fn_801FA354(void);
extern void fn_8016B400(int, int, int);

void fn_801597BC(int value, int source, int room, int effect, u32 flags)
{
    int state;
    int handle;
    u32 timestamp;
    float distance;
    Vec3 position;
    void* object;
    char* base;
    int zero;
    int actor;

    fn_80046774(value);
    state = fn_8004610C(value);
    fn_80159440(value, flags);

    if (lbl_8064C4E4 != 0 && lbl_8064C5C0 == 0) {
        if (flags & 2) {
            fn_80046C98(0);
        }
        if (flags & 1) {
            object = fn_8016BA38(0);
        } else {
            object = fn_80158ABC(fn_8015C4A4(source, 2), 2, &distance);
        }
        if (object != 0) {
            fn_80179DB0(&position, object);
            fn_801379E4(lbl_8064C4E4, &position, lbl_80650634);
            timestamp = fn_80201B44();
            handle = (int)(fn_8020123C(0xEE, timestamp, timestamp, 0) & 0xFFFFFFFF);
            if (handle != -1) {
                fn_8012B7A0(lbl_8064C4E4, lbl_80650638 + distance);
                fn_8020123C(0xBF, timestamp, timestamp, handle);
            } else {
                fn_8012B7A0(lbl_8064C4E4, distance);
            }
        }
        fn_80046430(state, value, source, room);
    }

    fn_800BC74C(0);
    fn_80045980();
    fn_800459A0();
    if (lbl_8064C4F4 == 0) {
        fn_80180C94();
        fn_80200EAC(62, 0, 0, lbl_80650630, lbl_8064D18C);
    }

    base = lbl_8063CD18;
    zero = 0;
    actor = fn_801FA250(room, 2, zero);
    fn_801FA01C(base + 0x110, actor, zero, zero, zero, zero, zero, zero, zero, 1);
    fn_801F8598();
    fn_801FA410(2);
    fn_801FA354();
    if (effect > 0) {
        fn_8016B400(effect, 0, 0);
    }
    lbl_8064C5C0 = 0;
}
