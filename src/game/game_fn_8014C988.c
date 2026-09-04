extern const float lbl_806504D8;
extern const float lbl_806504DC;
extern float lbl_806504E0;
extern float lbl_806504E4;
extern float lbl_806504E8;
extern void fn_8014C8F8(void);
extern void fn_801FE8DC(void*, float, float, float);

void fn_8014C988(void* state, int mode)
{
    switch (mode) {
    case 1:
        *(void (**)(void))((char*)state + 0x48) = fn_8014C8F8;
        fn_801FE8DC((char*)state + 4, lbl_806504D8, lbl_806504D8,
                    lbl_806504DC);
        break;
    case 2:
        fn_801FE8DC((char*)state + 4, lbl_806504E0, lbl_806504E4,
                    lbl_806504E8);
        break;
    }
}
