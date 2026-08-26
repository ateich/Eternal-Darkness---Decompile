typedef signed short s16;
typedef unsigned char u8;

extern void fn_80182014(void*, void*, void*);

void fn_80181FD8(void* object, u8* coord, u8* effect)
{
    effect[0x14] = 4;
    *(s16*)(coord + 2) = 0;
    *(s16*)(coord + 0) = 0;
    *(s16*)(coord + 4) = 8;
    fn_80182014(object, coord, effect);
}
