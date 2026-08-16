typedef unsigned int u32;
typedef struct Vec3 { u32 x, y, z; } Vec3;

extern const Vec3 lbl_80248AE4;
extern void *fn_80201B94(void *);
extern int fn_80201C48(void *);
extern int fn_80201B54(void *);
extern void fn_80201DD8(void *, int);
extern void fn_8011F114(Vec3 *, void *);
extern void fn_8012B690(void *, const Vec3 *, Vec3 *);
extern void fn_80211A48(Vec3 *, Vec3 *, Vec3 *);
extern void fn_8020123C(int, int, int, void *);

int fn_800D3620(void *state, void *object)
{
    void *resource = fn_80201B94(object);
    int value = fn_80201C48(resource);
    int id = fn_80201B54(object);
    Vec3 first;
    Vec3 second;

    fn_80201DD8(resource, 0);
    fn_8011F114(&first, state);
    fn_8012B690(state, &lbl_80248AE4, &second);
    fn_80211A48(&first, &second, &second);
    fn_8020123C(157, id, value, &second);
    fn_8020123C(160, id, value, 0);
    return 1;
}
