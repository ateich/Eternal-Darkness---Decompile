typedef struct FileRecord {
    int handle;
    char pad04[0x14];
    unsigned int position;
    unsigned char *buffer;
    unsigned int buffer_size;
    unsigned char *buffer_ptr;
    unsigned int buffer_space;
    unsigned int alignment_mask;
    char pad30[4];
    unsigned int buffer_position;
    char pad38[8];
    int (*write)(int, unsigned char *, unsigned int *, void *);
    char pad44[4];
    void *ref;
} FileRecord;

int __flush_buffer(FileRecord *file, unsigned int *written)
{
    int result;
    unsigned int count = file->buffer_ptr - file->buffer;

    if (count != 0) {
        file->buffer_space = count;
        result = file->write(file->handle, file->buffer, &file->buffer_space,
                             file->ref);
        if (written != 0) {
            *written = file->buffer_space;
        }
        if (result != 0) {
            return result;
        }
        file->position += file->buffer_space;
    }
    file->buffer_ptr = file->buffer;
    file->buffer_space = file->buffer_size;
    file->buffer_space -= file->position & file->alignment_mask;
    file->buffer_position = file->position;
    return 0;
}
