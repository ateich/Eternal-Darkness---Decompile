float fn_8011F778(void* object, float value)
{
    float old = *(float*)((char*)object + 0x270);
    *(float*)((char*)object + 0x270) = value;
    return old;
}
