typedef unsigned int u32;

typedef struct State801B192C {
    unsigned char pad[0x48];
    u32 value;
} State801B192C;

extern State801B192C* lbl_8064D348;
extern u32 fn_801B1924(void);

u32 fn_801B192C(void)
{
    if (lbl_8064D348 != 0) {
        return fn_801B1924() - lbl_8064D348->value;
    }
    return 0;
}
