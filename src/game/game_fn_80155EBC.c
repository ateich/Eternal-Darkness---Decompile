extern void* lbl_8064D0F8;
extern int lbl_8064D0D4;
extern void fn_8017CE74(void*, void*);

void fn_80155EBC(void* value)
{
    if (value != 0) {
        fn_8017CE74(lbl_8064D0F8, value);
        lbl_8064D0D4--;
    }
}
