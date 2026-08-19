typedef struct Record { unsigned int value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;
unsigned int fn_801578AC(Object* object) { return object->secondary->value; }
