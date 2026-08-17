typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Queue {
    void* callbacks[14];
    u32 values[14];
    u32 kinds[14];
    u8 padA8[0x5A];
    u8 flags[14];
} Queue;

void fn_801289A0(Queue* queue)
{
    int i;

    for (i = 0; i < 14; i++) {
        if (queue->callbacks[i] != 0) {
            queue->flags[i] |= 1;
        }
    }
}
