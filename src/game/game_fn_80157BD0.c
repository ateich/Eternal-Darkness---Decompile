typedef struct Object { void* primary; unsigned char* secondary; } Object;
unsigned char fn_80157BD0(Object* object) { return object->secondary[0x4E]; }
