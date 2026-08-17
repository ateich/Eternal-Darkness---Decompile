typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

typedef struct Batch {
    char pad_0[0x74];
    int* handles;
    char pad_78[5];
    u8 count;
} Batch;

typedef struct ResourceDescriptor {
    char pad_0[0x1E];
    s16 state;
    char pad_20[8];
} ResourceDescriptor;

typedef struct RuntimeEntry {
    char pad_0[0x1DA];
    u8 resource_kind;
    char pad_1DB;
    s8 disabled;
} RuntimeEntry;

extern RuntimeEntry lbl_8030F540[];
extern ResourceDescriptor lbl_80241DE8[];
extern struct {
    char pad_0[0x1914];
    u8 allow_all_resources;
} lbl_803003C8;

extern int fn_80138224(void);
extern void fn_8016B400(int, int, int);

void fn_80132A4C(Batch* batch)
{
    int i;
    int offset;
    RuntimeEntry* entry;
    char* context;
    ResourceDescriptor* descriptor;

    if (batch->count != 0) {
        entry = lbl_8030F540;
        context = (char*)&lbl_803003C8;
        descriptor = lbl_80241DE8;
        offset = 0;
        for (i = 0; i < batch->count; i++, offset += 4) {
            ResourceDescriptor* resource = descriptor;
            u8 kind = entry->resource_kind;
            resource += kind;

            if (resource->state != -1 && entry->disabled == 0 &&
                (*(u8*)(context + 0x1914) != 0 || kind == 0x60) &&
                batch->handles[i] == -1) {
                fn_80138224();
            } else if (batch->handles[i] != -1) {
                fn_8016B400(batch->handles[i], 0, 0);
            }
        }
    }
}
