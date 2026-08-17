typedef unsigned char u8;
typedef unsigned short u16;

extern const float lbl_806501D8;
extern void fn_8017A630(float*);
extern void fn_8012BE78(const float*, void*);

void fn_8012C3B8(u8* state)
{
    float vector[3];

    *(u16*)(state + 0xA) &= ~9;
    fn_8017A630(vector);
    fn_8012BE78(vector, state + 0x6C);
    *(unsigned int*)(state + 0x74) = *(unsigned int*)(state + 0x6C);
    *(unsigned int*)(state + 0x78) = *(unsigned int*)(state + 0x70);
    *(unsigned int*)(state + 0x7C) = *(unsigned int*)(state + 0x6C);
    *(unsigned int*)(state + 0x80) = *(unsigned int*)(state + 0x70);
    *(float*)(state + 0x84) = lbl_806501D8;
    *(float*)(state + 0x88) = lbl_806501D8;
    *(unsigned int*)(state + 0x8C) = 0;
}
