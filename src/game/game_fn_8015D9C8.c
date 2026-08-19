typedef struct DVDFileInfo {
    unsigned char data[0x34];
    int length;
} DVDFileInfo;

extern void* fn_8015D424(int*, int);
extern void fn_8015D44C(void);
extern void fn_8015D7D4(int, DVDFileInfo*, int, int, void*);
extern int fn_80213394(void*, DVDFileInfo*);
extern void fn_8021345C(DVDFileInfo*);
extern int lbl_8064D11C;

int fn_8015D9C8(void* path, int kind)
{
    int allocation_size;
    DVDFileInfo info;
    int length;
    void* buffer;

    buffer = fn_8015D424(&allocation_size, 4);
    if (fn_80213394(path, &info)) {
        length = (info.length + 31) & ~31;
        if (kind == 0xF69340) {
            lbl_8064D11C = length;
        }
        fn_8015D7D4(kind, &info, 0, length, buffer);
        fn_8021345C(&info);
    }
    fn_8015D44C();
    return length;
}
