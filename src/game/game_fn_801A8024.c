typedef unsigned short u16;
typedef unsigned long u32;

typedef struct Buffer801A8024 {
    unsigned char pad[0x10];
    u16 count;
    unsigned char pad12[2];
    void* data;
} Buffer801A8024;

extern void* memcpy(void*, const void*, unsigned long);

u32 fn_801A8024(void* source, Buffer801A8024* buffer)
{
    memcpy(buffer->data, source, buffer->count * 0x74);
    return (buffer->count * 0x74 + 0x1F) & ~0x1F;
}
