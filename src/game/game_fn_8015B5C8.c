typedef unsigned char u8;

typedef struct Stream {
    void* source;
    unsigned int remaining;
    unsigned int total;
    u8* cursor;
} Stream;

extern u8* fn_8015B708(Stream*);

int fn_8015B5C8(Stream* stream)
{
    if (stream->remaining == 0) {
        stream->cursor = fn_8015B708(stream);
    } else {
        stream->cursor++;
    }
    stream->remaining--;
    return *stream->cursor;
}
