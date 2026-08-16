typedef struct FileRecord {
    char pad00[0x18];
    unsigned int position;
    unsigned char *buffer;
    unsigned int buffer_size;
    unsigned char *buffer_ptr;
    unsigned int buffer_space;
    unsigned int alignment_mask;
    char pad30[4];
    unsigned int buffer_position;
} FileRecord;

void __prep_buffer(FileRecord *file)
{
    file->buffer_ptr = file->buffer;
    file->buffer_space = file->buffer_size;
    file->buffer_space -= file->position & file->alignment_mask;
    file->buffer_position = file->position;
}
