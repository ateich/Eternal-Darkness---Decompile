typedef unsigned char u8;

typedef struct Runtime {
    char pad_0[0x10];
    char* records;
} Runtime;

typedef struct Batch {
    char pad_0[0x5C];
    char* entries;
    char* values;
    char* extra;
    char* auxiliary;
    char* scene;
    int* indices;
    int* secondary;
    char pad_78[4];
    u8 count;
} Batch;

extern int lbl_8064D7F0[2];
extern Batch* fn_801328D4(Runtime*, Batch*);

Batch* fn_80132794(Runtime* runtime, Batch* batch)
{
    int i;

    batch->indices = (int*)((char*)batch + (int)batch->indices);
    batch->secondary = (int*)((char*)batch + (int)batch->secondary);
    batch->entries = (char*)batch + (int)batch->entries;
    batch->auxiliary = (char*)batch + (int)batch->auxiliary;
    batch->values = (char*)batch + (int)batch->values;
    if (batch->extra != 0) {
        batch->extra = (char*)batch + (int)batch->extra;
    }

    for (i = 0; i < batch->count; i++) {
        if (*(void**)(runtime->records + batch->indices[i] * 0x28) != 0) {
            *(char**)(batch->entries + i * 0x20 + 0x18) =
                (char*)batch + *(int*)(batch->entries + i * 0x20 + 0x18);
            *(char**)(batch->entries + i * 0x20 + 0x10) =
                (char*)batch + *(int*)(batch->entries + i * 0x20 + 0x10);
            *(char**)(batch->entries + i * 0x20 + 0x14) =
                (char*)batch + *(int*)(batch->entries + i * 0x20 + 0x14);
            if (*(void**)(batch->entries + i * 0x20 + 0x1C) != 0) {
                *(char**)(batch->entries + i * 0x20 + 0x1C) =
                    (char*)batch + *(int*)(batch->entries + i * 0x20 + 0x1C);
            }
        }
    }
    if (batch->scene != 0) {
        fn_801328D4(runtime, batch);
    } else {
        lbl_8064D7F0[0] = 0;
        lbl_8064D7F0[1] = 0;
    }
    return batch;
}
