typedef unsigned long long u64;
typedef unsigned int u32;
typedef int s32;

extern unsigned int lbl_8064C5F0;
extern int lbl_8064C5D8;
extern int lbl_8064D18C;
extern const float lbl_8064DCBC;

extern int fn_801F349C(void);
extern int fn_800460EC(void);
extern int fn_801A5CE0(void);
extern int fn_801A5D04(void);
extern int fn_80201B44(void);
extern void *fn_80201814();
extern void *fn_80201B9C(void);
extern void* fn_80204844(void*, int);
extern void fn_8006D444(void);
extern int fn_8006BCB4(void);
extern unsigned long long fn_8020123C();
extern int fn_801D1374(void);
extern int fn_80070A6C(int);
extern int fn_80201B54();
extern void fn_80200EAC(float, int, int, int, int);
extern void fn_8001D9FC(int);
extern void fn_80180BE4(void);
extern void fn_800073DC(int);
extern void fn_801EFE84(int);
extern void fn_80144C40(void);

void fn_80006D50(void)
{
    int value;
    int context;
    int state;
    int status;
    u32 result;

    status = fn_801F349C();
    if (lbl_8064C5F0 != 0) {
        return;
    }
    if (status != 0) {
        return;
    }
    if (fn_800460EC() != 0) {
        return;
    }
    if (fn_801A5CE0() == 0) {
        if (fn_801A5D04() == 0) {
            return;
        }
    }

    context = fn_80201B44();
    fn_80201814(context);
    state = (int)fn_80204844(fn_80201B9C(), 0x20);
    fn_8006D444();
    value = fn_8006BCB4();

    result = fn_8020123C(0x87, 0, context, 0) & 0xFFFFFFFFULL;
    if (result != 1) {
        return;
    }
    if (fn_801D1374() != 0) {
        return;
    }
    if (fn_80070A6C(1) != 0) {
        return;
    }

    context = 3;
    if (lbl_8064C5D8 == 0) {
        switch (value) {
        case 25:
            result = fn_8020123C(0x54, 0, fn_80201B54(state), 0) & 0xFFFFFFFFULL;
            if (result == 1) {
                context = 8;
            }
            break;
        case 26:
            result = fn_8020123C(0x54, 0, fn_80201B54(state), 0) & 0xFFFFFFFFULL;
            if (result == 1) {
                context = 7;
            }
            break;
        case 28:
            result = fn_8020123C(0x54, 0, fn_80201B54(state), 0) & 0xFFFFFFFFULL;
            if (result == 1) {
                context = 10;
            }
            break;
        }
    }

    fn_80200EAC(lbl_8064DCBC, 0x1C, 0, 1, lbl_8064D18C);
    fn_8001D9FC(context);
    fn_80180BE4();
    fn_800073DC(2);
    fn_801EFE84(1);
    fn_80144C40();
}
