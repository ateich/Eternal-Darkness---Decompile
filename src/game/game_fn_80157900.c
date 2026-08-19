typedef struct Record { char pad[0x24]; short value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
short fn_80157900(Object* object) { return object->secondary->value; }
