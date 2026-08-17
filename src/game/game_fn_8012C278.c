typedef unsigned char u8;

extern void fn_8012F6E8(u8*);
extern void fn_8012C2D0(u8*);

void fn_8012C278(u8* owner, int index)
{
    u8* state = ((u8**)*(void**)(owner + 0x240))[index];
    if (state != 0) {
        fn_8012F6E8(state + 0xC);
        fn_8012C2D0(((u8**)*(void**)(owner + 0x240))[index]);
    }
}
