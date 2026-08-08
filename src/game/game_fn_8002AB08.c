typedef int s32;
typedef unsigned char u8;

extern void* fn_80156938(void*);
extern s32 fn_80131458(void);
extern void* fn_8015C910(void);
extern u8 fn_80202160(void*);
extern void fn_802015D4(void*);

s32 fn_8002AB08(void* callback, void* unused, s32 run)
{
    void* source = fn_80156938(callback);

    if (run != 0) {
        return 0;
    }
    if (source != 0 && fn_80131458() == 0) {
        if (fn_8015C910() == 0 || fn_80202160(source) == 0) {
            fn_802015D4(source);
        }
    }
    return 0;
}
