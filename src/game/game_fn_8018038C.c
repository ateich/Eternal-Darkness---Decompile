typedef unsigned int u32;

extern char lbl_80606334[];
extern u32 lbl_8064D230;
extern u32 lbl_8064D234;

extern void* fn_801801F4(void*);
extern int fn_80180274(void*, void*);
extern void fn_801E7DC8(int);

void* fn_8018038C(void* allocator, void* config)
{
    void* object = fn_801801F4(allocator);

    if (object != 0) {
        if (config == lbl_80606334) {
            lbl_8064D230++;
        }
        if (config != lbl_80606334) {
            lbl_8064D234++;
        }
        *(void**)((char*)object + 0x48) = config;
        if (fn_80180274(object, config) == 0) {
            object = 0;
            fn_801E7DC8(2);
            fn_801E7DC8(0x100);
        }
    }
    return object;
}
