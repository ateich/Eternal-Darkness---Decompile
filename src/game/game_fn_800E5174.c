typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;

#define NULL ((void *)0)

typedef struct Vec3 {
    int x, y, z;
} Vec3;

typedef struct GXColor {
    u8 r, g, b, a;
} GXColor;

typedef struct EventData {
    u8 pad00[0x88];
    int *slots;
    u8 pad8C[0x8];
    int kind;
} EventData;

extern int lbl_8064D18C;
extern void *lbl_8064C4E0;
extern int lbl_8064F6D0, lbl_8064F6D4, lbl_8064F6D8;
extern int lbl_8064F6DC, lbl_8064F6E0, lbl_8064F6E4;
extern int lbl_8064F6E8, lbl_8064F6EC, lbl_80651B38;
extern int lbl_8064F6F0, lbl_8064F6F4, lbl_80651B3C;
extern GXColor lbl_8064F6F8, lbl_8064F6FC, lbl_8064F700;
extern int lbl_8064F704, lbl_8064F708, lbl_8064F70C;
extern int lbl_8064F718, lbl_8064F71C, lbl_80651B40;
extern int lbl_8064F720, lbl_8064F724, lbl_80651B44;
extern int lbl_8064F728, lbl_8064F72C, lbl_80651B48;
extern int lbl_8064F730, lbl_8064F734, lbl_80651B4C;
extern int lbl_8064F710;
extern u16 lbl_8064F714;
extern u8 lbl_8064F716;
extern f32 lbl_8064F738, lbl_8064F73C, lbl_8064F740, lbl_8064F744;
extern f32 lbl_8064F748, lbl_8064F74C, lbl_8064F750;

extern int fn_80200C10(int);
extern int fn_80200C20(int);
extern int fn_80200C28(int);
extern int fn_80200C38(int);
extern int fn_80201B54(void *);
extern void *fn_80201BC8(void *);
extern EventData *fn_80201B8C(void *);
extern void *fn_80201814(int);
extern int fn_80201EB8(void *);
extern int fn_802019EC(int, int);
extern void fn_80201D14(void *, int);
extern void fn_80201D1C(void *, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D34(void *, int);
extern void fn_8020123C(int, int, int, int);
extern void fn_8020104C(int, int, int, int, f32);
extern void fn_8012C62C(void *, int, int *, int *, int *, u16);
extern void fn_8012B324(void *);
extern void fn_801E8328(int, void *);
extern void fn_801E7974(void *, int);
extern void fn_801A7228(void);
extern void fn_800E5EA0(int, void *, int, int, int, int *);
/* Defined as taking Vec3 *; the original passes the position by value, which
 * the EABI lowers to a pointer to a caller-side copy (same calling convention). */
extern void fn_800E50AC(Vec3, GXColor *);
extern void fn_8011F114(Vec3 *, void *);
extern void *fn_800CCF60(void *, int, int, void *, int, int, int, int, int, int, int);
extern void fn_80120AD0(void *, int, int, int, f32, f32);
extern int fn_800CB098(s8, s8, int, int, int, int *);
extern void fn_800CA3A0(void *, int, int, int);

int fn_800E5174(void *object, int state, int event, int *handled)
{
    void *runtime;
    int *slots;
    int id;
    u16 flags;
    int type;
    EventData *data;

    type = fn_80200C10(event);
    id = fn_80201B54(object);
    runtime = fn_80201BC8(object);
    data = fn_80201B8C(object);
    flags = 0x20;
    slots = data->slots;
    switch (data->kind) {
    case 2:
        flags |= 0x200;
        break;
    case 3:
        flags |= 0x100;
        break;
    case 1:
        flags |= 0x80;
        break;
    }

    if (state == 0) {
        if (type == 1) {
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (type == 0x3B) {
            if (handled != NULL) {
                *handled = 1;
            }
            return 1;
        } else if (type == 0x10) {
            int c0, c1, c2;
            c2 = lbl_8064F6D8;
            c1 = lbl_8064F6D4;
            c0 = lbl_8064F6D0;
            fn_8012C62C(runtime, 0xF, &c0, &c1, &c2, 4);
            return 1;
        } else if (type == 0x8C) {
            if (lbl_8064D18C == fn_80201EB8(object)) {
                int c0, c1, c2;
                int d0, d1, d2;
                c2 = lbl_8064F6E4;
                c1 = lbl_8064F6E0;
                c0 = lbl_8064F6DC;
                fn_8012C62C(runtime, 0xF, &c0, &c1, &c2, 4);
                d2 = lbl_8064F6EC;
                d1 = lbl_80651B38;
                d0 = lbl_8064F6E8;
                fn_8012C62C(runtime, 0, &d0, &d1, &d2, flags);
            }
            return 1;
        } else if (type == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        } else if (type == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        } else if (type == 0xB) {
            fn_800E5EA0(id, object, 1, state, event, handled);
            return 1;
        } else if (type == 0x3E) {
            if (lbl_8064D18C == fn_80201EB8(object)) {
                int c0, c1, c2;
                c2 = lbl_8064F6F4;
                c1 = lbl_80651B3C;
                c0 = lbl_8064F6F0;
                fn_8012C62C(runtime, 0, &c0, &c1, &c2, flags);
            }
            return 1;
        } else if (type == 0x39) {
            fn_8012B324(runtime);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            fn_801E8328(2, object);
            return 1;
        }
    } else if (state == 1) {
        if (type == 0xED) {
            fn_8020123C(0xB, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        } else if (type == 0x3A) {
            fn_8020123C(0x27, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        } else if (type == 0xB) {
            fn_800E5EA0(id, object, 0, state, event, handled);
            return 1;
        } else if (type == 0xAF) {
            fn_80201D2C(object, 0x26);
            fn_80201D14(object, 1);
            return 1;
        } else if (type == 3) {
            return 1;
        }
    } else if (state == 0x70) {
        int ids[3];
        Vec3 pos;
        int failIds[3];
        int doneIds[3];

        if (type == 0x3D) {
            int *slot;
            int i;
            for (slot = slots, i = 0; i < 3; i++, slot++) {
                if (*slot != 0) {
                    fn_8020123C(0x7A, id, *slot, 0);
                    *slot = 0;
                }
            }
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (type == 1) {
            int *p;
            int i;
            ids[0] = fn_802019EC(0x88A, lbl_8064D18C);
            ids[1] = fn_802019EC(0x88B, lbl_8064D18C);
            ids[2] = fn_802019EC(0x88C, lbl_8064D18C);
            slots[0] = 0;
            slots[1] = 0;
            slots[2] = 0;
            for (p = ids, i = 0; i < 3; i++, p++) {
                if (id != *p) {
                    void *other;
                    fn_8020123C(0xAF, id, *p, 0);
                    other = fn_80201814(*p);
                    if (other != NULL) {
                        void *otherRuntime = fn_80201BC8(other);
                        EventData *otherData = fn_80201B8C(other);
                        if (otherData != NULL && otherRuntime != NULL) {
                            Vec3 tmp;
                            fn_8011F114(&tmp, otherRuntime);
                            pos = tmp;
                            switch (otherData->kind) {
                            case 2: {
                                GXColor color = lbl_8064F6F8;
                                fn_800E50AC(pos, &color);
                                break;
                            }
                            case 3: {
                                GXColor color = lbl_8064F6FC;
                                fn_800E50AC(pos, &color);
                                break;
                            }
                            case 1: {
                                GXColor color = lbl_8064F700;
                                fn_800E50AC(pos, &color);
                                break;
                            }
                            }
                        }
                    }
                }
            }
            if (id == ids[0]) {
                fn_8020104C(0x79, id, id, ids[1], lbl_8064F738);
                fn_8020104C(0x79, id, id, ids[2], lbl_8064F73C);
            } else if (id == ids[1]) {
                fn_8020104C(0x79, id, id, ids[0], lbl_8064F738);
                fn_8020104C(0x79, id, id, ids[2], lbl_8064F73C);
            } else if (id == ids[2]) {
                fn_8020104C(0x79, id, id, ids[1], lbl_8064F738);
                fn_8020104C(0x79, id, id, ids[0], lbl_8064F73C);
            }
            return 1;
        } else if (type == 0x79) {
            void *other = fn_80201814(fn_80200C38(event));
            if (other != NULL) {
                int index = -1;
                void *otherRuntime = fn_80201BC8(other);
                void *spawned = fn_800CCF60(other, 0, 1, object, 0, 1, 0, 0, 1, 0x32, 1);
                EventData *otherData;
                if (slots[0] == 0) {
                    index = 0;
                } else if (slots[1] == 0) {
                    index = 1;
                } else if (slots[2] == 0) {
                    index = 2;
                }
                slots[index] = fn_80201B54(spawned);
                otherData = fn_80201B8C(other);
                if (otherData != NULL && otherRuntime != NULL) {
                    switch (otherData->kind) {
                    case 2:
                        fn_80120AD0(otherRuntime, 0, 100, 0xA, lbl_8064F740, lbl_8064F744);
                        break;
                    case 3:
                        fn_80120AD0(otherRuntime, 0, 100, 0x12, lbl_8064F740, lbl_8064F744);
                        break;
                    case 1:
                        fn_80120AD0(otherRuntime, 0, 100, 0x22, lbl_8064F740, lbl_8064F744);
                        break;
                    }
                }
            }
            return 1;
        } else if (type == 0x7A) {
            int c0, c1, c2;
            c2 = lbl_8064F70C;
            c1 = lbl_8064F708;
            c0 = lbl_8064F704;
            fn_8012C62C(runtime, 0xF, &c0, &c1, &c2, 4);
            fn_8020104C(0xAF, id, id, 0, lbl_8064F748);
            return 1;
        } else if (type == 0xAF) {
            int *slot;
            int i;
            int count;
            int *p;
            int j;
            int self;
            u8 kinds[7];
            u8 *kp;
            u32 k;
            *(int *)&kinds[0] = lbl_8064F710;
            *(u16 *)&kinds[4] = lbl_8064F714;
            kinds[6] = lbl_8064F716;
            count = 0;
            for (slot = slots, i = 0; i < 3; i++, slot++) {
                if (*slot != 0) {
                    fn_8020123C(0x7A, id, *slot, 0);
                    *slot = 0;
                }
            }
            for (k = 0, kp = kinds; k < 7; k++, kp++) {
                count += fn_800CB098(2, *kp, -1, lbl_8064D18C, 0, 0);
            }
            if (count <= 3) {
                fn_800CA3A0(object, 4, 0, 1);
            } else {
                self = fn_80201B54(object);
                failIds[0] = fn_802019EC(0x88A, lbl_8064D18C);
                failIds[1] = fn_802019EC(0x88B, lbl_8064D18C);
                failIds[2] = fn_802019EC(0x88C, lbl_8064D18C);
                for (p = failIds, j = 0; j < 3; j++, p++) {
                    if (self != *p) {
                        fn_8020104C(0x78, self, *p, 0, lbl_8064F74C);
                    }
                }
                fn_8020104C(0x7F, self, self, 0, lbl_8064F74C);
            }
            return 1;
        } else if (type == 0x78) {
            int *p;
            int *params;
            int i;
            int self;
            params = (int *)fn_80200C38(event);
            self = fn_80201B54(object);
            doneIds[0] = fn_802019EC(0x88A, lbl_8064D18C);
            doneIds[1] = fn_802019EC(0x88B, lbl_8064D18C);
            doneIds[2] = fn_802019EC(0x88C, lbl_8064D18C);
            for (p = doneIds, i = 0; i < 3; i++, p++) {
                if (self != *p) {
                    fn_8020123C(0x78, self, *p, 0);
                }
            }
            if (*params != 0 && lbl_8064D18C == 0x61) {
                fn_801E7974(lbl_8064C4E0, 0xA3);
            }
            if (lbl_8064D18C == fn_80201EB8(object)) {
                int c0, c1, c2;
                c2 = lbl_8064F71C;
                c1 = lbl_80651B40;
                c0 = lbl_8064F718;
                fn_8012C62C(runtime, 0, &c0, &c1, &c2, flags);
            }
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (type == 0x7F) {
            if (lbl_8064D18C == fn_80201EB8(object)) {
                int c0, c1, c2;
                c2 = lbl_8064F724;
                c1 = lbl_80651B44;
                c0 = lbl_8064F720;
                fn_8012C62C(runtime, 0, &c0, &c1, &c2, flags);
            }
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (type == 2) {
            return 1;
        }
    } else if (state == 0x26) {
        if (type == 0x3D) {
            int *slot;
            int i;
            for (slot = slots, i = 0; i < 3; i++, slot++) {
                if (*slot != 0) {
                    fn_8020123C(0x7A, id, *slot, 0);
                    *slot = 0;
                }
            }
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        } else if (type == 0x78) {
            if (lbl_8064D18C == fn_80201EB8(object)) {
                int c0, c1, c2;
                c2 = lbl_8064F72C;
                c1 = lbl_80651B48;
                c0 = lbl_8064F728;
                fn_8012C62C(runtime, 0, &c0, &c1, &c2, flags);
            }
            fn_80201D2C(object, 1);
            fn_80201D14(object, 1);
            return 1;
        }
    } else if (state == 8) {
        if (type == 1) {
            int c0, c1, c2;
            c2 = lbl_80651B4C;
            c1 = lbl_8064F734;
            c0 = lbl_8064F730;
            fn_8012C62C(runtime, 0xF, &c0, &c1, &c2, 4);
            fn_8020104C(0x39, id, id, 0, lbl_8064F750);
            return 1;
        } else if (type == 0xED) {
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        } else if (type == 0x3A) {
            fn_80200C38(event);
            fn_801A7228();
            return 1;
        } else if (type == 0x3B) {
            return 1;
        } else if (type == 0x10) {
            return 1;
        } else if (type == 0x8C) {
            return 1;
        } else if (type == 0xB) {
            return 1;
        } else if (type == 0x3E) {
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}
