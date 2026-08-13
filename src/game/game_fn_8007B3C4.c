typedef struct Object {
    unsigned char pad0[0x2C];
    unsigned char active;
} Object;

extern void fn_8004910C(void *value);
extern void *fn_80201C24(void);
extern unsigned short fn_80158234(void);
extern void fn_8007BA3C(Object *object, void *arg);
extern void fn_8007B828(Object *object);
extern void fn_8007B540(void *position, Object *object);
extern void fn_8007B640(Object *object, int flags);

void fn_8007B3C4(Object *object, void *arg, void *value, int flags)
{
    unsigned short type;

    fn_8004910C(value);
    fn_80201C24();
    type = fn_80158234();

    switch (type) {
    case 1:
        if (flags == 0) {
            fn_8007BA3C(object, arg);
        }
        break;
    case 2:
    case 8:
    case 16:
    case 32:
    case 64:
    case 128:
    case 2048:
        if (object->active != 0 && flags == 0) {
            fn_8007B828(object);
        }
        break;
    case 4:
    case 512:
        if (object->active != 0 && flags == 0) {
            fn_8007B540((char *)object + 0xC, object);
        }
        break;
    case 1024:
        if (object->active != 0) {
            fn_8007B640(object, flags);
        }
        break;
    case 256:
        if (object->active != 0 && flags == 0) {
            fn_8007B828(object);
        }
        break;
    }
}
