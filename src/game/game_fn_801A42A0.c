typedef unsigned char u8;
typedef unsigned short u16;

extern void* lbl_8064D238;
extern u8 lbl_80606334[];
extern void* fn_8018038C(void*, void*);
extern void fn_801A4430(void*, void*, void*, void*);
extern void fn_801A4880(void*, void*);
extern void fn_801A48EC(void);
extern void fn_801A4AA0(void);
extern void fn_801A4CE0(void);
extern void fn_8018A88C(void);

void* fn_801A42A0(void* coordinate, void* descriptor, u8* owner)
{
    u8* result = fn_8018038C(lbl_8064D238, lbl_80606334);

    if (result != 0) {
        fn_801A4430(result, coordinate, descriptor, owner);
        fn_801A4880(result, owner);
        switch (owner[0x20]) {
        case 1:
            *(void (**)(void))(result + 0x14C) = fn_801A48EC;
            break;
        case 2:
            *(void (**)(void))(result + 0x14C) = fn_801A4AA0;
            break;
        case 3:
            *(void (**)(void))(result + 0x14C) = fn_801A4CE0;
            break;
        }
        *(void (**)(void))(result + 0x148) = fn_8018A88C;
        *(u16*)(result + 0x22) = 4;
    }
    return result;
}
