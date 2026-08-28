typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern u8 lbl_80606348[];

extern u8* fn_8018038C(void*, void*);
extern void fn_80190794(u8*, void*, void*, void*);
extern void fn_801908EC(u8*, void*);
extern void fn_80190BD0(void);
extern void fn_8018B928(void);

u8* fn_80190320(void* arg0, void* arg1, void* arg2)
{
    u8* result;

    result = fn_8018038C(lbl_8064D238, lbl_80606348);
    if (result != 0) {
        fn_80190794(result, arg0, arg1, arg2);
        fn_801908EC(result, arg2);
        *(void (**)(void))(result + 0x14C) = fn_80190BD0;
        *(void (**)(void))(result + 0x148) = fn_8018B928;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
