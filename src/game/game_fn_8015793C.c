typedef struct Record { char pad[0x54]; unsigned char value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
unsigned char fn_8015793C(Object* object) { return object->secondary->value; }
