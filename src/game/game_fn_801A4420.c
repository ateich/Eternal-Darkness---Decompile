void fn_801A4420(char* object, void* value, int index)
{
    object += index * 4;
    *(void**)(object + 0xA8) = value;
}
