typedef struct StreamContext StreamContext;
typedef void (*WriteCallback)(StreamContext*, int, int);

struct StreamContext {
    unsigned char pad0[0x2000];
    int chunk_size;
    int field2004;
    int field2008;
    int field200C;
    int remaining;
    unsigned char pad2014[0xAB8];
    int callback_arg;
    WriteCallback write_callback;
    void* read_callback;
};

void fn_80145EDC(StreamContext* context)
{
    context->chunk_size = 0x1000;
    if (context->remaining < 0x1000)
        context->chunk_size = context->remaining;
    if (context->chunk_size != 0) {
        context->write_callback(context, context->chunk_size, context->callback_arg);
        context->remaining -= context->chunk_size;
    }
    context->field2004 = 0;
}
