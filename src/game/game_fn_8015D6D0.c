typedef struct DVDFileInfo {
    unsigned char data[0x34];
    int length;
} DVDFileInfo;

extern unsigned char lbl_805FA1F0[];
extern unsigned char lbl_8064D130;
extern void fn_8015CDF0(void);
extern void fn_8015D6A0(void);
extern void fn_8020D1F0(void*, void*, int);
extern int fn_8020D318(void*, void*, int);
extern int fn_80213394(void*, DVDFileInfo*);
extern void fn_8021345C(DVDFileInfo*);
extern int fn_80213704(DVDFileInfo*, void*, int, int, void*, int);

int fn_8015D6D0(register void* path, register unsigned char* buffer,
                register int size)
{
    DVDFileInfo info;
    int message;
    register int offset;
    register int chunk;
    register int result;
    int length;

    result = 0;
    offset = 0;
    fn_8020D1F0(lbl_805FA1F0, &lbl_8064D130, 2);
    if (fn_80213394(path, &info)) {
        length = (info.length + 31) & ~31;
        if (length > size) {
            length = size;
        }
        while (length != 0) {
            chunk = 0x1000;
            if (length <= 0x1000) {
                chunk = length;
            }
            while (!fn_80213704(&info, buffer, chunk, offset,
                                fn_8015D6A0, 2)) {
            }
            fn_8020D318(lbl_805FA1F0, &message, 1);
            fn_8015CDF0();
            offset += chunk;
            length -= chunk;
            buffer += chunk;
        }
        result = (info.length + 31) & ~31;
        fn_8021345C(&info);
    }
    return result;
}
