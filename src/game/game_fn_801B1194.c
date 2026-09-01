typedef unsigned int u32;

extern char* lbl_8064D348;
extern void fn_801B110C(void);
extern void fn_80213930(void*, int, u32, void (*)(void));

void fn_801B1194(void)
{
    char* entry = lbl_8064D348;
    fn_80213930(entry + 0x18, 0, *(u32*)(entry + 0x10), fn_801B110C);
}
