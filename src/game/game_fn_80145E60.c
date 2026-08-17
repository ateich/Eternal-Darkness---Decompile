typedef struct StreamContext {
    unsigned char pad[0x2AD0];
    void* write_callback;
    void* read_callback;
} StreamContext;

void fn_80145E60(StreamContext* context, void* write_callback, void* read_callback)
{
    context->write_callback = write_callback;
    context->read_callback = read_callback;
}
