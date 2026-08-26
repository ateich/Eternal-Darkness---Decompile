typedef signed short s16;

extern void* lbl_8064D238;
extern char lbl_80606334[];

extern void* fn_8018038C(void*, void*);
extern void fn_8017EE58(void*, void*, void*, void*);
extern void fn_8017F084(void*, void*);
extern void fn_8017F120(void);
extern void fn_8018A88C(void);

void* fn_8017EDB4(void* first, void* second, void* config)
{
    void* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606334);
    if (result != 0) {
        fn_8017EE58(result, first, second, config);
        fn_8017F084(result, config);
        *(void (**)(void))((char*)result + 0x14C) = fn_8017F120;
        *(void (**)(void))((char*)result + 0x148) = fn_8018A88C;
        *(s16*)((char*)result + 0x22) = 4;
    }
    return result;
}
