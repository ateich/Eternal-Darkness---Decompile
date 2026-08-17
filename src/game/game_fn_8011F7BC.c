typedef struct Vec3 { float x, y, z; } Vec3;

void fn_8011F7BC(void* object, const Vec3* value)
{
    *(Vec3*)((char*)object + 0x0C) = *value;
}
