typedef struct Primary { char pad[0x14]; unsigned int value; } Primary;
typedef struct Object { Primary* primary; } Object;
unsigned int fn_801578A0(Object* object) { return object->primary->value; }
