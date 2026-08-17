typedef struct Runtime Runtime;

typedef struct Batch {
    char pad_0[0x6C];
    char* scene;
} Batch;

typedef struct SceneRecord {
    unsigned int pointers[11];
    char pad_2C[0x48];
} SceneRecord;

typedef struct SceneHeader {
    int count;
    SceneRecord* records;
    int field_08;
    char* field_0C;
    char* field_10;
    char* field_14;
    char* field_18;
    int field_1C;
    char* field_20;
    char* field_24;
    int field_28;
    char* field_2C;
    char* field_30;
    int field_34;
    char* field_38;
    char* field_3C;
} SceneHeader;

extern int lbl_8064CF40;
extern void fn_801FF8EC(int, int, int, int, int);
extern void fn_801FFD08(SceneHeader*);

#define SCENE ((SceneHeader*)batch->scene)

Batch* fn_801328D4(Runtime* runtime, Batch* batch)
{
    int i;
    int j;
    char* base = (char*)batch;

    batch->scene = base + (int)batch->scene;
    SCENE->records = (SceneRecord*)(base + (int)SCENE->records);

    for (i = 0; i < SCENE->count; i++) {
        for (j = 0; j < 11; j++) {
            if (SCENE->records[i].pointers[j] != 0) {
                SCENE->records[i].pointers[j] =
                    (int)base + SCENE->records[i].pointers[j];
            }
        }
    }

    SCENE->field_0C = base + (int)SCENE->field_0C;
    SCENE->field_10 = base + (int)SCENE->field_10;
    SCENE->field_14 = base + (int)SCENE->field_14;
    SCENE->field_18 = base + (int)SCENE->field_18;
    SCENE->field_20 = base + (int)SCENE->field_20;
    SCENE->field_24 = base + (int)SCENE->field_24;
    SCENE->field_2C = base + (int)SCENE->field_2C;
    SCENE->field_30 = base + (int)SCENE->field_30;
    SCENE->field_38 = base + (int)SCENE->field_38;
    SCENE->field_3C = base + (int)SCENE->field_3C;

    if (lbl_8064CF40 == 0) {
        fn_801FF8EC(SCENE->field_28, SCENE->field_08, SCENE->field_34,
                    SCENE->count, SCENE->field_1C);
        lbl_8064CF40 = 1;
    }
    fn_801FFD08(SCENE);
    return batch;
}
