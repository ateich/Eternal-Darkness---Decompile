typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern void* lbl_80606334[];
extern void* fn_8018038C(void*, void*);
extern int fn_80180A9C(void*);

void fn_80180A38(void* unused1, void* unused2, u8* source)
{
    u8* object = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (object != 0) {
        *(u16*)(object + 0x0C) = *(u16*)(source + 6);
        *(void**)(object + 0x14C) = fn_80180A9C;
        *(void**)(object + 0x148) = 0;
        *(u16*)(object + 0x22) = 4;
    }
}
