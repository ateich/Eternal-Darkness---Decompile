typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const float lbl_80650C1C;
extern const float lbl_80650C20;
extern const float lbl_80650C24;
extern const float lbl_80650C28;

extern void* fn_8015C2FC(int);
extern void fn_80179B08(void*, Vec3*);
extern void fn_80179A18(Vec3*);
extern void fn_8013F3C0(void*, Vec3*, Vec3*, float);
extern void* fn_8013FBE4(void*, void*, void*, int, int);
extern void fn_8013F760(Vec3*, void*, void*, float);
extern void fn_80178E94(Vec3*, Vec3*);

void fn_8019C26C(void* start_packed, void* direction_packed, void* extent_out,
                 Vec3* normal_out, Vec3* hit_out)
{
    void* world;
    void* hit;
    Vec3 end;
    Vec3 start;
    Vec3 direction;
    u32 contact[6];
    u32 shape[16];

    world = fn_8015C2FC(2);
    fn_80179B08(direction_packed, &direction);
    fn_80179B08(start_packed, &start);
    fn_80179A18(&direction);

    end.x = lbl_80650C1C * direction.x + start.x;
    end.y = lbl_80650C1C * direction.y + start.y;
    end.z = lbl_80650C1C * direction.z + start.z;
    fn_8013F3C0(shape, &start, &end, lbl_80650C20);
    hit = fn_8013FBE4(world, shape, contact, 0, 0);
    if (hit != 0) {
        *hit_out = *(Vec3*)contact;
        hit_out->z += lbl_80650C24;
        fn_8013F760(hit_out, hit, extent_out, lbl_80650C28);
        *normal_out = *(Vec3*)((char*)hit + 0x14);
    } else {
        *hit_out = end;
    }
    fn_80178E94(&start, hit_out);
}
