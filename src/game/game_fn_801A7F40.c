typedef unsigned short u16;

typedef struct Buffer801A7F40 {
    unsigned char pad[0x10];
    u16 count;
    unsigned char pad12[2];
    void* data;
} Buffer801A7F40;

extern void* memcpy(void*, const void*, unsigned long);

u16 fn_801A7F40(void* destination, Buffer801A7F40* buffer)
{
    void* source = buffer->data;
    buffer->data = destination;
    memcpy(buffer->data, source, buffer->count * 0x74);
    return ((u16)(buffer->count * 0x74) + 0x1F) & ~0x1F;
}
