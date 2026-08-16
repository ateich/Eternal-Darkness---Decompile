extern int fn_800E4750(void);
extern unsigned char lbl_8064CADD;
extern unsigned char lbl_8064D5F8;

typedef struct StateOwner {
    unsigned char pad[32];
    unsigned int flags;
} StateOwner;

void fn_800E4AC4(StateOwner *owner)
{
    if (fn_800E4750())
        lbl_8064D5F8 = (owner->flags & 0x100) ? 2 : 0;
    else
        lbl_8064D5F8 = lbl_8064CADD;
}
