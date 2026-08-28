typedef unsigned int u32;
typedef unsigned char u8;

extern void fn_801F1034(void);
extern void fn_801ECF50(int);
extern void fn_801A852C(u32*, int, int, int);
extern void fn_801EDA7C(void*, void*, int, int);
extern void* lbl_8064D790;

void fn_8018D0D0(u8* self, u32* source, int id)
{
    fn_801F1034();
    fn_801ECF50(3);
    if (id == -1) {
        u32 value = *source;
        fn_801A852C(&value, -1, 0, 0);
    } else {
        *(u32*)(self + 0x88) = *(u32*)(self + 0x5C);
        fn_801EDA7C(self + 0x6C, lbl_8064D790, 0x2BF, 0);
    }
}
