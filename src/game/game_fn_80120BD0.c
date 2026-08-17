typedef unsigned short u16;

typedef struct Object {
    unsigned char pad[0x2BC];
    float value;
    unsigned char pad2[0x12];
    u16 state;
} Object;

extern float lbl_806500C8;

int fn_80120BD0(Object* object)
{
    if (object->state & 1) {
        return lbl_806500C8 == object->value;
    }
    return 0;
}
