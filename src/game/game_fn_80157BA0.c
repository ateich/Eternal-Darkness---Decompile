typedef struct Object { void* primary; unsigned char* secondary; } Object;
void fn_80157BA0(Object* object, unsigned short value) { *(unsigned short*)(object->secondary + 0x24) = value; }
