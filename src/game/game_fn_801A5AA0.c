typedef unsigned char u8;

typedef struct Entry {
    u8 pad0[0xC];
    void* value;
    u8 pad10[0x10];
} Entry;

extern Entry lbl_80607AE0[];
extern void* lbl_8064D268;

extern void fn_801A6C58(void*, void*);
extern void* fn_80144628(int, Entry*, int);
extern void fn_80144680(void*);
extern void fn_801446B4(void*);
extern void fn_801446D4(void*, void (*)(void));
extern void fn_801446DC(void*, void (*)(void));
extern void fn_801446E4(void*, void*);
extern void fn_801A665C(void);
extern void fn_801A66C4(void);

void fn_801A5AA0(void* first, void* second)
{
    void* object;

    fn_801A6C58(first, second);
    lbl_80607AE0[0].value = second;
    lbl_80607AE0[1].value = second;
    lbl_80607AE0[2].value = second;
    lbl_80607AE0[3].value = second;
    lbl_80607AE0[4].value = second;
    lbl_80607AE0[5].value = second;
    lbl_80607AE0[6].value = second;
    lbl_80607AE0[0].value = first;
    lbl_80607AE0[1].value = first;
    lbl_80607AE0[2].value = first;
    lbl_80607AE0[3].value = first;
    lbl_80607AE0[4].value = first;

    object = lbl_8064D268;
    if (object != 0) {
        fn_80144680(object);
        lbl_8064D268 = 0;
    }

    object = fn_80144628(7, lbl_80607AE0, 0);
    lbl_8064D268 = object;
    fn_801446E4(object, second);
    fn_801446D4(lbl_8064D268, fn_801A665C);
    fn_801446DC(lbl_8064D268, fn_801A66C4);
    fn_801446B4(lbl_8064D268);
}
