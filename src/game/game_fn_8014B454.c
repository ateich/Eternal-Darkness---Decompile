extern void* fn_8017FDA8(void*, unsigned char);
extern void* memcpy(void*, const void*, unsigned long);
void fn_8014B454(void* object, void* destination, unsigned char value, int unused1, int unused2)
{
    memcpy(destination, fn_8017FDA8(object, value), 6);
}
