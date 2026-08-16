typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void *fn_80201B9C(void *);
extern int fn_80201B5C(void *);
extern int fn_80201EB8(void *);
extern int fn_80201B54(void *);
extern void fn_80201E78(Vec3 *, void *);
extern unsigned int fn_80179064(int, int, int, int);
extern void *fn_80201BC0(void *);

int fn_800E1C9C(void *object)
{
    int best_id = -1;
    void *item;
    unsigned int best_distance = 0xF423F;
    int object_id;

    item = fn_80201B9C(object);
    object_id = fn_80201B54(object);
    for (; item != 0; item = fn_80201BC0(item)) {
        if (fn_80201B5C(item) == 0x51 && fn_80201EB8(item) == fn_80201EB8(object)) {
            int item_id = fn_80201B54(item);
            if (object_id != item_id) {
                Vec3 object_position;
                Vec3 item_position;
                unsigned int distance;
                fn_80201E78(&object_position, object);
                fn_80201E78(&item_position, item);
                distance = fn_80179064((int)item_position.x, (int)item_position.y,
                                      (int)object_position.x, (int)object_position.y);
                if (distance < best_distance) {
                    best_id = item_id;
                    best_distance = distance;
                }
            }
        }
    }
    return best_id;
}
