typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Coord2List { u32 count; void* entries; } Coord2List;
typedef struct RegionEntry { u8 pad_00[0x30]; u8 data[0x44]; } RegionEntry;

extern char lbl_80251528[];
extern u8 lbl_802FC5BC[];
extern void fn_80179B08(void*, Vec3*);
extern void fn_80179E08(Vec3*, void*);
extern void fn_80179D38(Vec3*, float, const Coord2List*, u32, const Vec3*, u8);
extern void fn_800EBA80(int, Vec3*, u32*, int, float);
extern void fn_800EBBF4(Vec3*, Vec3*, u32*, int);
extern void fn_800EB750(Vec3*, Vec3*, u32*, int);
extern void fn_800ED4BC(Vec3*, int, const char*, ...);

void fn_801A7958(RegionEntry* entry, u16 count)
{
    char* strings = lbl_80251528;
    u8* globals = lbl_802FC5BC;
    u16 i;
    Vec3 vertices[4];
    Vec3 position;
    Vec3 second;
    Vec3 first;
    Vec3 first_plane;
    Vec3 second_plane;
    u32 sphere_color;
    u32 box_color;
    u32 first_color;
    u32 second_color;
    int j;
    for (i = 0; i < count; i++, entry++) {
        int index = i;
        int remainder = index % 19;
        u8* data = entry->data;
        switch (*(s16*)(entry->data + 0x3C)) {
        case 0:
            fn_80179B08((u8*)data + 4, &position);
            sphere_color = *(u32*)(globals + 0x2C);
            fn_800EBA80(1, &position, &sphere_color, 0x78, (float)*(u32*)data);
            fn_800ED4BC(&position, remainder, strings, index);
            break;
        case 1:
            fn_80179E08(&first, data);
            fn_80179E08(&second, (u8*)data + 6);
            box_color = *(u32*)(globals + 0x2C);
            fn_800EBBF4(&first, &second, &box_color, 0x78);
            fn_800ED4BC(&first, remainder, strings + 0x10, index,
                        *(s16*)(data + 0xC), *(s16*)(data + 0xE));
            break;
        case 2:
            for (j = 0; j < 4; j++) {
                fn_80179D38(&vertices[j], *(float*)(data + 0x2C),
                            (Coord2List*)data, j, (Vec3*)(data + 0x10), data[0x28]);
            }
            first_color = *(u32*)(globals + 0x10);
            first_plane = *(Vec3*)(data + 0x10);
            fn_800EB750(vertices, &first_plane, &first_color, 0x78);
            for (j = 0; j < 4; j++) {
                fn_80179D38(&vertices[j], *(float*)(data + 0x30),
                            (Coord2List*)(data + 8), j, (Vec3*)(data + 0x1C), data[0x29]);
            }
            second_color = *(u32*)(globals + 0x28);
            second_plane = *(Vec3*)(data + 0x1C);
            fn_800EB750(vertices, &second_plane, &second_color, 0x78);
            fn_800ED4BC(vertices, remainder, strings + 0x2C, index);
            break;
        }
    }
}
