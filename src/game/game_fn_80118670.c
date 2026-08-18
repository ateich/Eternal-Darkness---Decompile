extern void *fn_8015C28C(int);
extern int fn_80201B44();
extern void *fn_80201814();
extern void *fn_80201BC8();
extern unsigned int lbl_8064D18C;
extern unsigned char lbl_80332158[];
extern int lbl_8064CD70;

extern unsigned int fn_801F6794(void *);
extern unsigned int fn_8012BB34(void *);
extern unsigned int fn_801E9068(void *);
extern void fn_801A8070(void *);
extern void *fn_80049220(void *, int);
extern void *fn_80049304(void *, void *);
extern void fn_8007D69C(void *);
extern void *fn_8011FCE4(void);
extern void fn_8011FC38(void *, void *, int);
extern void* fn_80201C24();
extern int fn_801579EC(void);

void fn_80118670(void)
{
    void *object;
    void *owner;
    void *item;

    object = fn_8015C28C(2);
    fn_80201B44();
    owner = fn_80201814();
    fn_80201BC8();

    if (*(unsigned int *)lbl_80332158 == lbl_8064D18C) {
        if (object != 0 && ((signed char *)object)[0x8143] != 0 &&
            ((signed char *)object)[0x8142] != 0) {
            unsigned int offset;
            unsigned char *resource;

            resource = *(unsigned char **)((unsigned char *)object + 0x128 +
                       (*(unsigned int *)(lbl_80332158 + 4) * 4));
            offset = fn_801F6794(resource);
            offset += fn_8012BB34(resource + (unsigned short)offset);
            offset += fn_801E9068(resource + (unsigned short)offset);
            offset += *(unsigned short *)(lbl_80332158 + 0x166);
            fn_801A8070(resource + (unsigned short)offset);
        }

        item = fn_80049220(owner, 1);
        object = fn_80049304(owner, item);
        if (lbl_8064CD70 != 0) {
            fn_8007D69C(owner);
        } else if (object != 0) {
            void *state = fn_80201BC8();
            item = fn_8011FCE4();
            fn_8011FC38(state, item, 1);
            fn_80201C24(object);
            if (fn_801579EC() != 0) {
                object = fn_80049220(owner, 0);
                fn_80049304(owner, object);
                fn_8011FC38(fn_80201BC8(), item, 1);
            }
        }
    }
}
