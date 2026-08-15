typedef unsigned int u32;

extern void* lbl_8064C98C;
extern void* lbl_8064C988;
extern const u32 lbl_80239750[3];
extern const float lbl_8064EF18;

extern void* fn_80201814(void*);
extern void* fn_80201EB8(void*);
extern void* fn_80201B54(void);
extern void fn_800453E8(int, int, void*, int, int, int, int, int, u32*, int,
                       void*, float);

void fn_800A76A0(void)
{
    u32 values[3];
    void* owner = fn_80201814(lbl_8064C98C);
    void* object = fn_80201EB8(owner);

    values[0] = lbl_80239750[0];
    values[1] = lbl_80239750[1];
    values[2] = lbl_80239750[2];
    fn_800453E8(2, 0xBA, object, 0x60, 0, 0, 0x341, 0,
                values, 3, owner, lbl_8064EF18);
    lbl_8064C988 = fn_80201B54();
}
