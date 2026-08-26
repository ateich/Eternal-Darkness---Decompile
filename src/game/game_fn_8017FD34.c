extern void* lbl_8064D238;
extern void fn_801806E8(void*, void*, void*);

void fn_8017FD34(void* object)
{
    if (object != 0 && *(void**)((char*)object + 0x48) != 0) {
        fn_801806E8(object, lbl_8064D238,
                    *(void**)((char*)object + 0x48));
    }
}
