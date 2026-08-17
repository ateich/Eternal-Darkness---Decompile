typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct PackedVector {
    u32 word;
    u16 half;
} PackedVector;

extern void fn_8012DA44(void*, void*, void*, int);

void fn_8012D6C4(u8* state)
{
    PackedVector delta;

    delta.word = *(u32*)(state + 0x4E);
    delta.half = *(u16*)(state + 0x52);
    fn_8012DA44(state + 0x3C, state + 0x48, &delta, 8);
}
