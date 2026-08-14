typedef unsigned char u8;

typedef struct Object800A2E00 {
    u8 pad000[0x2A2];
    u8 pad_bit : 1;
    u8 active : 1;
    u8 remaining_bits : 6;
} Object800A2E00;

extern void fn_800A7F1C(void*);
extern void fn_8016B400(void*, void*, int);

void fn_800A2E00(Object800A2E00* object, void* target, void* owner)
{
    object->active = 1;
    fn_800A7F1C(target);
    fn_8016B400(owner, target, 0);
}
