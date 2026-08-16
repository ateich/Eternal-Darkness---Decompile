typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex;
    u32 in_use;
    u32 length;
    u32 position;
    u8 data[0x880];
} TRKBuffer;

typedef int (*TRKDispatchHandler)(TRKBuffer *);

extern u32 lbl_80329FD8;
extern TRKDispatchHandler lbl_8024A798[];
extern int fn_800EFC6C(TRKBuffer *, u32);
extern int fn_800EF86C(TRKBuffer *, u8 *);

int TRKDispatchMessage(TRKBuffer *buffer)
{
    int result = 0x500;
    u8 command;

    fn_800EFC6C(buffer, 0);
    fn_800EF86C(buffer, &command);
    if (command < lbl_80329FD8)
        result = lbl_8024A798[command](buffer);
    return result;
}
