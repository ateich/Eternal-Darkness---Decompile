typedef unsigned short u16;

extern void *lbl_803251E4[3];
extern int lbl_8064CA88;
extern int lbl_8064B714;
extern float lbl_8064F140;

extern void *fn_80201BC8();
extern int fn_80201B54();
extern u16 fn_801291CC(void *);
extern unsigned long long fn_8020123C();
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a,b,c,d,e) fn_8020104C((int)(a),(void*)(b),(void*)(c),(int)(d),(float)(e))

void fn_800C4B6C(void *context)
{
    void *object = fn_80201BC8(context);
    void *value = ((void *)fn_80201B54(context));

    if (lbl_8064B714 >= 0) {
        if (fn_801291CC(object) <= 5) {
            fn_8020123C(0x28, value, value, lbl_803251E4[lbl_8064B714]);
            lbl_8064B714++;
            if (lbl_8064B714 >= lbl_8064CA88) {
                lbl_8064B714 = -1;
                lbl_8064CA88 = 0;
            }
        } else {
            fn_8020104C(0x46, value, value, lbl_803251E4[lbl_8064B714],
                        lbl_8064F140);
        }
    }
}
