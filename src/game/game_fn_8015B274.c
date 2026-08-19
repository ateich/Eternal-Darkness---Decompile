typedef unsigned char u8;

typedef struct BitStream {
    void* source;
    unsigned int remaining;
    unsigned int total;
    u8* cursor;
    unsigned int mode;
    unsigned int limit;
    unsigned int end;
    void* reader;
} BitStream;

extern void fn_8015B628(BitStream*);
extern int fn_8015B5C8(BitStream*);
extern void fn_8020B740(void*, int);

int fn_8015B274(void* destination, int unused, u8* output, int arg6,
                int arg7, int arg8, void* reader, int mode)
{
    BitStream stream;
    int written = 0;
    int i;

    stream.source = destination;
    stream.remaining = 0;
    stream.total = 0;
    stream.mode = mode;
    stream.limit = arg8;
    stream.end = arg7 + arg8;
    stream.reader = reader;
    fn_8015B628(&stream);

    if (mode == 0) {
        for (i = 0; i < 64; i++) {
            output[written++] = fn_8015B5C8(&stream);
        }
    } else if (mode == 1) {
        for (i = 0; i < 4; i++) {
            output[written++] = fn_8015B5C8(&stream);
        }
    }

    while (stream.source != 0 || stream.remaining != 0) {
        output[written++] = fn_8015B5C8(&stream);
    }
    fn_8020B740(output, written);
    return written;
}
