typedef signed int s32;
typedef unsigned char u8;
typedef unsigned long size_t;

typedef struct Owner {
    void *field_00;
    u8 field_04[0xC];
    void *field_10;
    u8 field_14;
    u8 field_15;
    u8 field_16;
    u8 pad_17;
    u8 field_18[0x20];
    u8 pad_38[4];
    float field_3C;
    u8 field_40[0x84];
    void *field_C4;
} Owner;

extern void *lbl_8064C8D0;
extern void *lbl_8064C8D4;
extern u8 lbl_80310F0C[];
extern const float lbl_8064E7E0;
extern void *memset(void *dest, s32 value, size_t size);
extern void fn_8006BD78(Owner *owner);

void fn_8006C92C(Owner *owner)
{
    owner->field_00 = lbl_8064C8D0;
    owner->field_10 = lbl_8064C8D4;
    owner->field_C4 = lbl_80310F0C;
    owner->field_14 = 0;
    owner->field_15 = 0;
    owner->field_16 = 0;
    owner->field_3C = lbl_8064E7E0;
    memset(owner->field_18, 0, sizeof(owner->field_18));
    memset(owner->field_04, 0, sizeof(owner->field_04));
    memset(owner->field_40, 0, sizeof(owner->field_40));
    fn_8006BD78(owner);
}
