extern float fn_80140E58(void);

float fn_8011F700(void* object)
{
    char* bytes = object;
    if (*(char**)(bytes + 0x3C) != 0) {
        float value = fn_80140E58();
        char* owner = *(char**)(bytes + 0x3C);
        if (*(float*)(owner + 0xF8) > value) {
            return *(float*)(owner + 0xF8);
        }
        return fn_80140E58();
    }
    return *(float*)(bytes + 0x274);
}
