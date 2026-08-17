typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Queue {
    void* callbacks[14];
    u32 values[14];
    u32 kinds[14];
    u8 padA8[0x58];
    u8 index : 7;
    u8 control : 1;
} Queue;

void fn_801287C4(Queue* queue, void* callback, u32 value, u32 kind)
{
    queue->callbacks[queue->index] = callback;
    queue->values[queue->index] = value;
    queue->kinds[queue->index] = kind << 17;
    queue->index++;
}
