typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TRKBuffer {
    u32 mutex;
    u32 in_use;
    u32 length;
    u32 position;
    u8 data[0x880];
} TRKBuffer;

extern TRKBuffer lbl_80328610[3];
extern void fn_800F34CC(void *);
extern void fn_800F34C4(void *);
extern void fn_800F34BC(void *);

int TRKInitializeMessageBuffers(void)
{
    register TRKBuffer *buffer;
    int i;

    i = 0;
    buffer = &lbl_80328610[i];

    for (i = 0; i < 3; i++, buffer++) {
        fn_800F34CC(buffer);
        fn_800F34C4(buffer);
        buffer->in_use = 0;
        fn_800F34BC(buffer);
    }
    return 0;
}
