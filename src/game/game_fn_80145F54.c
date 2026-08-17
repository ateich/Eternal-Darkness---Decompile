extern void* memset(void*, int, unsigned int);

typedef struct StreamContext StreamContext;
typedef int (*ReadCallback)(void*, int, int);

struct StreamContext {
    unsigned char input[0x2000];
    unsigned char pad2000[8];
    int input_remaining;
    unsigned char pad200C[4];
    int total_remaining;
    int total_read;
    unsigned char pad2018[0x10];
    unsigned char workspace[0xAA4];
    int callback_arg;
    void* write_callback;
    ReadCallback read_callback;
};

void fn_80145F54(StreamContext* context)
{
    if (context->read_callback(context->input + 0x1000, context->input_remaining,
                               context->callback_arg) == 1) {
        context->total_remaining = 0;
        memset(context->workspace, 0, sizeof(context->workspace));
    }
    context->total_read += context->input_remaining;
    context->input_remaining = 0;
}
