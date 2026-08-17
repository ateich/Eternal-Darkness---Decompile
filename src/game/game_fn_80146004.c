typedef struct StreamContext {
    unsigned char input[0x2000];
    int input_remaining;
    int input_offset;
    unsigned char pad2008[0x10];
    unsigned short value;
    unsigned short maximum;
    unsigned short count;
    unsigned char pad201E[2];
    int state;
} StreamContext;

extern void fn_80145EDC(StreamContext*);

void fn_80146004(StreamContext* context)
{
    int byte;

    context->maximum = 0xFFFF;
    context->count = 0;
    context->state = 0;

    if (context->input_remaining > 0) {
        context->input_remaining--;
        byte = context->input[context->input_offset++];
    } else {
        fn_80145EDC(context);
        if (context->input_remaining > 0) {
            context->input_remaining--;
            byte = context->input[context->input_offset++];
        } else {
            byte = -1;
        }
    }
    context->value = byte << 8;

    if (context->input_remaining > 0) {
        context->input_remaining--;
        byte = context->input[context->input_offset++];
    } else {
        fn_80145EDC(context);
        if (context->input_remaining > 0) {
            context->input_remaining--;
            byte = context->input[context->input_offset++];
        } else {
            byte = -1;
        }
    }
    context->value |= byte & 0xFF;
}
