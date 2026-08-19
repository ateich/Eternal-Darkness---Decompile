typedef unsigned char u8;
typedef unsigned int u32;

typedef struct FileInfo {
    u8 pad0[0x34];
    u32 size;
} FileInfo;

extern int fn_80213394(char*, FileInfo*);
extern int fn_802137F4(FileInfo*, void*, u32, int, int);
extern void fn_8021345C(FileInfo*);

u32 fn_8015E86C(char* path, void* destination)
{
    u32 size = 0;
    FileInfo info;

    if (fn_80213394(path, &info)) {
        size = (info.size + 0x1F) & ~0x1F;
        while (fn_802137F4(&info, destination, size, 0, 2) == -1) {}
        fn_8021345C(&info);
    }
    return size;
}
