typedef unsigned char u8;

typedef struct Runtime {
    char pad_0[0x10];
    char* records;
} Runtime;

typedef struct MeshRecord {
    void* object;
    char pad_4[0x20];
    unsigned short count;
} MeshRecord;

typedef struct Batch {
    char pad_0[0x5C];
    char* entries;
    char pad_60[0x10];
    int* record_indices;
    char pad_74[8];
    u8 count;
} Batch;

extern void fn_8012D0D0(void);

/* The retail routine expands each indexed mesh entry, performs per-vertex
 * fixed-point conversion, and submits visible records.  This recovery keeps
 * the outer ownership/filtering loop explicit while the vertex transforms
 * remain to be reconstructed. */
void fn_80131E8C(Runtime* runtime, Batch* batch)
{
    int i;

    for (i = 0; i < batch->count; i++) {
        int index = batch->record_indices[i];
        MeshRecord* record = (MeshRecord*)(runtime->records + index * 0x28);
        signed char flags = *(signed char*)(batch->entries + i + 0x0E);

        if (record->object != 0) {
            int enabled = flags & 1;
            int alternate = flags & 2;
            if (enabled || alternate) {
                fn_8012D0D0();
            }
        }
    }
}
