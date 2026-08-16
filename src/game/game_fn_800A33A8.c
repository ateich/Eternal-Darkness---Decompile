typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Value800A33A8 {
    u8 bytes[0xC];
} Value800A33A8;

extern void* lbl_8064C4E4;
extern void *fn_8011F114();
extern u32 fn_80178E94(void*, Value800A33A8*);
extern void fn_801F74C8(int, int, int);
extern void fn_801441C0(int, int, int);

void fn_800A33A8(void* object)
{
    Value800A33A8 value;
    u32 amount;

    fn_8011F114(&value, lbl_8064C4E4);
    amount = fn_80178E94(object, &value);
    if (amount < 500) {
        fn_801F74C8(35, 0, 7);
        fn_801441C0(3, 0, 40);
    } else if (amount < 1000) {
        fn_801F74C8(35, 0, 6);
        fn_801441C0(2, 1, 40);
    } else if (amount < 2000) {
        fn_801F74C8(25, 0, 6);
        fn_801441C0(1, 1, 40);
    }
}
