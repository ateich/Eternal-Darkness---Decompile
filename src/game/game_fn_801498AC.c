extern void* memset(void*, int, unsigned int);
extern void fn_8018782C(void);
extern void fn_80187968(void);
extern void fn_80149920(void);
extern void fn_80149B60(void);

void fn_801498AC(unsigned char* object, unsigned char* state)
{
    *(void**)(object + 0x90) = fn_8018782C;
    *(void**)(object + 0x94) = fn_80187968;
    *(void**)(object + 0x98) = fn_80149920;
    *(unsigned int*)(object + 0x9C) = 0;
    *(void**)(object + 0xA0) = fn_80149B60;
    *(unsigned int*)(object + 0xA4) = 0;
    object[0xBC] = 1;
    state[0] = 1;
    memset(state + 0x88, 0, 0x40);
}
