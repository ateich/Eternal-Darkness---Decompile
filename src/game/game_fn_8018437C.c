typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SixBytes { u32 word; u16 half; } SixBytes;

extern u32 lbl_8064A80C;
extern SixBytes lbl_80651D28;
extern int fn_80180430(void*, u8);
extern int fn_80180454(void*);
extern void fn_80180518(void*, u8, int);
extern void fn_8017E1B0(void*, void*);
extern void* fn_80201B9C(void);
extern void* fn_80201BC0(void*);
extern int fn_80201B4C(void*);
extern void* fn_80201BC8(void*);
extern void* fn_80201B54(void*);
extern int fn_80201EB8(void*);
extern void fn_8011F114(void*, void*);
extern u16 fn_8011F760(void*);
extern float fn_8011F6F0(void*);
extern u32 fn_80179064(int, int, s16, s16);
extern int fn_8020123C(int, int, int, int);
extern void* fn_801A717C(void);
extern void fn_80179B08(void*, void*);
extern void fn_801A74A8(void*, void*);
extern void fn_801A7538(void*, int);
extern void fn_801A7518(void*, int);
extern void fn_801A7588(void*, int);
extern void fn_801A7470(void*, int);
extern void fn_801A764C(void*, void*);
extern void fn_801A7228(void*);
extern unsigned int fn_800FBFB0(void);
extern void* memcpy(void*, const void*, u32);
extern int fn_8018E26C(void*, void*);
extern void fn_8018E230(void*, void*, int, u8, u8, int);
extern void fn_8018A88C(void);

int fn_8018437C(u8* self)
{
    u8* timers = self + 0x8C;
    u8* entry = *(u8**)(self + 0x4C);
    u8 count = self[1];
    int i;

    if (*(u16*)(self + 0x92) == 0) {
        *(void**)(self + 0x148) = fn_8018A88C;
        for (i = 0; i < count; i++, entry += 0x38, timers += 2) {
            if (fn_80180430(self + 0x24, (u8)i)) {
                int mode = lbl_8064A80C & 0x1F;
                if (entry[0x21] < timers[1] && ((*(u16*)(self + 0xA) & 3) == 0))
                    entry[0x21] += timers[0];
                if (timers[4] != 2 || ((*(u16*)(self + 0xA) & 1) == 0))
                    fn_8017E1B0(entry + 0xA, entry + 0x10);
                if (timers[3] && mode == 0) {
                    void* node = fn_80201B9C();
                    while (node) {
                        int type = fn_80201EB8(node);
                        int state = fn_80201B4C(node);
                        if (type == (int)lbl_8064A80C && (state == 0 || state == 1)) {
                            void* object = fn_80201BC8(node);
                            float point[3];
                            u16 bound = fn_8011F760(object);
                            fn_8011F114(point, object);
                            if ((u32)fn_80179064(0, 0, *(s16*)(entry + 0xA), *(s16*)(entry + 0xC)) <= bound &&
                                (u32)fn_80179064(0, 0, *(s16*)(entry + 0xA), *(s16*)(entry + 0xE)) <= (u32)fn_8011F6F0(object)) {
                                void* actor = fn_80201B54(node);
                                if (fn_8020123C(0x3B, 0, (int)actor, 0)) {
                                    void* effect = fn_801A717C();
                                    float pos[3];
                                    fn_80179B08(entry + 0xA, pos);
                                    timers[3] = 0;
                                    fn_801A74A8(effect, actor);
                                    fn_801A7538(effect, 1);
                                    fn_801A7518(effect, 10);
                                    fn_801A7588(effect, 2);
                                    fn_801A7470(effect, -1);
                                    fn_801A764C(effect, pos);
                                    fn_8020123C(0x27, -1, (int)actor, (int)effect);
                                    fn_801A7228(effect);
                                }
                            }
                        }
                        node = fn_80201BC0(node);
                    }
                }
                if (entry[0] && !fn_8018E26C(entry, entry + 0x2B))
                    fn_80180518(self + 0x24, (u8)i, 0);
                if (*(u16*)(self + 0xA) == *(u16*)(entry + 8)) {
                    SixBytes setup = lbl_80651D28;
                    if (timers[2])
                        setup.half = (fn_800FBFB0() & 1) + 1;
                    else
                        setup.half = -1 - (fn_800FBFB0() & 1);
                    memcpy(entry + 0x10, &setup, 6);
                    fn_8018E230(entry, entry + 0x2B, 1, self[2], self[4], 0);
                }
            } else if (--*(s16*)(timers + 8) == 0) {
                fn_80180518(self + 0x24, (u8)i, 1);
                entry[0x2B] = self[2];
            }
        }
    } else {
        *(u32*)(self + 0x148) = 0;
        --*(u16*)(timers + 6);
    }
    ++*(u16*)(self + 0xA);
    if (fn_80180454(self + 0x24) || *(u16*)(self + 0xA) > 300)
        *(u16*)(self + 0x22) = 8;
    return 0;
}
