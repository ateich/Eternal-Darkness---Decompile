typedef unsigned int u32;

typedef struct Owner {
    unsigned char pad_00[0x38];
    void *resource;
    unsigned char pad_3c[0x88];
    unsigned char *state;
} Owner;

extern int fn_8006BCE4(Owner *owner);
extern void *fn_80201814(void *object);
extern void *fn_80036D38(void);
extern void *fn_80201B54(void *object);
extern void fn_8006EE9C(Owner *owner);
extern void fn_801261F4(void *object);
extern void fn_8011F7E0(void *object, int value);
extern int fn_801E79FC(void *object, int value);
extern void fn_8004736C(int value);
extern void fn_801A5C30(int value);
extern void fn_802020B4(void *object, int value);
extern int fn_80200614(void *object, int index, int value);
extern float fn_80200534(void *object, int index, int value);
extern void fn_8020104C(int type, int zero, void *object, int other, float time);
extern void fn_8011E174(int value, int zero);
extern void *lbl_8064C4E4;
extern void *lbl_8064C4E0;
extern const float lbl_8064E7E0;
extern const float lbl_8064E81C;

void fn_8006E3F8(Owner *owner)
{
    int kind;
    u32 owner_value;
    unsigned char *state;
    void *object;
    void *other;
    float time;

    owner_value = (u32)owner;
    kind = fn_8006BCE4((Owner *)owner_value);
    state = ((Owner *)owner_value)->state;
    fn_80201814(((Owner *)owner_value)->resource);
    object = fn_80201814(*(void **)((unsigned char *)fn_80036D38() + 0x44));
    other = fn_80201B54(object);
    fn_8006EE9C((Owner *)owner_value);
    if (kind == 0x17) {
        fn_801261F4(lbl_8064C4E4);
        fn_8011F7E0(lbl_8064C4E4, 0);
    }
    if (!fn_801E79FC(lbl_8064C4E0, 0x373)) {
        fn_8004736C(0);
    }
    fn_801A5C30(1);
    fn_802020B4(object, 1);
    *(u32 *)(state + 0x20) |= 1U << 16;
    if (fn_80200614(((Owner *)owner_value)->resource, -1, 8)) {
        time = fn_80200534(((Owner *)owner_value)->resource, -1, 8);
        fn_8020104C(0xE5, 0, ((Owner *)owner_value)->resource, 0, lbl_8064E7E0 + time);
        *(u32 *)(state + 0x20) |= 2U << 16;
        fn_8020104C(0xBC, 0, other, 0, lbl_8064E81C + time);
    }
    fn_8011E174(0x100, 0);
}
