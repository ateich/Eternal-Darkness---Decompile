typedef struct Object { void* primary; unsigned char* secondary; } Object;
unsigned char fn_801579FC(Object* object) { return object->secondary[0x53]; }
