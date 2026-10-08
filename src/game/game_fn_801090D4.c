typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern int fn_80108ECC(void*);
extern void fn_80108478(void);
extern int fn_80108470(void);

#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define VU32(p, o) (*(volatile u32*)((u8*)(p) + (o)))

int fn_801090D4(void* state)
{
    int result;
    u32 limit;

    if (state == 0) {
        return 0;
    }

    U32(state, 0x17C) = 1;
    while (S32(state, 0x17C) != 0) {
        if (U8(state, 0x1AC) & 1) {
            result = fn_80108ECC(state);
            if (result == 2) {
                limit = U32(state, 0x1C);
                while (VU32(state, 0x174) < limit) {}
                fn_80108478();
                while (fn_80108470() != 0 && fn_80108470() != 3) {}
                U8(state, 0x1AC) = 4;
            } else if (result == 1) {
                U8(state, 0x1AC) = 4;
            }
            U8(state, 0x1AE) = 0;
        }
    }

    U32(state, 0x17C) = 2;
    return 0;
}
