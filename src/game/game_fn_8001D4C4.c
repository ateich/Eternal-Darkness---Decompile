typedef int s32;

char lbl_8023CF7C[28] = "EDCountChararactersInRegion";

extern void fn_8001007C(void);
extern void fn_8016B29C(s32, void (*)(void));
extern void fn_8016B26C(void*, s32);
extern void fn_8016B3A4(void*, s32);
extern char lbl_80237F44[];
extern char lbl_8023CFE8[];

void fn_8001D4C4(void)
{
    fn_8016B29C(0, fn_8001007C);
    fn_8016B26C(lbl_80237F44, 0x138);
    fn_8016B3A4(lbl_8023CFE8, 1);
}
