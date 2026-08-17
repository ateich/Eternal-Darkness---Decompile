typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Queue {
    void* callbacks[14];
    u32 values[14];
    u32 kinds[14];
    u32 optional_a8[2];
    u32 optional_b0[2];
    u8 padB8[0x48];
    u8 index : 7;
    u8 control : 1;
    u8 pad101;
    u8 flags[14];
} Queue;

void fn_8012880C(Queue* queue, int clear_optional_b0, int clear_optional_a8)
{
    int i;

    for (i = 0; i < 14; i++) {
        queue->flags[i] = 0;
        queue->callbacks[i] = 0;
        queue->values[i] = 0;
        queue->kinds[i] = 0;
    }
    if (clear_optional_a8) {
        queue->optional_a8[0] = 0;
        queue->optional_a8[1] = 0;
    }
    if (clear_optional_b0) {
        queue->optional_b0[0] = 0;
        queue->optional_b0[1] = 0;
    }
    queue->index = 0;
}
