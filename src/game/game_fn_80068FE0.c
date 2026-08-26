typedef signed int s32;
typedef unsigned int u32;

extern u32 lbl_8065195C;
extern u32 lbl_8064E730;
extern u32 lbl_8064E734;
extern u32 lbl_80651960;
extern u32 lbl_8064E738;
extern u32 lbl_8064E73C;
extern u32 lbl_80651964;
extern u32 lbl_8064E740;
extern u32 lbl_8064E744;
extern u32 lbl_80651968;
extern u32 lbl_8064E748;
extern u32 lbl_8064E74C;
extern u32 lbl_8064E750;
extern u32 lbl_8064E754;
extern u32 lbl_8064E758;

extern void* fn_8012C62C(void *object, s32 index, u32 *a, u32 *b, u32 *c,
                       s32 count);
extern s32 fn_80066D04(void *context, s32 index);
extern u32 fn_80036D5C(void *context);
extern s32 fn_801261F4(void *object);
extern void fn_8012F58C(void *object, s32 index, s32 a, s32 b, s32 c, s32 d);

void fn_80068FE0(void *context, void *object)
{
    u32 c0;
    u32 b0;
    u32 a0;

    a0 = lbl_8064E734;
    b0 = lbl_8065195C;
    c0 = lbl_8064E730;

    fn_8012C62C(object, 1, &c0, &b0, &a0, 4);

    if (fn_80066D04(context, 2)) {
        u32 c2;
        u32 b2;
        u32 a2;
        a2 = lbl_8064E73C;
        b2 = lbl_80651960;
        c2 = lbl_8064E738;
        fn_8012C62C(object, 2, &c2, &b2, &a2, 4);
    }
    if (fn_80066D04(context, 3)) {
        u32 c3;
        u32 b3;
        u32 a3;
        a3 = lbl_8064E744;
        b3 = lbl_80651964;
        c3 = lbl_8064E740;
        fn_8012C62C(object, 3, &c3, &b3, &a3, 4);
    }
    if (fn_80066D04(context, 0)) {
        u32 c1;
        u32 b1;
        u32 a1;
        a1 = lbl_8064E74C;
        b1 = lbl_80651968;
        c1 = lbl_8064E748;
        fn_8012C62C(object, 0, &c1, &b1, &a1, 4);
    }
    if ((fn_80036D5C(context) & 0x20000) != 0) {
        u32 c4;
        u32 b4;
        u32 a4;

        fn_801261F4(object);
        a4 = lbl_8064E758;
        b4 = lbl_8064E754;
        c4 = lbl_8064E750;
        fn_8012C62C(object, 15, &c4, &b4, &a4, 0x12);
        fn_8012F58C(object, 15, 0, 1, 0x1E, 8);
    }
}
