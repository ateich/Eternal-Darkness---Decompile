typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

typedef struct Point16 {
    s16 x;
    s16 y;
} Point16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct Request {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    u8 pad2C[0xC];
} Request;

typedef struct Root {
    u8 pad00[8];
    s32 mode;
    u8 pad0C[4];
} Root;

extern Root lbl_803003C8;

extern u8 lbl_8023BA14[];
extern void* lbl_8064C4E0;
extern void* lbl_8064C4E4;
extern void* lbl_8064C5B4;
extern s32 lbl_8064B4D8;
extern s32 lbl_8064C864;
extern s32 lbl_8064D18C;
extern s32 lbl_806518C0;
extern s32 lbl_806518C4;
extern s32 lbl_806518C8;

extern void* fn_80156DA0(s32, void*);
extern void fn_80043F44(Request*);
extern s32 fn_801E79FC(void*, s32);
extern void fn_801E7974(void*, s32);
extern void fn_801E79A0(void*, s32);
extern void fn_801399CC(s16);
extern void* fn_80034708(Request*);
extern void* fn_80201B54(void);
extern void fn_80201AEC(void*, void*);
extern void fn_80201AF8(void*);
extern void* fn_80201BC8(void*);
extern u32 fn_8011FAEC(void*);
extern void fn_8011FADC(void*, u32);
extern void fn_8011FE64(void*, void*);
extern void fn_801261F4(void*);
extern Vec3s* fn_80158ABC(s32, s32, float*);
extern void fn_8011F104(void*, float, float, float);
extern void fn_8012B7A0(void*, float);
extern void fn_8011FB54(void*, s32);
extern void fn_8012C62C(void*, s32, s32*, s32*, s32*, s32);
extern void fn_802015A4(void*);
extern void fn_801294DC(void*, s32, s32, s32);
extern void fn_800C3D24(void);
extern void fn_800C39D0(void*);
extern s32 fn_8004918C(void);
extern void fn_8004948C(void*, s32, s32);
extern void fn_801568C8(void*, void*, void*, void*);
extern void fn_80156904(void*, s32);
extern void fn_801568FC(void*, void*);
extern void fn_801568C0(void*, void*);
extern void fn_801568B8(void*, void*);
extern void fn_8015690C(void*, void*);
extern void fn_80156918(void*, void*);
extern s32 fn_800CF0C8(void*, s32, s32, s32, s32, s32, float, float);
extern s32 fn_800CF32C(void*, s32, s32, s32, float, float);
extern s32 fn_800CF220(void*, s32, s32, s32, s32, s32, float, float);
extern s32 fn_800CE914(void*, Point16*, Point16*, s32);
extern void fn_801E8328(s32, s32);
extern void fn_800CDD84(void*);
extern void* fn_80201B44(void);
extern void* fn_80158598(void*, s32);
extern void fn_80158668(void);
extern void fn_801586CC(void*, s32, void*, void*);
extern void fn_800CCA44(void*);

extern void fn_800C2180(void);
extern void fn_8002A508(void);
extern void fn_8002AC60(void);
extern void fn_800073E4(void);
extern void fn_8002A4C8(void);
extern void fn_800CBAB8(void);
extern void fn_800CBF40(void);

extern void fn_8011FA8C(void*, s32, s32);
extern s32 fn_8011EB04(void*);
extern void fn_801303F0(void*, s32, s32, float, float);
extern void fn_8013041C(void*, void*);
extern void fn_800C23D8(void);
extern void fn_801387E4(void);
extern void* fn_801D3974(s32);
extern void fn_8011FF0C(void**);
extern void fn_8011FF18(s32);
extern void* fn_801E86A0(void*, s32);
extern void fn_8011FF04(void*);
extern void fn_801B1A1C(s32, s32);
extern void fn_800E4648(void);
extern void fn_800E46A0(void);
extern void* fn_80138B90(const char*, s32, s32);
extern void fn_8015DAB0(void);
extern void* lbl_8064C528;
extern void* lbl_8064C53C;
extern void* lbl_8064C540;

typedef struct Pair {
    s32 count;
    s32 limit;
} Pair;

extern void fn_80134CAC(Pair*, s32);

void fn_80007F64(s32 mode);

static const Point16 lbl_8064DCC0 = { 200, 160 };
static const Point16 lbl_8064DCC4 = { -1, -56 };

void fn_8000755C(s32 arg0, s32 arg1, u32 flags)
{
    Request req;
    float ratio;
    Point16 a;
    Point16 b;
    s32 v0;
    s32 v1;
    s32 v2;
    void* obj;
    void* view;
    void* handle;
    u32 lowbit;
    s32 mode;
    s32 t1;
    s32 t4;
    s32 t6;
    s32 tmp;
    u32 attrs;

    obj = fn_80156DA0(3, lbl_8023BA14);
    if (obj == 0) {
        return;
    }

    a = lbl_8064DCC0;
    b = lbl_8064DCC4;
    fn_80043F44(&req);

    req.f10 = arg1;
    req.f14 = arg0;
    mode = lbl_803003C8.mode;
    req.f1C = 0;

    switch (mode) {
    case 0:
        if (fn_801E79FC(lbl_8064C4E0, 0x37E) != 0) {
            if (lbl_8064D18C == 0x64) {
                fn_801E7974(lbl_8064C4E0, 0x1F5);
                fn_801E7974(lbl_8064C4E0, 0x1F6);
                fn_801E7974(lbl_8064C4E0, 0x3DF);
                fn_801E7974(lbl_8064C4E0, 0x3E0);
                fn_801E7974(lbl_8064C4E0, 0x3B);
                fn_801E7974(lbl_8064C4E0, 0x3D);
                fn_801E7974(lbl_8064C4E0, 0x3C);
                fn_801E7974(lbl_8064C4E0, 0x25C);
                fn_801E7974(lbl_8064C4E0, 0x25B);
                fn_801E7974(lbl_8064C4E0, 0x133);
                fn_801E7974(lbl_8064C4E0, 0xAA);
                fn_801E7974(lbl_8064C4E0, 0xA9);
                fn_801E7974(lbl_8064C4E0, 0x25E);
                fn_801E7974(lbl_8064C4E0, 0x1F3);
                fn_801E7974(lbl_8064C4E0, 0x1F4);
                fn_801E7974(lbl_8064C4E0, 0x3DD);
                fn_801E7974(lbl_8064C4E0, 0x3DE);
                fn_801E7974(lbl_8064C4E0, 0x10A);
                fn_801E7974(lbl_8064C4E0, 0x258);
                fn_801E7974(lbl_8064C4E0, 0x25A);
                fn_801E7974(lbl_8064C4E0, 0x259);
                fn_801E7974(lbl_8064C4E0, 0x257);
                fn_801E7974(lbl_8064C4E0, 0x2CD);
                fn_801E7974(lbl_8064C4E0, 0x2CC);
                fn_801E7974(lbl_8064C4E0, 0x360);
                fn_801E7974(lbl_8064C4E0, 0x2B6);
                req.f1C = 0x914;
            } else {
                req.f1C = 0x4BB;
            }
        } else {
            req.f1C = 0x4BB;
        }
        break;
    case 1:
        req.f1C = 0x4B0;
        break;
    case 4:
        req.f1C = 0x4B3;
        break;
    case 5:
        req.f1C = 0x4B4;
        break;
    case 9:
        if (fn_801E79FC(lbl_8064C4E0, 0x37E) != 0) {
            if (lbl_8064D18C == 0x117) {
                req.f1C = 0x8EB;
            } else {
                req.f1C = 0x4B8;
            }
        } else {
            req.f1C = 0x4B8;
        }
        break;
    case 2:
        req.f1C = 0x4B1;
        break;
    case 7:
        req.f1C = 0x4B6;
        break;
    case 6:
        req.f1C = 0x4B5;
        break;
    case 10:
        if (fn_801E79FC(lbl_8064C4E0, 0x37E) != 0) {
            if (lbl_8064D18C == 0x4F) {
                req.f1C = 0x99D;
            } else {
                req.f1C = 0x4B9;
            }
        } else {
            req.f1C = 0x4B9;
        }
        break;
    case 8:
        req.f1C = 0x4B7;
        break;
    case 3:
        req.f1C = 0x4B2;
        break;
    case 11:
        req.f1C = 0x4BA;
        break;
    case 13:
        if (fn_801E79FC(lbl_8064C4E0, 0x37E) != 0) {
            req.f1C = 0x8EC;
        }
        break;
    case 16:
        req.f1C = 0x777;
        break;
    default:
        req.f1C = 0;
        break;
    }

    fn_801E79A0(lbl_8064C4E0, 0x37E);

    lowbit = flags & 1;
    if (lowbit != 0) {
        req.f1C = 0;
    }

    req.f28 = 2;
    fn_801399CC((s16)req.f14);
    view = fn_80034708(&req);

    handle = fn_80201B54();
    fn_80201AEC(handle, view);
    fn_80201AF8(handle);

    handle = fn_80201BC8(view);
    attrs = fn_8011FAEC(handle);
    fn_8011FADC(handle, attrs | 0xC0);
    fn_8011FE64(handle, (void*)fn_800C2180);
    fn_801261F4(handle);

    if ((flags & 2) == 0) {
        Vec3s* pos = fn_80158ABC(-2, 2, &ratio);

        if (pos != 0) {
            fn_8011F104(handle, pos->x, pos->y, pos->z);
            fn_8012B7A0(handle, ratio);
            fn_8011FB54(handle, lbl_8064D18C);
            fn_8011FADC(handle, fn_8011FAEC(handle));
        }

        if (lbl_803003C8.mode == 1 || lbl_803003C8.mode == 4) {
            v2 = lbl_806518C8;
            v1 = lbl_806518C4;
            v0 = lbl_806518C0;
            fn_8012C62C(handle, 15, &v0, &v1, &v2, 4);
        }
    }

    fn_802015A4(view);
    lbl_8064C4E4 = handle;
    lbl_8064C5B4 = obj;
    lbl_8064B4D8 = 0;
    fn_801294DC(handle, 15, 0x21, 1);
    fn_800C3D24();
    lbl_8064C864 = 0;
    fn_800C39D0(view);
    tmp = fn_8004918C();
    fn_8004948C(view, tmp, 0);

    fn_801568C8(obj, (void*)fn_8002A508, (void*)fn_8002AC60, (void*)fn_800073E4);
    fn_80156904(obj, 0);
    fn_801568FC(obj, (void*)fn_800073E4);
    fn_801568C0(obj, (void*)fn_8002A508);
    fn_801568B8(obj, (void*)fn_8002AC60);
    fn_8015690C(obj, (void*)fn_8002A4C8);
    fn_80156918(obj, view);

    t1 = fn_800CF0C8(view, 0x19, 0x118, 0, 0, 0x1F4, 1.0f, 1.0f);
    fn_801E8328(7, t1);
    fn_801E8328(7, fn_800CF0C8(view, 0x19, 0x28, 0, 1, 0x1F4, 1.0f, 1.0f));
    fn_801E8328(7, fn_800CF0C8(view, 0x3C, 0xB0, 0, 2, 0x1F4, 1.0f, 1.0f));
    t4 = fn_800CF32C(view, 0x1F4, 0x19F, 0xFF, 1.0f, 1.0f);
    fn_801E8328(9, t4);
    fn_801E8328(7, fn_800CF220(view, 0x21A, 0x168, 0, 7, 0x1F4, 1.0f, 1.0f));
    t6 = fn_800CE914(view, &a, &b, 5);
    fn_801E8328(0xB, t6);

    fn_800CDD84(view);
    fn_80158598(fn_80201B44(), 1);
    fn_80158668();
    fn_801586CC(fn_80158598(fn_80201B44(), 1), 6, (void*)fn_800CBAB8,
                (void*)fn_800CBF40);

    if (lowbit == 0) {
        fn_800CCA44(view);
    }
}

void fn_80007C48(void* obj)
{
    if (fn_8011EB04(obj) == 9) {
        fn_8011FA8C(obj, 0, 0x80000000);
        fn_801303F0(obj, 1, 0, 0.013089969754219055f, 0.19634954631328583f);
        fn_801303F0(obj, 0, 1, 0.01745329238474369f, 0.8726646304130554f);
    } else {
        fn_801303F0(obj, 1, 0, 0.013089969754219055f, 0.19634954631328583f);
        fn_801303F0(obj, 0, 1, 0.01745329238474369f, 0.8726646304130554f);
    }

    fn_8013041C(obj, (void*)fn_800C23D8);
}

s32 fn_80007D00(s32 mode)
{
    switch (mode) {
    case 0:
        return 9;
    case 1:
        return 0;
    case 4:
        return 0x96;
    case 5:
        return 0x12;
    case 9:
        return 0x45;
    case 2:
        return 0x46;
    case 7:
        return 0x4A;
    case 6:
        return 0x49;
    case 10:
        return 0x4B;
    case 8:
        return 0x4C;
    case 3:
        return 0x55;
    case 11:
        return 0x51;
    case 13:
        return 9;
    case 15:
        return 0x4B;
    case 16:
        return 9;
    }
    return 9;
}

s32 fn_80007DA0(s32 mode)
{
    switch (mode) {
    case 0:
        return 0x1A;
    case 1:
        return 1;
    case 2:
        return 0x31;
    case 3:
        return 0x2E;
    case 4:
        return 0x1B;
    case 5:
        return 0x2C;
    case 6:
        return 0x37;
    case 7:
        return 0x2F;
    case 8:
        return 0x36;
    case 9:
        return 0x35;
    case 10:
        return 0x2D;
    case 11:
        return 0x30;
    case 13:
        return 0x1A;
    case 15:
        return 0x2D;
    case 16:
        return 0x1A;
    }
    return mode;
}

s32 fn_80007E38(s32 mode)
{
    switch (mode) {
    case 0:
    case 13:
    case 16:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    case 6:
        return 6;
    case 7:
        return 7;
    case 8:
        return 8;
    case 9:
        return 9;
    case 10:
    case 15:
        return 0xA;
    case 11:
        return 0xB;
    }
    return 0;
}

void fn_80007EC0(s32 arg0, s32 arg1, u32 flags)
{
    void* handle;

    fn_801387E4();
    fn_80007F64(lbl_803003C8.mode);
    handle = fn_801D3974(3);
    fn_8011FF0C(&handle);
    fn_8011FF18(0x96);
    fn_8011FF04(fn_801E86A0(lbl_8064C528, 0x68));
    fn_8000755C(arg0, arg1, flags);
    fn_801B1A1C(lbl_803003C8.mode, 0x1E);
}

static Pair lbl_8023BDE0[7] = {
    { 9, 0x1F40 },  { 7, 0x3E80 },  { 6, 0x7D00 },  { 9, 0x13880 },
    { 3, 0x249F0 }, { 1, 0x30D40 }, { 1, 0x4E200 },
};

static Pair lbl_8023BE18[7] = {
    { 9, 0x1F40 },  { 7, 0x3E80 },  { 6, 0x7D00 },  { 9, 0x13880 },
    { 3, 0x249F0 }, { 1, 0x30D40 }, { 1, 0x493E0 },
};

void fn_80007F64(s32 mode)
{
    switch (mode) {
    case 7:
        fn_800E4648();
        break;
    case 9:
        lbl_8064C53C = fn_80138B90("/chars/zomser.tpl", 0, 0);
        fn_8015DAB0();
        lbl_8064C540 = fn_80138B90("/chars/zomserf.tpl", 0, 0);
        fn_8015DAB0();
        fn_800E4648();
        break;
    case 10:
        fn_800E46A0();
        break;
    case 13:
        fn_80134CAC(lbl_8023BDE0, 7);
        break;
    case 15:
        fn_80134CAC(lbl_8023BE18, 7);
        break;
    case 0:
    case 16:
        break;
    }
}
