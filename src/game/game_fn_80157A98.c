typedef struct Object { void* primary; unsigned char* secondary; } Object;

void fn_80157A98(Object* object, unsigned short value, int mode)
{
    if (mode == 1) {
        *(unsigned short*)(object->secondary + 0x44) = value;
    } else {
        object->secondary[0x4A] = value;
    }
}
