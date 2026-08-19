typedef struct Primary { char pad[0x10]; unsigned int value; } Primary;
typedef struct Object { Primary* primary; } Object;
unsigned int fn_80157888(Object* object) { return object->primary->value; }
