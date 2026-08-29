typedef unsigned char u8;

extern void* lbl_8064D238;
extern char lbl_80606334[];
extern void* fn_8018038C(void*, const char*);
extern void fn_80180384(void*, int);
extern void fn_801A1C78(void*, void*, void*, void*);
extern void fn_801A1E14(void*, void*);
extern void fn_801A1F8C(void);
extern void fn_801A2D64(void);

void* fn_801A1BD0(void* arg0, void* arg1, void* arg2)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_801A1C78(result, arg0, arg1, arg2);
        fn_80180384(result, 100);
        fn_801A1E14(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_801A1F8C;
        *(void (**)(void))(result + 0x148) = fn_801A2D64;
    }
    return result;
}
