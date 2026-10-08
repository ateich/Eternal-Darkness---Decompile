typedef unsigned int u32;

typedef struct Table Table;

extern char lbl_8023E9C4[];
extern char lbl_8023E9D0[];
extern Table* lbl_8064C520;
extern int lbl_8064C7E0;

extern void* fn_801FEA8C(u32, int, const char*, int);
extern int fn_8015D458(void*, int*, void*);
extern void fn_801E85A8(Table*);
extern void* fn_801E86A0(Table*, u32);
extern u32 fn_801E88E4(Table*);
extern void* fn_80125788(void*);

void fn_80042B54(void)
{
    u32 i;
    void* entry;
    u32 j;

    lbl_8064C520 = fn_801FEA8C(0x2A06FC, 1, lbl_8023E9C4, 0x1D6);
    fn_8015D458(lbl_8023E9D0, (int*)lbl_8064C520, (void*)0x2A06FC);
    fn_801E85A8(lbl_8064C520);
    lbl_8064C7E0 = 0;

    for (i = 0; i < fn_801E88E4(lbl_8064C520); i++) {
        entry = fn_801E86A0(lbl_8064C520, i);
        if (entry != 0) {
            for (j = 0; j < i; j++) {
                if (fn_801E86A0(lbl_8064C520, j) == entry) {
                    break;
                }
            }
            if (j == i) {
                fn_80125788(entry);
            }
        }
    }
}
