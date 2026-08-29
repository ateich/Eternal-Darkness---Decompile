typedef unsigned char u8;
typedef struct Triple { unsigned long x, y, z; } Triple;
void fn_80199138(u8* object, Triple* value) { *(Triple*)(object + 0xbc) = *value; }
