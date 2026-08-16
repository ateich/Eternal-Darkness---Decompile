typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Owner {
    u8 pad_00[0x64];
    void *value;
    u8 pad_68[0x1E];
    u16 kind;
} Owner;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern void *fn_80201A84(void *);
extern void fn_800D04A4(Vec3 *, void *);
extern void *fn_80155330(int, void *, int, int, Vec3 *, int);

void fn_800CFFFC(void *object, Owner *owner)
{
    int create = 1;
    int type = 0;
    int arg3 = 0;
    void *value = fn_80201A84(object);
    Vec3 *position = 0;
    int lifetime = 0;
    Vec3 local_position;

    switch (owner->kind) {
    case 3:
        create = 0;
        break;
    case 0:
        type = 1;
        break;
    case 1:
        type = 2;
        break;
    case 2:
        fn_800D04A4(&local_position, object);
        position = &local_position;
        lifetime = 250;
        type = 3;
        arg3 = 14;
        break;
    }

    if (create != 0) {
        owner->value = fn_80155330(type, value, 1, arg3, position, lifetime);
    }
}
