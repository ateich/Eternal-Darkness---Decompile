typedef unsigned char u8;

extern u8 lbl_80606334[];
extern void* lbl_8064D238;

extern void* fn_8018038C(void*, void*);
extern void fn_80185CA4(void*, void*, void*, void*);
extern void fn_80185E0C(void*, void*);
extern void fn_8018666C(void);
extern void fn_80186A88(void);

void* fn_80185A44(void* first, void* second, u8* data)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_80185CA4(result, first, second, data);
        fn_80185E0C(result, data + 0x14);
        *(void (**)(void))(result + 0x14C) = fn_80186A88;
        *(void (**)(void))(result + 0x148) = fn_8018666C;
        *(unsigned short*)(result + 0x22) = 4;
    }
    return result;
}
