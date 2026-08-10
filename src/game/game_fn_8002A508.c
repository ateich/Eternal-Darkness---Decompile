typedef int s32;
typedef unsigned char u8;

extern char lbl_8030F540[];
extern void* fn_80156938(void*);
extern void* fn_80201BC8();
extern void* fn_8015C910(void);
extern u8 fn_80202160(void*);
extern void fn_8012A72C(void*);
extern void fn_8012A254(void*);

s32 fn_8002A508(void* callback)
{
    void* source = fn_80156938(callback);
    void* object = fn_80201BC8();

    if (object != 0 && *(s32*)(lbl_8030F540 + 0x1C8) == -2) {
        if (fn_8015C910() != 0 && fn_80202160(source) != 0) {
            fn_8012A72C(object);
        } else {
            fn_8012A254(object);
        }
    }
    return 2;
}
