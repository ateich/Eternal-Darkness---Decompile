typedef int s32;
typedef unsigned char u8;

typedef struct ObjectData {
    char pad00[0x94];
    s32 type;
    char pad98[7];
    u8 kind;
} ObjectData;

typedef struct TypeEntry {
    s32 unk0;
    s32 type;
    s32 unk8;
} TypeEntry;

extern TypeEntry lbl_8023BA64[];
extern void *fn_80201B9C(void);
extern void *fn_80201BC0(void *);
extern s32 fn_80201EB8(void *);
extern s32 fn_80201B4C(void *);
extern s32 fn_80201B5C(void *);
extern ObjectData *fn_80201B8C(void *);

s32 fn_800797D8(s32 owner)
{
    void *object;
    s32 type;

    object = fn_80201B9C();
    type = 0;

    while (object != 0) {
        if (owner == fn_80201EB8(object) && fn_80201B4C(object) == 1) {
            s32 object_kind = fn_80201B5C(object);
            ObjectData *data = fn_80201B8C(object);

            if (object_kind != 0x15 && data != 0 && data->kind == 7) {
                if (type == 0) {
                    type = data->type;
                } else if (data->type == lbl_8023BA64[type].type) {
                    return data->type;
                }
            }
        }
        object = fn_80201BC0(object);
    }
    return type;
}
