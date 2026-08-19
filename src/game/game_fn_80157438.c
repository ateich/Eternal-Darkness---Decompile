typedef struct Object {
    struct Object* previous;
    struct Object* next;
    void* value;
} Object;

extern Object* fn_80155EF4(void);
extern Object* fn_80155F8C(void);
extern Object* fn_801560CC(void*);
extern void fn_8015677C(Object*, unsigned int, int);

void fn_80157438(unsigned int flags, void* value)
{
    int skip_update;
    int bounded;
    int count;
    Object* object;

    count = 0;

    if ((flags & 1) != 0) {
        object = fn_80155EF4();
        skip_update = flags & 0x80;
        bounded = flags & 0x100;

        while (object != 0) {
            if (skip_update == 0) {
                fn_8015677C(object, flags, 1);
            }
            count++;
            if (bounded != 0 && count > 452) {
                return;
            }
            object = object->previous;
        }
    }

    if ((flags & 8) != 0) {
        object = fn_80155F8C();
        while (object != 0) {
            object = object->next;
        }
    }

    if ((flags & 0x10) != 0) {
        object = fn_801560CC(value);
        if (object != 0) {
            object = object->value;
            while (object != 0) {
                object = object->value;
            }
        }
    }
}
