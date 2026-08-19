typedef enum Slot { SLOT_ZERO, SLOT_ONE } Slot;
typedef struct Shared { Slot primary; Slot secondary; unsigned char rest[0x34]; } Shared;

extern volatile Shared lbl_805B6FE0;
extern int fn_800460FC(void);

void fn_8015BDAC(void)
{
    if (fn_800460FC() == 2) {
        lbl_805B6FE0.primary ^= 1;
        lbl_805B6FE0.secondary ^= 1;
    }
}
