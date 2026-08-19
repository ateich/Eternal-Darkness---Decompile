typedef struct Record { char pad[0x1C]; unsigned int value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
void fn_80157930(Object* object, unsigned int value) { object->secondary->value = value; }
