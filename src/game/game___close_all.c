typedef unsigned char u8;
typedef unsigned short u16;

typedef struct FileRecord {
    char pad0[4];
    u16 mode;
    char pad6[6];
    u8 allocated;
    char padD[0x3F];
    struct FileRecord *next;
} FileRecord;

extern FileRecord __files[];
extern void fn_800F91F0(FileRecord *);
extern void fn_800F68D0(FileRecord *);

void __close_all(void)
{
    FileRecord *file = __files;

    while (file != 0) {
        FileRecord *next;
        if (((file->mode >> 6) & 7) != 0) {
            fn_800F91F0(file);
        }
        next = file->next;
        if (file->allocated != 0) {
            fn_800F68D0(file);
            break;
        }
        file->mode = (file->mode & ~0x1C0) | (3 << 6);
        if (next != 0 && next->allocated != 0) {
            file->next = 0;
        }
        file = next;
    }
}
