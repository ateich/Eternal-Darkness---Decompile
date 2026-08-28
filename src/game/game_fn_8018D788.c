typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Buffers {
    u8* vertices;
    u8* colors;
    u8* indices;
} Buffers;

void fn_8018D788(int allocation, u8* self, Buffers* buffers, u16 offset)
{
    buffers->vertices = *(u8**)(self + 0x50);
    buffers->colors = *(u8**)(self + 0x54);
    buffers->indices = *(u8**)(self + 0x58);

    if (allocation != 0) {
        buffers->vertices += offset * 6;
        buffers->colors += offset * 4;
        buffers->indices += offset * 4;
    }
}
