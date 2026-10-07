typedef struct ObjLink {
    char pad0[0xBC];
    int unkBC;
} ObjLink;

typedef struct ObjData {
    char pad0[0x8C];
    ObjLink *unk8C;
    char pad90[0x9E - 0x90];
    unsigned char unk9E;
    unsigned char unk9F;
} ObjData;

typedef struct SpawnParams {
    float pos[3];
    float facing;
    int unk10;
    int unk14;
    char pad18[0x28 - 0x18];
    int unk28;
    int unk2C;
} SpawnParams;

extern int lbl_8064D18C;
extern int lbl_8064C4E4;
extern void *lbl_8064C5B4;
extern float lbl_8064F200;
extern float lbl_8064F204;
extern float lbl_8064F208;

extern void fn_8002AA18();
extern void fn_8002A508();
extern void fn_8002AC60();
extern void fn_800073E4();
extern void fn_8002A4C8();

extern int fn_80201B44(void);
extern int fn_800AD2B4(void);
extern void fn_80043F44(SpawnParams *);
extern int fn_80201814(int);
extern void *fn_80155DB4(void);
extern ObjData *fn_80201B8C(int);
extern void fn_801568FC(void *, void (*)());
extern void fn_80201D3C(int, int);
extern int fn_80201BC8(int);
extern void fn_800C96D4(int, int, int, int, int, int, float);
extern void fn_8020104C(int, int, int, int, float);
extern unsigned long long fn_8020123C(int, int, int, int);
extern void fn_8011FA8C(int, int, int);
extern float fn_8012B750(int);
extern void fn_80201E78(SpawnParams *, int);
extern int fn_80034708(SpawnParams *);
extern void fn_801261F4(int);
extern void fn_8012B7A0(int, float);
extern void fn_80201D54(int, int);
extern int fn_80201B54(int);
extern void fn_80201AF8(int);
extern void fn_802015A4(int);
extern void *fn_80156DA0(int, SpawnParams *);
extern void fn_80156904(void *, int);
extern void fn_801568C8(void *, void (*)(), void (*)(), void (*)());
extern void fn_801568C0(void *, void (*)());
extern void fn_801568B8(void *, void (*)());
extern void fn_8015690C(void *, void (*)());
extern void fn_80156918(void *, int);
extern void fn_801F6ED0(int, int);
extern int fn_8004918C(void);
extern void fn_8004948C(int, int, int);
extern void fn_801A7864(int);
extern void fn_80006954(int);

int fn_800C6890(int type, int fade) {
    int object;
    int pending;
    void *anim;
    void *handler;
    ObjData *oldData;
    ObjData *newData;
    int oldModel;
    int newModel;
    int self;
    int newId;
    int sound;
    SpawnParams params;

    self = fn_80201B44();
    pending = fn_800AD2B4();
    fn_80043F44(&params);
    object = fn_80201814(self);
    anim = fn_80155DB4();

    switch (type) {
    case 6:
        params.unk10 = 0x40;
        params.unk14 = 0x8E;
        break;
    case 8:
        params.unk10 = 0x40;
        params.unk14 = 0x8F;
        break;
    case 10:
        params.unk10 = 0x40;
        params.unk14 = 0x90;
        break;
    case 12:
        params.unk10 = 0x40;
        params.unk14 = 0x91;
        break;
    case 14:
        params.unk10 = 0x40;
        params.unk14 = 0x92;
        break;
    case 16:
        params.unk10 = 0x40;
        params.unk14 = 0x93;
        break;
    case 19:
        params.unk10 = 0x40;
        params.unk14 = 0x99;
        break;
    }

    oldData = fn_80201B8C(object);
    fn_801568FC(anim, fn_8002AA18);
    fn_80201D3C(object, 1);
    oldModel = fn_80201BC8(object);
    if (fade == 1) {
        fn_800C96D4(object, 0xFF, -1, 0, 100, 1, lbl_8064F200);
        fn_8020104C(0x33, 0, self, 0, lbl_8064F204);
    }
    fn_8011FA8C(oldModel, 0xC0, 0);
    oldData->unk9E = 2;
    oldData->unk9F = 1;
    params.unk2C = lbl_8064D18C;
    params.unk28 = 0x52;
    params.facing = fn_8012B750(oldModel);
    fn_80201E78(&params, object);

    object = fn_80034708(&params);
    newModel = fn_80201BC8(object);
    newData = fn_80201B8C(object);
    fn_801261F4(newModel);
    if (fade == 1) {
        fn_800C96D4(object, 1, 2, 0xFF, 100, 1, lbl_8064F200);
    }
    fn_801261F4(newModel);
    fn_8012B7A0(newModel, params.facing);
    fn_80201D54(object, params.unk2C);
    fn_80201D3C(object, 0);
    newData->unk9E = 1;
    newData->unk9E = 1;
    newId = fn_80201B54(object);
    fn_80201AF8(newId);
    newData->unk8C->unkBC = self;
    oldData->unk8C->unkBC = newId;
    fn_8020123C(0xF0, newId, self, 0x56);
    fn_8020123C(0xD5, newId, self, newId);
    if (fade == 1) {
        fn_8020104C(0x69, self, self, -2, lbl_8064F208);
    } else {
        fn_8020123C(0x69, self, self, -2);
    }
    fn_8020123C(0x3C, newId, newId, 0);
    fn_802015A4(object);

    handler = fn_80156DA0(3, &params);
    fn_80156904(handler, 0);
    fn_801568C8(handler, fn_8002A508, fn_8002AC60, fn_800073E4);
    fn_801568FC(handler, fn_800073E4);
    fn_801568C0(handler, fn_8002A508);
    fn_801568B8(handler, fn_8002AC60);
    fn_8015690C(handler, fn_8002A4C8);
    fn_80156918(handler, object);
    fn_801F6ED0(lbl_8064C4E4, newModel);
    lbl_8064C4E4 = newModel;
    lbl_8064C5B4 = handler;

    sound = fn_8004918C();
    fn_8004948C(object, sound, 0);
    fn_801A7864(sound);
    if (pending != 0) {
        fn_8020123C(0xFB, newId, pending, newId);
    }
    fn_80006954(0xB6);
    return object;
}
