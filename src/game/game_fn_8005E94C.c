typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct HandlerState {
    u8 pad[0x94];
    u8 value;
} HandlerState;

extern u32 fn_801291CC(void *object);
extern s32 fn_80128F40(void *object);
extern s32 fn_80128EAC(void *object);
extern s32 fn_8012A1BC(void *object, s32 value);
extern void fn_8012B344(void *object);

void fn_8005E94C(void *object, HandlerState *state)
{
    if ((u16)fn_801291CC(object) == 5) {
        s32 packed = fn_80128F40(object);
        s32 value = fn_8012A1BC(object, fn_80128EAC(object)) - (packed >> 17);

        if (value > 0) {
            state->value = (u8)((value < 12 ? value : 12) << 1);
        }
        fn_8012B344(object);
    }
}
