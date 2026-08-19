extern char lbl_805FAAB0[];
extern char lbl_8024FEF4[];
extern char lbl_8064BC08;
extern void* lbl_8064D1C0;
extern int lbl_8064D1BC;
extern int lbl_8064D1C4;
extern int lbl_8064D1DC;
extern void* lbl_8064D1E0;

extern char* fn_800FD40C(char*, const char*);
extern void fn_8016A970(void*, void*, int);
extern void fn_8016AA34(void*, const char*);
extern void fn_8016AB20(void*, const char*);
extern void fn_8016A5B0(void*, int);
extern void fn_8016AC68(void*, int);
extern void* fn_80160EBC(void*, void*, void*, void*);
extern void fn_8016B400(int, void*, int);
extern void fn_8016B914(int);

#pragma use_lmw_stmw on

void* fn_8016B4B4(void* data, void* size, char* name, void* context, int value)
{
    void* result;

    fn_800FD40C(lbl_805FAAB0, name);
    fn_8016B914(-1);
    fn_8016A970(lbl_8064D1C0, context, 0);
    fn_8016AB20(lbl_8064D1C0, lbl_8024FEF4);
    fn_8016A970(lbl_8064D1C0, (void*)value, 0);
    fn_8016AB20(lbl_8064D1C0, &lbl_8064BC08);
    result = fn_80160EBC(lbl_8064D1C0, data, size, name);
    fn_8016AA34(lbl_8064D1C0, lbl_8024FEF4);
    fn_8016A5B0(lbl_8064D1C0, -2);
    fn_8016AA34(lbl_8064D1C0, &lbl_8064BC08);
    fn_8016A5B0(lbl_8064D1C0, -2);
    fn_8016AC68(lbl_8064D1C0, 0);
    lbl_8064D1BC = 0;
    fn_8016B914(-2);
    if (lbl_8064D1C4 != 0) {
        fn_8016B400(lbl_8064D1C4, lbl_8064D1E0, lbl_8064D1DC);
    }
    return result;
}
