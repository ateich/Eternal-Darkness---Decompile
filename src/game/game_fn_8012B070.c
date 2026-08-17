typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec8012B070 {
    float x, y, z;
} Vec8012B070;

typedef struct State8012B070 {
    void (*callbacks[14])(void*, void*);
    void* callback_args[14];
    u8 pad70[0x48];
    void* resource;
    float angle;
    u8 padC4[8];
    Vec8012B070 transform;
    Vec8012B070 position;
    u8 padE4[0xC];
    void* resource_id;
    u32 flags;
    u16 attributes;
    u16 state;
} State8012B070;

extern State8012B070* fn_80128E30(void*);
extern int fn_8012B018(void*, int*);
extern void fn_80128C50(State8012B070*);
extern void fn_80211A6C(const Vec8012B070*, const void*, Vec8012B070*);
extern float fn_800490E8(float, float);
extern void* fn_8012A13C(void*, void*);
extern void fn_80129DE0(void*, State8012B070*, int, int);
extern void* fn_8011FE54(void*);
extern void fn_8012965C(void*, void*, int, int);
extern float lbl_806501BC;

int fn_8012B070(u8* owner)
{
    State8012B070* current;
    State8012B070* next;
    int index;
    int i;
    Vec8012B070 local;

    current = fn_80128E30(owner);
    if (current->state != 8 && current->resource != 0) {
        return 0;
    }
    if (fn_8012B018(owner, &index)) {
        *(u16*)(*(u8**)(owner + 0x40) + 0x880) = index;
        current = fn_80128E30(owner);
        if (current->flags & 0x80) {
            for (i = 0; i < 14; i++) {
                if (current->callbacks[i] != 0) {
                    current->callbacks[i](owner, current->callback_args[i]);
                }
            }
            current->state = 8;
            fn_8012B070(owner);
        } else {
            next = fn_80128E30(owner);
            if (next->attributes & 1) {
                next->position = *(Vec8012B070*)owner;
                fn_80211A6C(&next->transform, owner, &local);
                next->angle = lbl_806501BC + fn_800490E8(local.y, local.x);
            }
            if (current->resource != 0) {
                *(u8*)(*(u8**)(owner + 0x40) + 0x884) = *((u8*)current->resource + 0xD);
            }
            if (*(u32*)(owner + 0x254) & 0x1000) {
                next->resource = fn_8012A13C(owner, next->resource_id);
            }
            if (!(next->attributes & 1) || !(current->attributes & 1) ||
                current->resource != next->resource) {
                fn_80129DE0(owner, next, !(next->flags & 0x20000), 1);
            }
        }
        fn_80128C50(current);
    } else {
        *(u16*)(*(u8**)(owner + 0x40) + 0x880) = 0;
        *(u16*)(*(u8**)(owner + 0x40) + 0x882) = 1;
        if (current->resource != 0) {
            *(u8*)(*(u8**)(owner + 0x40) + 0x884) = *((u8*)current->resource + 0xD);
        }
        if (*(void (**)(void*, int))(owner + 0x178) != 0) {
            (*(void (**)(void*, int))(owner + 0x178))(owner, 0);
        } else {
            fn_8012965C(owner, fn_8011FE54(owner), 0x21, 1);
        }
    }
    return 0;
}
