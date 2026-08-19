typedef unsigned int u32;

extern int lbl_8064D1BC;
extern int lbl_8064D1C4;
extern unsigned char* lbl_8064D1CC;
extern int lbl_8064D1DC;
extern void* lbl_8064D1E0;
extern char lbl_8024FEE8[];

extern int fn_800F9D4C(char*, const char*, ...);
extern void fn_8016B4B4(void*, u32, char*, void*, int);

void fn_8016B400(int id, void* context, int value)
{
    char name[256];
    unsigned char* base;
    u32 index;
    u32 size;
    unsigned char* data;

    lbl_8064D1C4 = 0;
    base = lbl_8064D1CC;
    if (id > 0 && lbl_8064D1BC == 0) {
        lbl_8064D1E0 = context;
        lbl_8064D1DC = value;
        lbl_8064D1BC = id;
        index = id * 2 + 2;
        size = ((u32*)base)[index + 1];
        data = base + ((u32*)base)[index];
        if (size != 0) {
            fn_800F9D4C(name, lbl_8024FEE8, id);
            fn_8016B4B4(data, size, name, lbl_8064D1E0, lbl_8064D1DC);
        }
        lbl_8064D1BC = 0;
    }
}
