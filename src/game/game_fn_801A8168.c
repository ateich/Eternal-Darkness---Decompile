typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct Buffer801A8168 {
    u8 pad[0x10];
    u16 count;
    u8 pad12[2];
    void* data;
} Buffer801A8168;

typedef struct Context801A8168 {
    u8 pad[0xA0];
    Buffer801A8168 buffer;
    u8 padB8[0x808A];
    signed char active;
    signed char ready;
} Context801A8168;

extern Context801A8168* fn_8015C28C(int);
extern u32 fn_801A80FC(void*, u16, void*);

u32 fn_801A8168(void* destination)
{
    u32 size = 0;
    int index = 0;
    Context801A8168* context;

    do {
        context = fn_8015C28C(index);
        if (context != 0 && context->active != 0 && context->ready != 0) {
            size += fn_801A80FC((u8*)destination + (u16)size,
                                context->buffer.count,
                                context->buffer.data);
        }
        index++;
    } while (index < 2);

    return size;
}
