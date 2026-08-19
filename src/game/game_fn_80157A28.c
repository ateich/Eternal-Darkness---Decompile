typedef struct Object { void* primary; unsigned char* secondary; } Object;
extern unsigned char fn_801578B8(Object*);

void fn_80157A28(Object* object, unsigned short value)
{
    if (fn_801578B8(object) == 1) {
        *(unsigned short*)(object->secondary + 0x44) = value;
    } else {
        object->secondary[0x4A] = value;
    }
}
