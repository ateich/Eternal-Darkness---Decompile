typedef struct ArenaSizes {
    int first;
    int second;
} ArenaSizes;

typedef struct ArenaState {
    int base;
    int end;
} ArenaState;

extern ArenaState lbl_8064D858;

extern void fn_801388F8(int);
extern int fn_80135748(ArenaSizes*);
extern void fn_8015E168(void*, int);

void fn_80138894(void)
{
    ArenaSizes sizes;
    fn_801388F8(1);
    lbl_8064D858.base = (fn_80135748(&sizes) + 31) & ~31;
    lbl_8064D858.end = lbl_8064D858.base + 0x86480;
    fn_8015E168((void*)(lbl_8064D858.base + sizes.first),
                lbl_8064D858.end + 0x86480);
}
