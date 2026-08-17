typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct PackedVector {
    u32 word;
    u16 half;
} PackedVector;

extern void fn_8012DA44(void*, void*, void*, int);

void fn_8012D7AC(u8* state)
{
    PackedVector delta;

    delta.word = *(u32*)(state + 0x66);
    delta.half = *(u16*)(state + 0x6A);
    fn_8012DA44(state + 0x54, state + 0x60, &delta, 6);
}
