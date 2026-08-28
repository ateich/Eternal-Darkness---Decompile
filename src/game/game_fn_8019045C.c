typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_80606348[];
extern void* lbl_8064D238;
extern void* fn_8018038C(void*, void*);
extern void fn_80190930(void*, void*, void*, void*);
extern void fn_8019B6F0(void*, void*);
extern void fn_8019B73C(void);
extern void fn_8018B928(void);

void* fn_8019045C(void* arg0, void* arg1, void* arg2)
{
    void* object = fn_8018038C(lbl_8064D238, lbl_80606348);
    if (object != 0) {
        fn_80190930(object, arg0, arg1, arg2);
        fn_8019B6F0(object, arg2);
        *(void (**)(void))((u8*)object + 0x14C) = fn_8019B73C;
        *(void (**)(void))((u8*)object + 0x148) = fn_8018B928;
        *(u16*)((u8*)object + 0x22) = 4;
    }
    return object;
}
