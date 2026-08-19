typedef struct Object { void* primary; unsigned char* secondary; } Object;
void fn_80157B48(Object* object, unsigned short value) { *(unsigned short*)(object->secondary + 0x26) = value; }
