typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned long long u64;

#pragma use_lmw_stmw on

extern u8 lbl_8064C884;

extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern s32 fn_80128EAC(void *object);
extern void fn_8012B344();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern int fn_80200C38();
extern int fn_80201B44();
extern void fn_801D0D30(s32 value);
extern u64 fn_802011D4(void *event);
extern void *fn_8004918C(void);
extern s32 fn_80049694(void);
extern s32 fn_801D1374(void);
extern void* fn_80201B3C();
extern int fn_80038308(void *, int, short *);

s32 fn_8005AF34(void *context, void *event, u32 *result)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    fn_80201B54(context);

    if (kind == 3) {
        lbl_8064C884++;
        return 1;
    }
    if (kind == 1) {
        s32 type = fn_80128EAC(object);
        lbl_8064C884 = 0;
        if (type == 16 || type == 17)
            fn_8012B344(object);
        return 1;
    }
    if (kind == 176) {
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 184) {
        fn_80201D2C(context, 78);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 44) {
        fn_80200C38(event);
        if (lbl_8064C884 > 2)
            fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 229) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 207) {
        fn_8004918C();
        if (fn_80049694() != 0) {
            fn_801D0D30(fn_80201B44());
            if (result != 0)
                *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        }
        return 1;
    }
    if (kind == 208) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 177) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 198) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 155) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 46) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 40) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 107) {
        if (fn_80200C38(event) != 0)
            fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 8) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 135) {
        if (fn_801D1374() == 0 && result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 32) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 53) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 30) {
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 105) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 133) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 61) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 125) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 52) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 31) {
        fn_801D0D30(fn_80201B44());
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        return 1;
    }
    if (kind == 39) {
        s16 old_value;
        s16 new_value;
        fn_80038308(fn_80201B3C(), 0, &old_value);
        if (result != 0)
            *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        fn_80038308(fn_80201B3C(), 0, &new_value);
        if (new_value < old_value)
            fn_801D0D30(fn_80201B44());
        return 1;
    }
    if (kind == 175) {
        if (result != 0)
            *result = 0;
        return 1;
    }
    return 0;
}
