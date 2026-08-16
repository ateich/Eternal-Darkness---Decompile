typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern int lbl_8064D18C;
extern void fn_80201E78(Vec3 *, void *);
extern void *fn_80201B9C(void);
extern int fn_80201B4C(void *);
extern int fn_80201EB8(void *);
extern int fn_80036DF0(void *);
extern unsigned int fn_80179004(Vec3 *, Vec3 *);
extern void fn_800E19CC(void *);
extern void *fn_80201BC0(void *);

void fn_800E1DB0(void *object)
{
    Vec3 object_position;
    Vec3 item_position;
    void *item;

    fn_80201E78(&object_position, object);
    item = fn_80201B9C();
    while (item != 0) {
        if (fn_80201B4C(item) == 1) {
            int environment = fn_80201EB8(item);
            if (environment == lbl_8064D18C) {
                if (fn_80036DF0(item) != 0) {
                    fn_80201E78(&item_position, item);
                    if (fn_80179004(&object_position, &item_position) <= 200) {
                        fn_800E19CC(object);
                    }
                }
            }
        }
        item = fn_80201BC0(item);
    }
}
