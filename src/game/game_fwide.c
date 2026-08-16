typedef struct RuntimeFile {
    unsigned char reserved[5];
    unsigned char prefix : 2;
    unsigned char orientation : 2;
    unsigned char suffix : 4;
} RuntimeFile;

int fwide(RuntimeFile* file, int mode)
{
    if (file == 0 || ((*(unsigned short*)((unsigned char*)file + 4) >> 6) & 7) == 0) {
        return 0;
    }

    switch (file->orientation) {
    case 0:
        if (mode > 0) {
            file->orientation = 2;
        } else if (mode < 0) {
            file->orientation = 1;
        }
        return mode;
    case 2:
        return 1;
    case 1:
        return -1;
    default:
        return (int)file;
    }
}
