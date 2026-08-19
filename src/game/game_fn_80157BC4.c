typedef struct Object { void* primary; unsigned char* secondary; } Object;
unsigned char fn_80157BC4(Object* object) { return object->secondary[0x4D]; }
