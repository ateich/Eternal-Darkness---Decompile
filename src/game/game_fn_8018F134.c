extern void* lbl_8064D238;
extern unsigned char lbl_80606348[];

extern void* fn_8018038C(void*, void*);
extern void fn_8018AEB0(void);
extern void fn_8018F1D0(void*, void*, void*, void*);
extern void fn_8018F31C(void*, void*);
extern void fn_8018F378(void);

void* fn_8018F134(void* arg0, void* arg1, void* arg2)
{
    void* object = fn_8018038C(lbl_8064D238, lbl_80606348);

    if (object != 0) {
        fn_8018F1D0(object, arg0, arg1, arg2);
        fn_8018F31C(object, arg2);
        *(void (**)(void))((unsigned char*)object + 0x148) = fn_8018AEB0;
        *(void (**)(void))((unsigned char*)object + 0x14C) = fn_8018F378;
    }
    return object;
}
