typedef signed int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

extern s32 fn_80201B44(void);
extern s32 fn_80201814(s32);
extern s32 fn_80049220(s32, s32);
extern s32 fn_80049304(s32, s32);
extern void *fn_80201C24(void *);
extern u8 fn_80157AB8(void *);
extern s32 fn_8006749C(void);
extern void fn_80120AD0(s32, s32, u16, u32, float, float);
extern void fn_8020104C(s32, s32, s32, s32, float);

extern float lbl_8064E26C;
extern float lbl_8064E270;
extern float lbl_8064E274;
extern float lbl_8064E278;

void fn_8003C114(s32 unused, s32 object, s32 id)
{
    s32 current;
    s32 mode;
    s32 found;
    s32 state;

    current = fn_80201814(fn_80201B44());
    mode = fn_80049220(current, 1);
    found = fn_80049304(current, mode);
    if (found != 0) {
        state = fn_80157AB8(fn_80201C24((void *)found));
        if (state >= 5) {
            goto failure;
        }
        if (state >= 1) {
            goto active;
        }
        goto failure;
active:
        fn_80120AD0(object, 0, 100, (u16)(fn_8006749C() | 2),
                     lbl_8064E26C, lbl_8064E270);
        fn_8020104C(0x11, id, id, 0, lbl_8064E274);
        return;
failure:
        fn_8020104C(0x11, id, id, 0, lbl_8064E278);
        return;
    }
    fn_8020104C(0x11, id, id, 0, lbl_8064E278);
}
