typedef struct Object { void* primary; unsigned char* secondary; } Object;
void fn_80157B3C(Object* object, unsigned char value) { object->secondary[0x52] = value; }
