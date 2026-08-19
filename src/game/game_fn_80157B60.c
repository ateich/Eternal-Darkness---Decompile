typedef struct Object { void* primary; unsigned char* secondary; } Object;
void fn_80157B60(Object* object, unsigned char value) { object->secondary[0x51] = value; }
