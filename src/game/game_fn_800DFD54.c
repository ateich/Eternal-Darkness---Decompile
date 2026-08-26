typedef unsigned char u8;

typedef struct Payload {
    u8 bytes[4];
} Payload;

#pragma use_lmw_stmw on

extern int lbl_8064B80C;
extern int fn_80201B54();
extern int fn_8011FB4C(void *);
extern int fn_80200C38();
extern unsigned short fn_8012DBE8(void *, int, Payload *);
extern int fn_800DE298(void *);
extern void* fn_8012C62C(void *, int, Payload *, Payload *, Payload *, int);

void fn_800DFD54(int enabled, void *object, void *resource, void *event)
{
    Payload source;
    Payload first;
    Payload second = {{0, 0, 0, 0}};
    int type;
    int flag;

    fn_80201B54(object);
    type = fn_8011FB4C(resource);
    flag = event != 0 ? fn_80200C38(event) : 1;
    fn_8012DBE8(resource, 15, &source);
    first.bytes[0] = source.bytes[0];
    first.bytes[1] = source.bytes[1];
    first.bytes[2] = source.bytes[2];

    if (type == lbl_8064B80C && fn_800DE298(object) != 0) {
        if (flag != 0) {
            source.bytes[3] = 0xFB;
            second.bytes[3] = 5;
            fn_8012C62C(resource, 15, &source, &second, &first, 4);
        } else if (enabled != 0) {
            source.bytes[3] = 0;
            second.bytes[3] = (u8)-5;
            fn_8012C62C(resource, 15, &source, &second, &first, 4);
        }
    }
}
