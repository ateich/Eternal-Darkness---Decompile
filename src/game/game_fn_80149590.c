extern void* memset(void*, int, unsigned int);
extern void fn_80190E60(void);
extern void fn_80149748(void);
extern void fn_80149B60(void);

void fn_80149590(unsigned char* object, unsigned char* state)
{
    *(void**)(object + 0x90) = fn_80190E60;
    *(unsigned int*)(object + 0x94) = 0;
    *(void**)(object + 0x98) = fn_80149748;
    *(unsigned int*)(object + 0x9C) = 0;
    *(void**)(object + 0xA0) = fn_80149B60;
    *(unsigned int*)(object + 0xA4) = 0;
    object[0xBC] = 1;
    state[0] = 1;
    memset(state + 0x88, 0, 0x40);
}
