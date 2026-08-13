/*
 * NonMatching: honest-C reconstruction of the resource-record file reader.
 * It opens the fixed resource archive, consumes its 0x20-byte header, checks
 * the requested 0xE0-byte record against the file-derived count, reads that
 * record with retry-on-negative-result semantics, and closes the file.
 */

typedef struct FileHandle {
    char pad_00[0x34];
    unsigned int length;
} FileHandle;

extern char lbl_8064B540;
extern char lbl_8064B544;
extern char lbl_80244680[];
extern char lbl_802446A0[];

extern void fn_802136A4(void *);
extern int fn_80213394(const char *, FileHandle *);
extern int fn_802137F4(FileHandle *, void *, unsigned int, unsigned int, int);
extern void fn_8021345C(FileHandle *);

int fn_800723A8(unsigned int index, void *output)
{
    FileHandle file;
    unsigned int count;
    unsigned int offset;
    int opened;

    fn_802136A4(&lbl_8064B540);
    opened = fn_80213394(lbl_802446A0, &file);
    fn_802136A4(&lbl_8064B544);
    if (opened == 0) {
        return 0;
    }

    count = (file.length - 0x20) / 0xE0;
    offset = index * 0xE0 + 0x20;
    while (fn_802137F4(&file, lbl_80244680, 0x20, 0, 2) < 0) {
    }
    if (index >= count) {
        return 0;
    }
    while (fn_802137F4(&file, output, 0xE0, offset, 2) < 0) {
    }
    fn_8021345C(&file);
    return 1;
}
