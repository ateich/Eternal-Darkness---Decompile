typedef unsigned short u16;
typedef unsigned int u32;

extern void* lbl_8064D238;
extern char lbl_80606334[];

extern void* fn_8018038C(void*, const char*);
extern void fn_80184A68(void*, void*, void*, void*);
extern void fn_80184C1C(void*, void*);
extern void fn_80184CC4(void);
extern void fn_8018A060(void);

void* fn_801848AC(void* arg1, void* arg2, void* arg3)
{
    void* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_80184A68(result, arg1, arg2, arg3);
        fn_80184C1C(result, (char*)arg3 + 0x14);
        *(void (**)(void))((char*)result + 0x14C) = fn_80184CC4;
        *(void (**)(void))((char*)result + 0x148) = fn_8018A060;
        *(u16*)((char*)result + 0x22) = 4;
    }

    return result;
}
