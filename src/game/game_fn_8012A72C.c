typedef unsigned char u8;

#define FN_80128E30_RETURN u8*
#define FN_80128E30_PARAMETERS void*
extern FN_80128E30_RETURN fn_80128E30(FN_80128E30_PARAMETERS);
extern unsigned int fn_8011FAEC(void*);
extern void* fn_8012A13C(void*, int);
extern void fn_80129DE0(void*, void*, int, int);
extern void fn_80134FF8(void*, int);
extern void fn_80124DBC(void*);

void fn_8012A72C(void* owner)
{
    u8* state;

    state = fn_80128E30(owner);
    if (*(void**)(state + 0xB8) != 0) {
        if ((fn_8011FAEC(owner) & 0x400) == 0) {
            if ((*(unsigned int*)((u8*)owner + 0x254) & 0x1000) != 0) {
                *(void**)(state + 0xB8) =
                    fn_8012A13C(owner, *(int*)(state + 0xF0));
            }
            fn_80129DE0(owner, state, 0, 0);
        }
        fn_80134FF8(owner, *(int*)(*(u8**)(state + 0xB8) + 4));
    }
    fn_80124DBC(owner);
}
