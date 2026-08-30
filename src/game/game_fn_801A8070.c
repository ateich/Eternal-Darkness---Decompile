typedef unsigned char u8;
typedef unsigned long u32;

typedef struct Context801A8070 {
    u8 pad[0x8142];
    signed char active;
    signed char ready;
} Context801A8070;

extern Context801A8070* fn_8015C28C(int);
extern u32 fn_801A8024(void*, void*);

u32 fn_801A8070(void* destination)
{
    u32 size = 0;
    int index = 0;
    Context801A8070* context;

    do {
        context = fn_8015C28C(index);
        if (context != 0 && context->active != 0 && context->ready != 0) {
            size += fn_801A8024((u8*)destination + size, (u8*)context + 0xA0);
        }
        index++;
    } while (index < 2);

    return size;
}
