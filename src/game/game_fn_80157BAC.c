typedef struct Object { void* primary; unsigned char* secondary; } Object;
void fn_80157BAC(Object* object, unsigned char value) { object->secondary[0x4F] = value; }
