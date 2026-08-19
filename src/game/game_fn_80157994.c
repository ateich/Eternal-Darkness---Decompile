typedef struct Object { void* primary; unsigned char* secondary; } Object;
extern unsigned char fn_801578B8(Object*);

unsigned short fn_80157994(Object* object)
{
    if (fn_801578B8(object) == 1) {
        return *(unsigned short*)(object->secondary + 0x44);
    }
    return object->secondary[0x4A];
}
