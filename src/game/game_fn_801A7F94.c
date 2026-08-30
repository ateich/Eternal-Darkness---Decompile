typedef unsigned short u16;

typedef struct Buffer801A7F94 {
    unsigned char pad[0x10];
    u16 count;
    unsigned char pad12[2];
    void* data;
} Buffer801A7F94;

typedef struct Context801A7F94 {
    unsigned char pad[0xA0];
    Buffer801A7F94 buffer;
    unsigned char padB8[0x8142 - 0xB8];
    signed char enabled0;
    signed char enabled1;
} Context801A7F94;

extern Context801A7F94* fn_8015C28C(int);
extern u16 fn_801A7F40(void*, Buffer801A7F94*);

u16 fn_801A7F94(void* destination)
{
    u16 size = 0;
    int index = 0;

    do {
        Context801A7F94* context = fn_8015C28C(index);
        if (context != 0 && context->enabled0 != 0 && context->enabled1 != 0) {
            size += fn_801A7F40((unsigned char*)destination + size,
                                (Buffer801A7F94*)((unsigned char*)context + 0xA0));
        }
        index++;
    } while (index < 2);
    return size;
}
