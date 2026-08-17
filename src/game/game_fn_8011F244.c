typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Record {
    u8 pad[0x18];
    u16 angle;
    u16 tail;
} Record;

extern void fn_8011F140(void* object, int index, void* output);
extern void fn_8011F2B8(void* object, void* output, u16 angle, int enabled);

void fn_8011F244(void* object, int index, void* output, int enabled)
{
    u8* owner = *(u8**)((u8*)object + 0x3C);
    Record* records = *(Record**)(owner + 0xBC);
    u16 angle = records[index].angle;

    fn_8011F140(object, index, output);
    fn_8011F2B8(object, output, angle, enabled);
}
