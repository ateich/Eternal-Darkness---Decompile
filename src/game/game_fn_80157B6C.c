typedef struct Object { void* primary; unsigned int* secondary; } Object;
void fn_80157B6C(Object* object, unsigned int mask) { object->secondary[1] &= ~mask; }
