typedef struct Object {
    unsigned char pad_000[0x86];
    unsigned short state;
    unsigned char pad_088[0x1fc];
    unsigned short timer;
} Object;

extern void fn_800A2384(Object *);
extern int fn_80201B44();

void fn_800D86E8(Object *object, int value)
{
    fn_800A2384(object);
    switch (object->state) {
    case 2:
        if (value == fn_80201B44()) {
            object->timer = 210;
        }
        break;
    }
}
