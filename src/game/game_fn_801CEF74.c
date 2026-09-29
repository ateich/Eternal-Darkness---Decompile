typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef float f32;

typedef struct Object {
    u8 bytes[0x1000];
} Object;

extern int lbl_8064D18C;
extern int lbl_8064D548;
extern int lbl_8064D550;
extern void* fn_80201B54(void*);
extern void fn_8020123C(u32, void*, void*, u32);
extern void fn_801FDF3C(void*, u32);
extern void fn_801FDF00(void*, u32);
extern void fn_801FDFEC(void*, u32);
extern void fn_801FE024(void*, u32);
extern void fn_802006D4(void*, void*, int, u32, u32);
extern void fn_8019B134(void*, u32);
extern void fn_801D313C(u32, u32, void*);
extern void* fn_80201814(void*);
extern void* fn_80201C24(void*);
extern u32 fn_80157894(void*);
extern void fn_80027B78(u32, void*);
extern void fn_801D1318(u32);
extern void fn_801B05B0(int, u32);
extern void fn_801A9E40(int);
extern void fn_801D0E78(void*);
extern void fn_800A0B68(u32);
extern f32 fn_80048C2C(f32);
extern f32 fn_80048C50(f32);
extern void fn_801CEBC4(void*, void*, int, int, s16, void*);

extern int fn_80128258(void);
extern int fn_80128130(void);
extern void* fn_800453AC(int, int, int, int, int, int, int, int,
                           f32*, int, int, f32);
extern void fn_8020104C(int, void*, void*, int, f32);
extern void* fn_80201BC8(void*);
extern u32 fn_801D3944(u32);
extern const u32 lbl_80651EB8;
extern void* fn_8012C62C(void*, int, void*, void*, void*, int);
extern void fn_8011FA8C(void*, int, u32);
extern void fn_8011FABC(void*, int, u32);
extern const u32 lbl_80651060;
extern void* fn_800CE9A4(void*, int, int);
extern void fn_801E8328(int, void*);
extern u32 fn_801D39F4(u32);
extern void fn_801E2B28(void*, void*, void*, int, int);
extern void fn_801B0CA4(int, int);
extern void fn_801CE720(u32, int, void*, u16, int, u8, void*, f32);

/*
 * Partial NonMatching reconstruction: teardown, point/effect creation, and
 * timer events are recovered. The completed-count dispatcher at retail
 * 0x801CF45C..0x801CFC70 is still absent.
 */
void fn_801CEF74(Object* object)
{
    Object* owner = *(Object**)(object->bytes + 0x284);
    u8* work = object->bytes + 0xBC;
    int local_gate = 0;
    int* gate = &local_gate;
    u8 flags = object->bytes[0xFF0];

    if (flags & 0x10) {
        gate = &lbl_8064D550;
    }

    if (*gate != 0 || *(int*)(object->bytes + 8) != lbl_8064D18C ||
        (owner->bytes[0xFF0] & 1) || (flags & 1)) {
        if (*(u16*)(work + 0xF38) != 0) {
            if (*(u16*)(work + 0xF38) > 10) {
                void* effect = *(void**)(owner->bytes + 0x30);
                if (effect != 0) {
                    void* data = fn_80201B54(effect);
                    fn_8020123C(0x39, data, data, 0);
                }
                if (*(u16*)(work + 0xF38) > 20) {
                    fn_801FDF3C(*(void**)(owner->bytes + 0x44), 0);
                    fn_801FDF00(*(void**)(owner->bytes + 0x44), 0);
                    fn_801FDFEC(*(void**)(owner->bytes + 0x44), 0);
                    fn_801FE024(*(void**)(owner->bytes + 0x44), 60);
                }

                if (*(u16*)(work + 0xF38) >= 30) {
                    int i;

                    for (i = 0; i < *(s16*)(work + 8); i++) {
                        void* item = *(void**)(work + 0x14 + i * 4);
                        if (item != 0) {
                            fn_802006D4(item, item, -1, 0x39, 0);
                            fn_8020123C(0x39, item, item, 0);
                        }
                    }

                    if (*(u16*)(work + 0xF38) > 30) {
                        for (i = 0; i < *(s16*)(work + 8); i++) {
                            void* item = *(void**)(work + 0x1AC + i * 4);
                            if (item != 0) {
                                fn_8019B134(item, 0);
                            }
                        }

                        if (*(int*)(object->bytes + 8) == lbl_8064D18C &&
                            (object->bytes[0xFF0] & 8)) {
                            fn_801D313C(*(u32*)(owner->bytes + 4),
                                        *(u32*)(object->bytes + 0xC),
                                        owner->bytes + 0x38);
                        }
                    }
                }
            }
        }

        if ((*(int*)(owner->bytes + 4) & 0x1FF0) == 0x300) {
            void* resource = *(void**)(owner->bytes + 0xBC);
            void* data = fn_80201C24(fn_80201814(resource));
            if (fn_80157894(data) & 1) {
                fn_80027B78(*(u32*)(object->bytes + 0xC), resource);
            }
            lbl_8064D548 = 0;
        }

        if ((*(u16*)(work + 0xF38) <= 30 ||
             !(object->bytes[0xFF0] & 8)) &&
            (object->bytes[0xFF0] & 0x10)) {
            fn_801D1318(0);
        }

        *gate = 0;
        fn_8020123C(0xB0, *(void**)(object->bytes + 0xC),
                    *(void**)(object->bytes + 0xC), 0);

        if (*(int*)(owner->bytes + 0x10) != -1) {
            fn_801B05B0(*(int*)(owner->bytes + 0x10), 10);
        }

        fn_801A9E40(-1);
        fn_801D0E78(owner);
        fn_801D0E78(object);
        fn_800A0B68(0);
        return;
    }

    /* First arm of the event/state dispatcher. */
    if (*(u16*)(work + 0xF38) >= 30 &&
        work[1] < *(s16*)(work + 8)) {
        if (work[3] == 0) {
            f32 angle = 6.2831855f * (f32)work[1] /
                        (f32)*(s16*)(work + 8);
            f32 point[3];
            u32 scratch;
            f32 trig;

            trig = fn_80048C2C(angle);
            point[0] = (f32)work[4] * trig + *(f32*)(work + 0x30);
            trig = fn_80048C50(angle);
            point[1] = (f32)work[4] * trig + *(f32*)(work + 0x34);
            point[2] = *(f32*)(work + 0x38);
            scratch = *(u32*)(work + 0x1CC);
            fn_801CEBC4(work + 0xF8, point, 4, 4,
                        *(s16*)(work + 6), &scratch);
            work[1]++;
            work[3] = work[2];

            if (fn_80128258() || fn_80128130()) {
                void* effect = fn_800453AC(0x5B, 0x68,
                    *(int*)(object->bytes + 8), -1, -1, -1, -1, 0x3E,
                    point, 1, 0, 0.0f);
                void* data;
                *(void**)(work + 0x10 + work[1] * 4) = effect;
                fn_8020104C(0x39, effect, effect, 0,
                    (f32)(*(u16*)(work + 0xA) +
                        (*(s16*)(work + 8) - work[1]) * 45 - work[1]));
                fn_8020104C(0x9C, effect, effect, 6, 1.0f);
                data = fn_80201814(effect);
                if (data != 0) {
                    data = fn_80201BC8(data);
                    if (data != 0) {
                        u32 color = fn_801D3944(*(u32*)(owner->bytes + 4));
                        u32 start = color;
                        u32 middle = lbl_80651EB8;
                        u32 end = color;
                        fn_8012C62C(data, 0xF, &start, &middle, &end, 0x12);
                        fn_8011FA8C(data, 0, 0x01000000);
                        fn_8011FABC(data, 0, 0x20);
                    }
                }
            } else {
                *(void**)(work + 0x10 + work[1] * 4) = 0;
            }
        } else {
            work[3]--;
        }
    }
    /* The completed-count dispatcher at 0x801CF45C is unreconstructed. */
    switch (*(u16*)(work + 0xF38)) {
    case 0:
        {
            void (*callback)(Object*, u32) =
                *(void (**)(Object*, u32))(owner->bytes + 0x20);
            if (callback != 0) {
                callback(owner, *(u32*)(owner->bytes + 0x24));
            }
            if (*(s16*)(work + 8) >= 7) {
                u32 scratch = *(u32*)(work + 0x1CC);
                fn_801CEBC4(work + 0x48, work + 0x30, 12, 30,
                    *(s16*)(work + 6), &scratch);
            }
        }
        break;
    case 10:
        {
            u32 scratch;
            if (owner->bytes[0xFF0] & 4) {
                u32 descriptor = lbl_80651060;
                *(void**)(owner->bytes + 0x30) =
                    fn_800CE9A4(&descriptor, 10, 0);
                if (*(void**)(owner->bytes + 0x30) != 0) {
                    fn_801E8328(13, *(void**)(owner->bytes + 0x30));
                }
            }
            scratch = *(u32*)(work + 0x1CC);
            fn_801CEBC4(work + 0x48, work + 0x30, 12, 30,
                *(s16*)(work + 6), &scratch);
        }
        break;
    case 20:
        {
            int duration = (*(s16*)(work + 8) - 1) * 45;
            u32 descriptor = fn_801D39F4(*(u32*)(work + 0x10));
            fn_801E2B28(owner->bytes + 0x44, work + 0x3C, &descriptor,
                (u16)(*(u16*)(work + 0xC) + duration), work[0]);
            *(u16*)(owner->bytes + 0x74) = *(u16*)(work + 0xE);
            if (*(s16*)(work + 8) >= 5) {
                u32 scratch = *(u32*)(work + 0x1CC);
                fn_801CEBC4(work + 0x48, work + 0x30, 12, 30,
                    *(s16*)(work + 6), &scratch);
            }
        }
        break;
    case 30:
        {
            int duration = (*(s16*)(work + 8) - 1) * 45;
            if (*(int*)(owner->bytes + 0x10) != -1) {
                fn_801B0CA4(*(int*)(owner->bytes + 0x10), 0);
            }
            fn_801CE720(*(u32*)(work + 0x10),
                *(int*)(object->bytes + 8), object->bytes + 0x38,
                (u16)(*(u16*)(work + 0xA) + duration), 1,
                (u8)(work[5] + duration), work + 0x1AC, 0.0f);
        }
        break;
    }
}
