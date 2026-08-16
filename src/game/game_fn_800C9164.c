typedef struct OwnerList {
    void *first;
} OwnerList;

typedef struct Component {
    unsigned char pad[0x6C];
    OwnerList *owners;
} Component;

#pragma use_lmw_stmw on

extern void *fn_80201B9C();
extern int fn_80201EB8(void *);
extern int fn_80201B54();
extern Component *fn_80201B8C();
extern void fn_801A764C(void *, void *);
extern int fn_800C8568(void *, void *, void *, void *, void *, void *, void *);

int fn_800C9164(void *object, void *target, void *position, void *radius,
                void *kind, void **extra)
{
    OwnerList *owners;
    void *extra_copy;

    fn_80201B9C(object);
    fn_80201EB8(object);
    fn_80201B54(object);
    owners = fn_80201B8C(object)->owners;
    fn_801A764C(owners->first, target);
    extra_copy = *extra;
    fn_800C8568(object, owners->first, target, position, radius, kind, &extra_copy);
    return 1;
}
