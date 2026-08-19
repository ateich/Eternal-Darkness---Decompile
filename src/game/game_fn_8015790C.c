typedef struct Record { char pad[0x2A]; short value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
short fn_8015790C(Object* object) { return object->secondary->value; }
