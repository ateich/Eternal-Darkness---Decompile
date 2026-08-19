typedef struct Object { void* primary; unsigned char* secondary; } Object;
extern unsigned char fn_801578B8(Object*);

unsigned short fn_80157948(Object* object)
{
    if (fn_801578B8(object) == 1) {
        return *(unsigned short*)(object->secondary + 0x46);
    }
    return *(unsigned short*)(object->secondary + 0x48);
}
