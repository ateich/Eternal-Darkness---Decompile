extern void* fn_8006D488(void*);
extern void fn_801A5C30(int);
extern void fn_802020B4(void*, int);
extern void fn_8011E174(int, int);
extern void* lbl_8064C8C4;

int fn_8009FE98(register void* state)
{
    void* linked;

    linked = fn_8006D488(state);
    lbl_8064C8C4 = 0;
    fn_801A5C30(1);
    fn_802020B4(linked, 1);
    fn_8011E174(0x100, 0);
    return 1;
}
