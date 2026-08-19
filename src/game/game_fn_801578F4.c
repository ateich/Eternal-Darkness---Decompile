typedef struct Record { char pad[0x28]; short value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
short fn_801578F4(Object* object) { return object->secondary->value; }
