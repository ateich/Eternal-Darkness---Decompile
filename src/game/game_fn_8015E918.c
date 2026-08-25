typedef unsigned char u8;
typedef unsigned int u32;

typedef struct FileInfo {
    u8 pad0[0x34];
    u32 size;
    u8 pad38[0x10];
} FileInfo;

extern char lbl_805FAA40[];
extern char lbl_805E2BDC[];
extern int fn_80213394(char*, FileInfo*);
extern int fn_802137F4(FileInfo*, void*, u32, int, int);
extern void fn_8021345C(FileInfo*);
extern void DCInvalidateRange(void*, u32);
extern void fn_8021B730(void*, int, int, int, void*, void*, u32, void*);
extern int fn_8020D318(void*, int, int);
extern void fn_8015E8E8(void);

u32 fn_8015E918(char* path, void* value, u32 unused, void* destination, u32 unused2)
{
    u32 size = 0;
    FileInfo info;

    if (fn_80213394(path, &info)) {
        size = (info.size + 0x1F) & ~0x1F;
        while (fn_802137F4(&info, destination, size, 0, 2) == -1) {}
        fn_8021345C(&info);
        DCInvalidateRange(destination, size);
        fn_8021B730(lbl_805FAA40, 7, 0, 0, destination, value, size,
                    fn_8015E8E8);
        fn_8020D318(lbl_805E2BDC, 0, 1);
    }
    return size;
}
