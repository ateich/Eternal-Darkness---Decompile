typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern u8 lbl_80302400[];
extern u8 lbl_8023D020[];
extern u8 lbl_8063C638[];
extern u8 lbl_8063B2FC[];
extern u32 lbl_8064DF30;
extern s32 lbl_8064D738;
extern float lbl_8064DEA8;

typedef struct FrontEndState {
    u8 pad00[0x14];
    s32 fade;
    u8 pad18[4];
    void* first_image;
    void* second_image;
    u8 pad24[0xC];
    u32 flags;
    u8 pad34[0xA];
    u8 first_kind;
    u8 second_kind;
} FrontEndState;

extern void fn_80021714(void);
extern void fn_8002188C(u8, void*, u8);
extern void fn_80023230(s32, s32, s32, s32);
extern void* fn_801EB080(void);
extern void fn_801EC7F4(void*, void*);
extern void fn_801ECC4C(void);
extern void fn_801A8D38(int);
extern void fn_801A8FE8(void*, void*, s32, s32, s32);
extern void fn_802262B8(s32);
extern void fn_802266B0(void);
extern void fn_80226EA0(s32, s32, s32, s32);
extern void fn_80226FA4(s32, s32, s32, s32);
extern void fn_802276AC(void*, s32);
extern void fn_80228474(void*, void*, s32, s32, s32, s32, s32, s32);
extern void fn_80228730(void*, s32, s32, s32, s32, s32, float, float, float);
extern void fn_80228AFC(void*, s32);
extern void fn_80228B98(void*, s32);
extern void fn_80229B08(s32, s32, s32, s32, s32);
extern void fn_80229B88(s32, s32, s32, s32, s32);
extern void fn_80229C0C(s32, s32, s32, s32, s32, s32);
extern void fn_80229CCC(s32, s32, s32, s32, s32, s32);
extern void fn_80229D8C(s32, void*);
extern void fn_80229F4C(s32, s32, s32);
extern void fn_80229FA4(s32, s32, s32, s32, s32);
extern void fn_8022A118(s32, s32, s32, s32);
extern void fn_8022A2F4(s32);
extern void fn_8022A5D8(s32, s32, s32, s32);

void fn_80023258(void)
{
    u8* data = lbl_8023D020;
    u8* global = lbl_80302400;
    FrontEndState* fade_state = (FrontEndState*)(global + 0x1C);
    FrontEndState* state;
    void* image;
    volatile u32 color;
    u32 call_color;
    s32 value;

    if (fade_state->fade < 255) {
        value = fade_state->fade + 4;
        fade_state->fade = value;
        fade_state->fade = value < 255 ? value : 255;
    }

    fn_8022A5D8(1, 4, 5, 0);
    state = (FrontEndState*)(global + 0x1C);
    if ((state->flags & 0x20) != 0) {
        if (fade_state->fade != 255) {
            fn_8002188C(state->second_kind, state->second_image, (u8)(255 - fade_state->fade));
        }
        if (fade_state->fade != 0) {
            fn_8002188C(state->first_kind, state->first_image, (u8)fade_state->fade);
        }
    } else if (fade_state->fade != 255) {
        color = lbl_8064DF30;
        image = fn_801EB080();
        fn_8002188C(state->second_kind, state->second_image, 255);
        fn_8022A5D8(1, 4, 5, 0);
        fn_80226EA0(0, 0, 640, 480);
        fn_80226FA4(640, 480, 4, 0);
        fn_802276AC(image, 0);
        fn_802266B0();
        fn_801ECC4C();
        fn_8002188C(state->first_kind, state->first_image, 255);
        fn_801ECC4C();
        fn_80021714();
        fn_80228474(lbl_8063C638 + lbl_8064D738 * 32, image,
                    640, 480, 4, 0, 0, 0);
        fn_80228730(lbl_8063C638 + lbl_8064D738 * 32, 0, 0, 0, 0, 0,
                    lbl_8064DEA8, lbl_8064DEA8, lbl_8064DEA8);
        call_color = color;
        fn_80229D8C(1, &call_color);
        fn_80229FA4(0, 0, 1, 2, 3);
        fn_80229F4C(0, 0, 0);
        fn_80229F4C(1, 0, 0);
        fn_8022A5D8(1, 5, 4, 0);
        fn_80228AFC(lbl_8063C638 + lbl_8064D738 * 32, 0);
        fn_8022A118(0, 0, 0, 255);
        fn_80023230(0, 1, 4, 60);
        fn_80229C0C(0, 0, 0, 0, 1, 0);
        fn_80229B08(0, 15, 15, 15, 8);
        fn_80229CCC(0, 0, 0, 0, 1, 0);
        fn_80229B88(0, 7, 7, 7, 6);
        fn_801EC7F4(data + 0x640, global + 0x98);
        fn_80228B98(global + 0x2C0, 3);
        fn_80228AFC(lbl_8063B2FC, 1);
        fn_8022A118(1, 1, 1, 255);
        fn_80023230(1, 1, 4, 33);
        fn_80229C0C(1, 0, 0, 0, 1, 0);
        fn_80229B08(1, 15, 15, 15, 0);
        fn_80229CCC(1, 0, 0, 0, 1, 0);
        fn_80229B88(1, 7, 1, 4, 7);
        fn_801A8D38(5);
        fn_802262B8(2);
        fn_8022A2F4(2);
        fn_801A8FE8(data + 0x4D8, data + 0x4C0, 0, 0, 5);
        fn_801ECC4C();
    } else {
        *(s32*)(data + 0x66C) = 0;
        *(s32*)(global + 0x98) = 0;
        *(s32*)(data + 0x668) = 255;
        fn_8002188C(state->first_kind, state->first_image, 255);
    }
    fn_8022A5D8(1, 4, 5, 15);
}
