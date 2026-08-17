extern int lbl_8064D18C;
extern float lbl_8064F804;
extern int fn_80201B54();
extern void *fn_80201BC8();
extern int fn_80201EB8();
extern void fn_80128B10(void *, int);
extern unsigned long long fn_8020123C();
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a,b,c,d,e) fn_8020104C((int)(a),(void*)(b),(void*)(c),(int)(d),(float)(e))

int fn_800E8720(void *unused, void *object)
{
    void *state;
    int handle;

    handle = fn_80201B54(object);
    state = fn_80201BC8(object);

    if (lbl_8064D18C == fn_80201EB8(object) && state != 0) {
        fn_80128B10(state, 60);
        fn_8020123C(17, handle, handle, 0);
        fn_8020104C(57, handle, handle, 0, lbl_8064F804);
    } else {
        fn_8020123C(57, handle, handle, 0);
    }
    return 0;
}
