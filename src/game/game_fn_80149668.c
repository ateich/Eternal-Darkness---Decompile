extern void* memset(void*, int, unsigned int);
extern void fn_801925F0(void);
extern void fn_80149748(void);
extern void fn_80149B60(void);

void fn_80149668(unsigned char* object, unsigned char* state)
{
    *(void**)(object + 0x90) = fn_801925F0;
    *(unsigned int*)(object + 0x94) = 0;
    *(void**)(object + 0x98) = fn_80149748;
    *(unsigned int*)(object + 0x9C) = 0;
    *(void**)(object + 0xA0) = fn_80149B60;
    *(unsigned int*)(object + 0xA4) = 0;
    object[0xBC] = 1;
    state[0] = 10;
    memset(state + 0x88, 0, 0x40);
}
