extern void* memset(void*, int, unsigned int);
extern void fn_801A38D0(void);
extern void fn_801497E0(void);
extern void fn_801499C4(void);

void fn_80149524(unsigned char* object, unsigned char* state)
{
    *(void**)(object + 0x90) = fn_801A38D0;
    *(unsigned int*)(object + 0x94) = 0;
    *(void**)(object + 0x98) = fn_801497E0;
    *(unsigned int*)(object + 0x9C) = 0;
    *(void**)(object + 0xA0) = fn_801499C4;
    *(unsigned int*)(object + 0xA4) = 0;
    object[0xBC] = 1;
    state[0] = 1;
    memset(state + 0x88, 0, 0x40);
}
