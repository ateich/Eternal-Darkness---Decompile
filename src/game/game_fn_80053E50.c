typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

#pragma use_lmw_stmw on

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Request {
    Vec3 position;
    float scale;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    s32 f30;
    s16 f34;
    u8 pad36[2];
} Request;

extern u8 lbl_80243A2C[];
extern u8 lbl_8030F740[];
extern void fn_8002A4C8(void);
extern void fn_80043F44(Request*);
extern s32 fn_8007255C(s32, void*);
extern void* fn_80054040(void*, void*, Request*);
extern void *fn_80201BC8();
extern unsigned int fn_8011FAEC(void);
extern void fn_8012B7A0(void*, float);
extern void fn_8011EAF4(void*, s32);
extern void fn_80201D54(void*, s32);
extern void* fn_80156DA0(s32, void*);
extern void fn_80156904(void*, s32);
extern void fn_801568FC(void*, void*);
extern void fn_8015690C(void*, void*);
extern void fn_80156918(void*, void*);

s32 fn_80053E50(s32 f10, s32 f14, s32 f2C, s32 f18, s32 f1C, s32 f20,
                 s32 f24, s32 f28, float scale, Vec3* position, s32 f30)
{
    Request req;
    void* object;
    void* view;

    fn_80043F44(&req);
    req.f10 = f10;
    req.f14 = f14;
    req.f2C = f2C == -1 ? req.f2C : f2C;
    req.f18 = f18 == -1 ? req.f18 : f18;
    req.f1C = f1C == -1 ? req.f1C : f1C;
    req.f20 = f20 == -1 ? req.f20 : f20;
    req.f24 = f24 == -1 ? req.f24 : f24;
    req.f28 = f28 == -1 ? req.f28 : f28;
    req.scale = scale;
    req.f30 = f30 == -1 ? req.f30 : f30;
    req.position.x = position->x;
    req.position.y = position->y;
    req.position.z = position->z;
    req.f34 = 0;

    if (fn_8007255C(req.f10, lbl_8030F740) != 0) {
        object = fn_80054040(lbl_80243A2C, lbl_8030F740, &req);
        if (object != 0) {
            view = fn_80201BC8();
            if (view != 0) {
                fn_8011FAEC();
                fn_8012B7A0(view, req.scale);
                fn_8011EAF4(view, f14);
            }
            fn_80201D54(object, req.f2C);
            view = fn_80156DA0(3, &req);
            if (view != 0) {
                fn_80156904(view, 0);
                fn_801568FC(view, 0);
                fn_8015690C(view, fn_8002A4C8);
                fn_80156918(view, object);
            }
        }
    }
    return 1;
}
