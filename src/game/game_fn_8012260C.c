typedef signed char s8;

typedef struct Object {
    unsigned char pad[0x2D8];
    s8 value;
    unsigned char timer;
} Object;

extern void fn_801225DC(Object* object, s8 value);

void fn_8012260C(Object* object)
{
    object->timer = 150;
    fn_801225DC(object, -2);
}
