typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Batch {
    char pad_0[0x60];
    struct Record* records;
    char pad_64[0x1A];
    u8 count;
} Batch;

typedef struct Pair {
    unsigned int word[2];
} Pair;

typedef struct Record {
    Pair pair;
    unsigned int word2;
    float vector[2];
    float scale;
} Record;

typedef struct Slot {
    int handle;
    float output[6];
    Pair pair;
    unsigned int word2;
    unsigned int word3;
    u16 value;
    char pad_2E[0x9];
    u8 flag;
    u8 kind;
    char pad_39[0xF];
    int state;
    char pad_4C[0x2C];
} Slot;

typedef struct Runtime {
    char pad_0[0x50];
    Slot slots[3];
    char pad_1B8[0x48];
} Runtime;

extern Runtime lbl_8030F540;
extern float lbl_80650228;
extern float lbl_8065024C;
extern float lbl_80650250;
extern void* fn_801FD6F4(int);
extern void fn_801FD6AC(void*, Record*, float*, int);
extern void fn_801FE8DC(float*, float, float, float);
extern int fn_801E8328();

void fn_80132B24(Batch* batch, int value)
{
    int i;

    if (batch->count == 0)
        return;
    for (i = 0; i < batch->count; i++) {
        Record* record = &batch->records[i];
        void* resource = fn_801FD6F4(lbl_8030F540.slots[i].handle);

        if (resource != 0) {
            fn_801FD6AC((char*)resource + 0x34, record, record->vector,
                        (int)(record->scale * lbl_8065024C));
        } else {
            lbl_8030F540.slots[i].pair = record->pair;
            lbl_8030F540.slots[i].word2 = record->word2;
            lbl_8030F540.slots[i].word3 = *(unsigned int*)record->vector;
            lbl_8030F540.slots[i].state = 0;
            lbl_8030F540.slots[i].value = value;
            lbl_8030F540.slots[i].flag = 0;
            lbl_8030F540.slots[i].kind = 7;
            fn_801FE8DC(lbl_8030F540.slots[i].output, lbl_80650228,
                        lbl_80650228, lbl_80650250);
            fn_801E8328(0x20, &lbl_8030F540.slots[i].handle);
        }
    }
}
