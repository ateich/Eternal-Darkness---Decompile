typedef struct Record { char pad[4]; unsigned int value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
unsigned int fn_80157894(Object* object) { return object->secondary->value; }
