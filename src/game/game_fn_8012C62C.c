typedef unsigned char u8;
typedef unsigned short u16;

extern int fn_8015C71C(void);
extern void fn_8011FB4C(u8*);
extern void fn_80125ECC(void *);
extern void fn_8012F6E8(void*);
extern void fn_8012CAC4(u8*, int, void*);
extern int lbl_8064F598;

void* fn_8012C62C(u8* state, int index, void* a, void* b, void* c, int flags)
{
    u8* entry;
    u8* definition;

    if (*(int*)(state + 0x244) == 0x30) {
        lbl_8064F598++;
        if (lbl_8064F598 > 2) { }
    }
    fn_8011FB4C(state);
    if (fn_8015C71C() == -1)
        return 0;
    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry) {
        definition = *(u8**)(entry + 4);
        *(unsigned int*)(entry + 0x30) = *(unsigned int*)a;
        *(unsigned int*)(entry + 0x2C) = *(unsigned int*)a;
        *(unsigned int*)(entry + 0x38) = *(unsigned int*)c;
        *(unsigned int*)(entry + 0x34) = *(unsigned int*)b;
        fn_8012F6E8(entry + 0xC);
        if (*(unsigned int*)b != 0)
            *(u16*)(entry + 0xC) = 1;
        if (*(void**)(state + 0x160))
            *(void**)(*(u8**)(state + 0x160) + *(u16*)(definition + 0xE) * 0x4C + 0x48) = entry;
        *(u16*)(entry + 8) = (*(u16*)(entry + 8) & 0xFFE9) | flags;
        fn_8012CAC4(state, index, entry);
    }
    return entry;
}
