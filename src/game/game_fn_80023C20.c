typedef unsigned char u8;
typedef unsigned int u32;

extern void* lbl_8064C658;
extern u32 lbl_806518F0;
extern u8 lbl_8023D77C[];
extern u8 lbl_8030241C[];
extern void* lbl_8064D68C;
extern u32 lbl_8064C51C;
extern u8 lbl_8023D884[];

extern u32 fn_8015AA0C(void);
extern void fn_80144680(void* object);
extern void* fn_80144628(u32 kind, void* data, u32 flags);
extern void fn_801EBA58(void* object);
extern void fn_801F348C(u32* value, u32 duration);
extern unsigned int fn_801A98F4(int, int);
extern u32 fn_80024638(void* data, u32 value, void* output);
extern void fn_801E85A8(void);
extern void fn_80020150(void);

void fn_80023C20(void)
{
    u32 output;
    volatile u32 initial_time;
    u32 timed_value;
    u32 value = fn_8015AA0C();

    initial_time = lbl_806518F0;
    if (lbl_8064C658 != 0) {
        fn_80144680(lbl_8064C658);
    }
    lbl_8064C658 = fn_80144628(7, lbl_8023D77C, 0);
    *(u32*)(lbl_8030241C + 0x34) = -1;
    fn_801EBA58(lbl_8064D68C);
    timed_value = initial_time;
    fn_801F348C(&timed_value, 20);
    if (lbl_8030241C[0x3E] == 7) {
        *(u32*)(lbl_8030241C + 0x38) = fn_801A98F4(0x275, 100);
    }
    lbl_8064C51C = fn_80024638(lbl_8023D884, value, &output);
    fn_801E85A8();
    fn_80020150();
}
