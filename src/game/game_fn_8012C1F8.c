typedef unsigned char u8;
typedef unsigned short u16;

extern void fn_8012F6E8(u8*);
extern void fn_8012C2D0(u8*);
extern void fn_8012C328(u8*);
extern void fn_8012C370(u8*);
extern void fn_8012C3B8(u8*);

void fn_8012C1F8(u8* state)
{
    u8* cursor;
    int i;

    *(u16*)(state + 0xA) = 0;
    cursor = state;
    for (i = 0; i < 4; i++, cursor += 8)
        fn_8012F6E8(cursor + 0xC);
    fn_8012C2D0(state);
    fn_8012C328(state);
    fn_8012C370(state);
    fn_8012C3B8(state);
}
