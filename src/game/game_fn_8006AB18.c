typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef union Color {
    u32 word;
    u8 bytes[4];
} Color;

extern void *fn_80201BC8(void);
extern s32 fn_8011F130(void);
extern void fn_801E79A0(void *manager, s32 kind);
extern void fn_801AC9F4(s32 kind, s32 value, s32 position, s32 count);
extern void fn_8012DBE8(void *object, s32 index, u32 *value);
extern void fn_8012C62C(void *object, s32 index, u32 *first, u32 *second,
                       u32 *third, s32 count);

extern void *lbl_8064C4E0;
extern u32 lbl_80651978;
extern u32 lbl_8064E7A0;

void fn_8006AB18(s32 unused)
{
    void *actor;
    s32 position;
    Color sampled;
    u32 first;
    u32 second;
    u32 third;
    Color faded;

    actor = fn_80201BC8();
    position = fn_8011F130();
    fn_801E79A0(lbl_8064C4E0, 0x54);
    fn_801AC9F4(0x62, 0x7F, position, 2);
    fn_801AC9F4(0x12, 0x64, position, 2);
    fn_8012DBE8(actor, 15, &sampled.word);
    faded.word = lbl_80651978;
    faded.bytes[0] = sampled.bytes[0];
    faded.bytes[1] = sampled.bytes[1];
    faded.bytes[2] = sampled.bytes[2];
    third = faded.word;
    second = lbl_8064E7A0;
    first = sampled.word;
    fn_8012C62C(actor, 15, &first, &second, &third, 4);
}
