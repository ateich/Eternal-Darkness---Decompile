typedef unsigned char u8;

typedef struct Batch {
    char pad_0[8];
    u8 count;
    char pad_9[3];
    char* entries;
} Batch;

extern void fn_801568B8(void*, int);
extern void fn_801568C0(void*, int);
extern void fn_801568FC(void*, int);
extern void fn_80156FF4(void*);

void fn_80132C94(Batch* batch)
{
    int offset = 0;
    int i = 0;

    while (i < batch->count) {
        void* object = *(void**)(batch->entries + offset + 4);
        if (object != 0) {
            fn_801568B8(object, 0);
            fn_801568C0(*(void**)(batch->entries + offset + 4), 0);
            fn_801568FC(*(void**)(batch->entries + offset + 4), 0);
            fn_80156FF4(*(void**)(batch->entries + offset + 4));
            *(void**)(batch->entries + offset + 4) = 0;
        }
        offset += 0x10;
        i++;
    }
}
