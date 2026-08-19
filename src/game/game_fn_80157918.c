typedef struct Record { char pad[0x52]; unsigned char value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
unsigned char fn_80157918(Object* object) { return object->secondary->value; }
