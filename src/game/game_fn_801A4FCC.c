typedef unsigned char u8;

extern void* lbl_8064D238;
extern u8 lbl_80606348[];
extern void* fn_8018038C(void*, void*);
extern void fn_801A5068(void*, void*, void*, void*);
extern void fn_801A5224(void*, void*);
extern void fn_801A5290(void);
extern void fn_801A5684(void);

void* fn_801A4FCC(void* first, void* second, void* descriptor)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606348);

    if (result != 0) {
        fn_801A5068(result, first, second, descriptor);
        fn_801A5224(result, descriptor);
        *(void (**)(void))(result + 0x14c) = fn_801A5290;
        *(void (**)(void))(result + 0x148) = fn_801A5684;
    }
    return result;
}
