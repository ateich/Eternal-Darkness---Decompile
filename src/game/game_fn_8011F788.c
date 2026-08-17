float fn_8011F788(void* object, float value)
{
    float old = *(float*)((char*)object + 0x274);
    *(float*)((char*)object + 0x274) = value;
    return old;
}
