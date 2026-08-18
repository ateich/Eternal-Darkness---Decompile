extern void* memset(void*, int, unsigned int);
extern void fn_8019BD44(void);
extern void fn_8014E52C(void);
extern void fn_80148B98(void);

void fn_8014E4C0(unsigned char* object, unsigned char* state)
{
    *(void**)(object + 0x90) = fn_8019BD44;
    *(unsigned int*)(object + 0x94) = 0;
    *(void**)(object + 0x98) = fn_8014E52C;
    *(unsigned int*)(object + 0x9C) = 0;
    *(void**)(object + 0xA0) = fn_80148B98;
    *(unsigned int*)(object + 0xA4) = 0;
    object[0xBC] = 1;
    state[0] = 1;
    memset(state + 0x88, 0, 0x40);
}
