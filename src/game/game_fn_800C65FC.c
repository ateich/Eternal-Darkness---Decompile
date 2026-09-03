typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

extern u32 lbl_8064D5A8;
extern float lbl_8064F1A8;
extern float lbl_8064F1F4;
extern float lbl_8064F1F8;

extern int fn_80201B44();
extern int fn_80201B54();
extern int fn_80038308(void *, int, s16 *);
extern int fn_80038464(void *, int, s16 *);
extern void fn_801441C0(int, int, int);
extern int fn_801A98F4(int, int);

void fn_800C65FC(void *object)
{
    s32 current;
    s32 object_id;
    s16 x;
    s16 y;
    float ratio;

    if (object == 0) {
        return;
    }
    current = ((s32)fn_80201B44());
    object_id = ((s32)fn_80201B54(object));
    if (object_id != current) {
        return;
    }
    if ((lbl_8064D5A8 & 0x3F) != 0 &&
        (lbl_8064D5A8 & 0x7F) != 0 &&
        (lbl_8064D5A8 & 0xFF) != 0) {
        return;
    }

    fn_80038308(object, 0, &x);
    fn_80038464(object, 0, &y);
    ratio = (float)x / (float)y;
    if (ratio < lbl_8064F1F4 && x != 0 && (lbl_8064D5A8 & 0x3F) == 0) {
        fn_801441C0(11, 0, 11);
        fn_801A98F4(500, 115);
    } else if (ratio < lbl_8064F1F8 && x != 0 && (lbl_8064D5A8 & 0x7F) == 0) {
        fn_801441C0(6, 0, 6);
        fn_801A98F4(500, 100);
    } else if (ratio < lbl_8064F1A8 && x != 0 && (lbl_8064D5A8 & 0xFF) == 0) {
        fn_801441C0(6, 0, 6);
        fn_801A98F4(500, 90);
    }
}
