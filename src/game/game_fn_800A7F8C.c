typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void* fn_801A717C(void);
extern void* fn_80201B44(void);
extern void fn_801A74A0(void*, void*);
extern void fn_801A74A8(void*, void*);
extern void fn_801A7538(void*, int);
extern void fn_801A7518(void*, int);
extern void fn_801A7470(void*, int);
extern void fn_801A764C(void*, Vec3*);
extern void fn_8020123C(int, void*, void*, void*);
extern void fn_801A7228(void*);

void fn_800A7F8C(void* object, Vec3* position, int kind)
{
    void* effect = fn_801A717C();
    void* owner = fn_80201B44();

    fn_801A74A0(effect, object);
    fn_801A74A8(effect, owner);
    fn_801A7538(effect, 2);
    fn_801A7518(effect, kind);
    fn_801A7470(effect, -1);
    fn_801A764C(effect, position);
    fn_8020123C(0x27, object, owner, effect);
    fn_801A7228(effect);
}
