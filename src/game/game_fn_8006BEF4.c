typedef unsigned char u8;
typedef unsigned long size_t;

extern void *memcpy(void *dest, const void *src, size_t size);

void fn_8006BEF4(u8 *object, const void *value)
{
    memcpy(object + 8, value, 20);
}
