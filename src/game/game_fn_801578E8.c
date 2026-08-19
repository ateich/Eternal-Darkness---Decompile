typedef struct Record { char pad[0x26]; short value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
short fn_801578E8(Object* object) { return object->secondary->value; }
