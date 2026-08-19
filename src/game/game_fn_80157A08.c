typedef struct Object { void* primary; unsigned char* secondary; } Object;

unsigned short fn_80157A08(Object* object, int mode)
{
    if (mode == 1) {
        return *(unsigned short*)(object->secondary + 0x44);
    }
    return object->secondary[0x4A];
}
