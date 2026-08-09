typedef signed short s16;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct RuntimeState {
    u8 pad_00[4];
    u32 first_handle;
    u32 second_handle;
    u8 pad_0C[0x10];
    s32 index;
    u8 pad_20[0x1E];
    u8 mode;
} RuntimeState;

extern RuntimeState lbl_8030241C;
extern s32 lbl_8064C654;
extern u32 lbl_8064C2AC;
extern u32 lbl_8064C2B0;
extern u32 lbl_8064DED0;
extern u32 lbl_8064DED4;
extern u8 fn_8001E894[];

#pragma section ".data"
#pragma force_active on
__declspec(section ".data") void* lbl_8023D950 = fn_8001E894 + 0xCD0;
#pragma force_active reset

extern void fn_80144C40(void);
extern u32* fn_801E5D08(u32);
extern u32* fn_801E5D20(u32);
extern s32 fn_800B193C(void);
extern void fn_800B2778(s16);

void fn_8001FB94(s16 delta)
{
    RuntimeState* runtime;
    u32* address;

    fn_80144C40();
    runtime = &lbl_8030241C;

    switch (runtime->mode) {
    case 18:
        lbl_8064C654 = 1;
        if (delta > 0 && lbl_8030241C.index == 0) {
            address = fn_801E5D08(lbl_8030241C.first_handle);
            *address = lbl_8064C2AC;
            address = fn_801E5D08(lbl_8030241C.second_handle);
            *address = lbl_8064C2AC;

            {
                volatile u32 value = lbl_8064DED0;
                address = fn_801E5D08(lbl_8030241C.first_handle);
                *address = value;
            }
            *fn_801E5D20(lbl_8030241C.first_handle) &= 0xFFFFFF1Fu;

            address = fn_801E5D08(lbl_8030241C.second_handle);
            *address = lbl_8064C2B0;
            *fn_801E5D20(lbl_8030241C.second_handle) |= 0x60;
            lbl_8030241C.index = 1;
        } else if (delta < 0 && lbl_8030241C.index == 1) {
            address = fn_801E5D08(lbl_8030241C.first_handle);
            *address = lbl_8064C2AC;
            address = fn_801E5D08(lbl_8030241C.second_handle);
            *address = lbl_8064C2AC;

            {
                volatile u32 value = lbl_8064DED4;
                address = fn_801E5D08(lbl_8030241C.second_handle);
                *address = value;
            }
            *fn_801E5D20(lbl_8030241C.second_handle) &= 0xFFFFFF1Fu;

            address = fn_801E5D08(lbl_8030241C.first_handle);
            *address = lbl_8064C2B0;
            *fn_801E5D20(lbl_8030241C.first_handle) |= 0x60;
            lbl_8030241C.index = 0;
        }
        break;

    case 9:
    case 17:
        if (delta > 0) {
            lbl_8030241C.index += delta;
            if (lbl_8030241C.index % 4 == 0) {
                lbl_8030241C.index -= 4;
            }
        } else if (delta < 0) {
            lbl_8030241C.index += delta;
            if (lbl_8030241C.index % 4 == 3 || lbl_8030241C.index < 0) {
                lbl_8030241C.index += 4;
            }
        }
        break;

    case 4:
    case 5:
    case 6:
    case 8:
    case 30:
        if (fn_800B193C() != 0) {
            fn_800B2778(-delta);
        }
        break;

    case 13:
        if (fn_800B193C() != 0) {
            fn_800B2778(delta);
        }
        break;

    case 14:
        if (fn_800B193C() != 0) {
            fn_800B2778(-delta);
        }
        break;
    }
}
