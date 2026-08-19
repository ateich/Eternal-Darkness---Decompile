typedef struct Record { char pad[0x1C]; unsigned int value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
unsigned int fn_80157924(Object* object) { return object->secondary->value; }
