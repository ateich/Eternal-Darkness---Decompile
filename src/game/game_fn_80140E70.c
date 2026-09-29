typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct DebugMeshPart {
    u16 count;
    u16 pad;
    u16* indices;
} DebugMeshPart;

typedef struct DebugMesh {
    u8 pad0[0x14];
    float offset[3];
    u8 pad20[8];
    u16 count;
    u16 pad2a;
    u16* indices;
    s8 part_count;
    u8 pad31[3];
    DebugMeshPart* parts;
} DebugMesh;

extern u32 lbl_802FC5BC[];
extern const float lbl_80650400;
extern const float lbl_80650404;
extern void fn_801ECD74(const u32*);
extern void fn_80226AB4(int, int, u16);
extern void fn_801409AC(float, float, float);
extern void fn_801409A8(void);

/* Keep the caller's packed color separate from the callee's argument copy. */
static inline void set_color(u32 rgba)
{
    fn_801ECD74(&rgba);
}

static inline void emit_point(const s16* points, u16 index, const DebugMesh* mesh)
{
    const s16* p = points + index * 3;
    fn_801409AC(mesh->offset[0] + p[0],
                mesh->offset[1] + p[1],
                mesh->offset[2] + p[2]);
}

/* Draw a debug mesh as its outline, face normals, and optional sub-parts. */
void fn_80140E70(const s16* points, DebugMesh* mesh, u8 color, int part_color, u8 alpha)
{
    u32 rgba;
    u16 i;
    u16 first;
    s8 part;
    float x, y, z;
    const s16* first_point;
    u16* indices = mesh->indices;
    DebugMeshPart* selected_part = 0;
    first = indices[(u16)(mesh->count - 1)];
    rgba = lbl_802FC5BC[color];
    x = mesh->offset[0] + points[first * 3];
    first_point = points + first * 3;
    y = mesh->offset[1] + first_point[1];
    z = mesh->offset[2] + first_point[2];
    ((u8*)&rgba)[3] = alpha;
    set_color(rgba);

    fn_80226AB4(0xB0, 3, mesh->count + 1);
    fn_801409AC(x, y, z);
    for (i = 0; i < mesh->count; i++)
        emit_point(points, indices[i], mesh);
    fn_801409A8();

    rgba = lbl_802FC5BC[3];
    ((u8*)&rgba)[3] = 0xFF;
    set_color(rgba);
    fn_80226AB4(0xA8, 3, (u16)(mesh->count * 2));
    {
        for (i = 0; i < mesh->count; i++) {
            const s16* p = points + indices[i] * 3;
            x = p[0];
            y = p[1];
            z = p[2];
            fn_801409AC(x, y, z);
            fn_801409AC(x + lbl_80650400 * mesh->offset[0],
                        y + lbl_80650400 * mesh->offset[1],
                        z + lbl_80650400 * mesh->offset[2]);
        }
    }
    fn_801409A8();

    if (mesh->part_count == 0)
        return;
    rgba = lbl_802FC5BC[(u8)part_color];
    ((u8*)&rgba)[3] = alpha;
    set_color(rgba);
    for (part = 0; part < mesh->part_count; part++) {
        DebugMeshPart* p = &mesh->parts[part];
        selected_part = p;
        indices = p->indices;
        first = indices[(u16)(p->count - 1)];
        first_point = points + first * 3;
        x = mesh->offset[0] + first_point[0];
        y = mesh->offset[1] + first_point[1];
        z = mesh->offset[2] + first_point[2];
        fn_80226AB4(0xB0, 3, p->count + 1);
        fn_801409AC(x, y, z);
        for (i = 0; i < p->count; i++)
            emit_point(points, indices[i], mesh);
        fn_801409A8();
    }

    rgba = lbl_802FC5BC[(u8)part_color];
    ((u8*)&rgba)[3] = alpha;
    set_color(rgba);
    {
        /* Retail retains the last selected part here: it repeats that count
         * for every part rather than summing the individual part counts. */
        u16 total = 0;
        for (part = 0; part < mesh->part_count; part++)
            total += selected_part->count;
        fn_80226AB4(0xA8, 3, (u16)(total * 2));
    }
    {
        for (part = 0; part < mesh->part_count; part++) {
            DebugMeshPart* p = &mesh->parts[part];
            indices = p->indices;
            for (i = 0; i < p->count; i++) {
                const s16* v = points + indices[i] * 3;
                x = v[0];
                y = v[1];
                z = v[2];
                fn_801409AC(x, y, z);
                fn_801409AC(x + lbl_80650404 * mesh->offset[0],
                            y + lbl_80650404 * mesh->offset[1],
                            z + lbl_80650404 * mesh->offset[2]);
            }
        }
    }
    fn_801409A8();
}
