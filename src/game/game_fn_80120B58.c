typedef unsigned short u16;

typedef struct Object {
    unsigned char pad[0x2BC];
    float value;
    float decrement;
    unsigned char pad2[0xE];
    u16 state;
} Object;

extern const float lbl_806500C4;

void fn_80120B58(Object* object)
{
    if ((object->state & 2) && !(object->state & 0x200)) {
        object->value -= object->decrement;
        if (object->value <= 0.0f) {
            object->value = 0.0f;
            object->state = 0;
        }
    }

    if (object->state & 1) {
        object->value += lbl_806500C4;
        if (object->value == 250.0f) {
            object->value = 250.0f;
        }
    }
}
