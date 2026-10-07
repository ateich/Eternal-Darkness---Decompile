typedef unsigned int u32;

typedef struct Entry {
    unsigned char pad[0x1C];
    u32 flags;
} Entry;

extern void *fn_80201B9C(void);
extern void fn_80201EB8(void *object);
extern void *fn_80201B94(void *object);
extern int fn_80201B4C(void *object);
extern int fn_80201C58();
extern void *fn_80201BC8(void *object);
extern void *fn_8011F950(void *object);
extern int fn_8011EB04(void *object);
extern Entry *fn_8002A444(int kind, int value);
extern void fn_8012B9C8(void *owner, void *value);
extern void *fn_80201BC0(void *object);

void fn_80042A64(void)
{
    void *object;

    object = fn_80201B9C();
    while (object != 0) {
        void *link;
        int kind;

        fn_80201EB8(object);
        link = fn_80201B94(object);
        kind = fn_80201B4C(object);
        if ((kind == 2 || kind == 1) && (u32)fn_80201C58(link) != 0) {
            void *runtime = fn_80201BC8(object);
            void *owner = fn_8011F950(runtime);

            if (owner != 0) {
                Entry *entry = fn_8002A444(fn_8011EB04(runtime), kind);
                if (entry != 0 && (entry->flags & 1) != 0) {
                    entry->flags &= 0xFFFFFFFE;
                    fn_8012B9C8(owner, (void *)1);
                }
            }
        }
        object = fn_80201BC0(object);
    }
}
