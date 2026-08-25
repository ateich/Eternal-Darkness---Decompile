typedef unsigned short u16;

extern void* fn_801FD6F4(void*);
extern int fn_801FE05C(void*);
extern int lbl_8064D1E8;

int fn_801754D0(void* state)
{
    void* object;

    object = fn_801FD6F4(state);
    if (object != 0 && lbl_8064D1E8 == 0 && fn_801FE05C(state) != 0) {
        *(u16*)((char*)object + 0x22) = 2;
    }
    return 0;
}
