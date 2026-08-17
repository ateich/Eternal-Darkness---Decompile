typedef unsigned char u8;
typedef unsigned int u32;

typedef struct PackedWord {
    u32 value;
} PackedWord;

void fn_8012D66C(u8* state)
{
    PackedWord saved;

    saved = *(PackedWord*)(state + 0x30);
    *(u32*)(state + 0x30) = *(u32*)(state + 0x38);
    *(u32*)(state + 0x2C) = *(u32*)(state + 0x30);
    *(PackedWord*)(state + 0x38) = saved;
    state[0x34] *= -1;
    state[0x35] *= -1;
    state[0x36] *= -1;
    state[0x37] *= -1;
}
