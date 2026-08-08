typedef int s32;

extern s32 lbl_8064CBB0;
extern void* fn_80156938(void*);
extern void fn_800CF2DC(void*);

void fn_8002B650(void* callback)
{
    void* object = fn_80156938(callback);
    if (object != 0 && lbl_8064CBB0 != 0) {
        fn_800CF2DC(object);
    }
}
