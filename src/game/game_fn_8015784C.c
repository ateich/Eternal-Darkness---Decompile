typedef struct Record { char pad[0x32]; short value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
short fn_8015784C(Object* object) { return object->secondary->value; }
