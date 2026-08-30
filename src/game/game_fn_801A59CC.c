typedef unsigned char u8;

typedef struct Entry {
    u8 pad0[0xC];
    void* value;
    u8 pad10[0x10];
} Entry;

extern Entry lbl_806079C0[];
extern Entry lbl_802512A4[];
extern void* lbl_8064D26C;
extern void* lbl_8064D264;

extern void fn_801A6CB4(void);
extern void* fn_80144628(int, Entry*, int);
extern void fn_801446D4(void*, void (*)(void));
extern void fn_801446DC(void*, void (*)(void));
extern void fn_801446E4(void*, void*);
extern void fn_801A5D5C(void);
extern void fn_801A5E68(void);
extern void fn_801A5FB0(void);

void fn_801A59CC(void* value)
{
    void* object;

    fn_801A6CB4();
    lbl_806079C0[0].value = value;
    lbl_806079C0[1].value = value;
    lbl_806079C0[2].value = value;
    lbl_806079C0[3].value = value;
    lbl_806079C0[4].value = value;
    lbl_806079C0[5].value = value;
    lbl_806079C0[6].value = value;
    lbl_806079C0[7].value = value;
    lbl_806079C0[8].value = value;
    lbl_802512A4[0].value = value;
    lbl_802512A4[1].value = value;
    lbl_802512A4[2].value = value;

    object = fn_80144628(3, lbl_802512A4, 0);
    lbl_8064D26C = object;
    fn_801446D4(object, fn_801A5D5C);
    fn_801446E4(lbl_8064D26C, value);

    object = fn_80144628(9, lbl_806079C0, 0);
    lbl_8064D264 = object;
    fn_801446D4(object, fn_801A5E68);
    fn_801446DC(lbl_8064D264, fn_801A5FB0);
    fn_801446E4(lbl_8064D264, value);
}
