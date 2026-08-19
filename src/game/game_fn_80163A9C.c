typedef struct Buffer {
    char pad00[0x18];
    char* data;
    unsigned int capacity;
    char pad20[0x40];
    unsigned int accounting;
} Buffer;

extern void* fn_8016B5CC(void*, void*, unsigned int, char*, int);
extern char lbl_8024F750[];

char* fn_80163A9C(Buffer* buffer, unsigned int requested)
{
    if (requested > buffer->capacity) {
        buffer->data = fn_8016B5CC(buffer, buffer->data, requested,
                                   lbl_8024F750, 0x3C);
        buffer->accounting += requested - buffer->capacity;
        buffer->capacity = requested;
    }
    return buffer->data;
}
