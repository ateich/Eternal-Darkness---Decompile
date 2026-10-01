typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Entry {
    void* object; u32 id; u32 field_8; void* link; void* resource;
    Vec3 position; u32 field_20; u8 field_24, field_25, flags, field_27;
} Entry;
typedef struct Manager { char pad_0[5]; u8 count; u8 range; char pad_7[9]; Entry* entries; } Manager;
typedef struct CandidateResource { u32 field_0; u32 id; } CandidateResource;
typedef struct Candidate {
    Vec3 position; char pad_C[0x30]; CandidateResource* resource;
    char pad_40[0x204]; int type; char pad_248[0xC]; int flags;
    char pad_258[0x78]; u16 flags_2D0;
} Candidate;

extern u8 lbl_8030F540[];
extern const float lbl_80650248;
extern void* fn_80201B9C(void);
extern void* fn_80201BC0(void*);
extern Candidate* fn_80201BC8(void*);
extern void fn_80201B54(void*);
extern void fn_80046C98(int);
extern void* fn_80155DB4(void*);
extern u32 fn_80178F14(int, int, int, int, int, int);
extern void fn_8011F7E0(Candidate*, int);
extern void* fn_80156928(void*);
extern void* fn_80205288(void*);
extern void fn_8012C478(void*, int, int);
extern void fn_801568C0(void*, int);
extern void fn_8012C198(void*);
extern void fn_8011FABC(Candidate*, int, int);
extern void fn_8011F114(Vec3*, void*);
extern void fn_8012B7A0(void*, float);

#define ENTRY_AT(manager, offset) ((Entry*)((char*)(manager)->entries + (offset)))

void fn_80133510(Manager* manager)
{
    int ez;
    int ey;
    int ex;
    int offset;
    void* iterator;
    int i;
    void* selected;
    u32 best;

    if (manager == 0) return;

    best = -1;

    i = 0;
    offset = 0;
    while (i < manager->count) {
        Entry entry = *ENTRY_AT(manager, offset);
        if (ENTRY_AT(manager, offset)->object == 0) {
            u32 entry_id = entry.id;
            u32 distance;

            iterator = fn_80201B9C();
            selected = 0;
            ez = (int)entry.position.z;
            ey = (int)entry.position.y;
            ex = (int)entry.position.x;

            while (iterator != 0) {
                Candidate* candidate = fn_80201BC8(iterator);
                if (candidate != 0 && candidate->resource != 0) {
                    u8 mode = lbl_8030F540[0x1DA];
                    if (mode == 0x82) {
                        fn_80046C98(1);
                        if (candidate->resource->id == entry_id &&
                            (candidate->flags & 0x8000) == 0) {
                            fn_80155DB4(iterator);
                            distance = fn_80178F14((int)candidate->position.x,
                                (int)candidate->position.y, (int)candidate->position.z,
                                ex, ey, ez);
                            if (distance < best || (best = -1)) {
                                best = distance;
                                selected = iterator;
                            }
                        }
                    } else if (mode == 0x86 || mode == 0x8F ||
                               mode == 0xAB || mode == 0xAC) {
                        if (candidate->resource->id == entry_id &&
                            (candidate->flags & 0x8000) == 0) {
                            fn_80155DB4(iterator);
                            distance = fn_80178F14((int)candidate->position.x,
                                (int)candidate->position.y, (int)candidate->position.z,
                                ex, ey, ez);
                            if (distance < best || (best = -1)) {
                                best = distance;
                                selected = iterator;
                            }
                        }
                    } else if (candidate->resource->id == entry_id &&
                               (candidate->flags & 0x8000) == 0 &&
                               candidate->type > 0x23 &&
                               candidate->type <= manager->range + 0x23) {
                        fn_80155DB4(iterator);
                        distance = fn_80178F14((int)candidate->position.x,
                                              (int)candidate->position.y,
                                              (int)candidate->position.z,
                                              ex, ey, ez);
                        if (distance < best || (best = -1)) {
                            best = distance;
                            selected = iterator;
                        }
                    }
                    fn_8011F7E0(candidate, 0);
                }
                iterator = fn_80201BC0(iterator);
            }

            if (selected != 0) {
                fn_80201B54(selected);
                fn_80201BC8(selected);
                if (fn_80155DB4(selected) == 0) selected = 0;
            }
            if (selected != 0) {
                Candidate* candidate;
                void* resource;
                void* linked_object;
                void* linked;
                fn_80201B54(selected);
                candidate = fn_80201BC8(selected);
                resource = fn_80155DB4(selected);
                ENTRY_AT(manager, offset)->object = candidate;
                ENTRY_AT(manager, offset)->resource = resource;
                best = distance;
                ENTRY_AT(manager, offset)->link = fn_80156928(resource);
                linked = fn_80205288(selected);
                linked_object = 0;
                if (linked != 0) linked_object = fn_80201BC8(linked);
                if (linked_object != 0) fn_8012C478(linked_object, 0xF, 0);
                fn_801568C0(resource, 0);
                fn_8012C198(ENTRY_AT(manager, offset)->object);
                fn_8012C478(ENTRY_AT(manager, offset)->object,
                            0xF, 1);
                candidate->flags |= 0x8000;
                if (ENTRY_AT(manager, offset)->flags & 1)
                    candidate->flags |= 0x04000000;
                if (ENTRY_AT(manager, offset)->flags & 2)
                    fn_8011FABC(candidate, 0, 0x1000);
                if (ENTRY_AT(manager, offset)->flags & 4) {
                    candidate->flags &= ~0x100;
                } else {
                    candidate->flags |= 0x100;
                    candidate->flags_2D0 |= 0x2000;
                }
            }
        }
        offset += 0x28;
        i++;
    }

    for (i = 0; i < manager->count; i++) {
        if (manager->entries[i].object != 0) {
            Vec3 position;
            fn_8011F114(&position, manager->entries[i].object);
            manager->entries[i].position = position;
            fn_8012B7A0(manager->entries[i].object, lbl_80650248);
        }
    }
}
