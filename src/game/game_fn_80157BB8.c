typedef struct Object { void* primary; unsigned char* secondary; } Object;
void fn_80157BB8(Object* object, unsigned char value) { object->secondary[0x4E] = value; }
