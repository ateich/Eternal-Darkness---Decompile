typedef struct Record { char pad[0x34]; short value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
short fn_80157858(Object* object) { return object->secondary->value; }
