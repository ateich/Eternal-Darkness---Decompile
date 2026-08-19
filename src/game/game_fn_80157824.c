typedef struct Vec4 { unsigned int v[4]; } Vec4;
typedef struct Record { char pad[0xC]; Vec4 value; } Record;
typedef struct Object { void* primary; Record* secondary; } Object;

void fn_80157824(Vec4* out, Object* object)
{
    *out = object->secondary->value;
}
