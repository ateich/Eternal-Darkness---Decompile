typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec {
    float x;
    float y;
    float z;
} Vec;

typedef struct ActorState {
    unsigned char pad0[0xC];
    int unkC;
    int unk10;
    int unk14;
    unsigned char pad18[0xA];
    u8 unk22;
} ActorState;

typedef struct ActorData {
    unsigned char pad0[0x50];
    ActorState *state;
    unsigned char pad54[0x38];
    unsigned char *unk8C;
} ActorData;

extern int fn_80200C10(void *);
extern int fn_80200C20(void *);
extern int fn_80200C28(void *);
extern int fn_80200C38(void *);
extern void *fn_80201BC8(void *);
extern ActorData *fn_80201B8C(void *);
extern void *fn_80201B94(void *);
extern int fn_80201B54(void *);
extern int fn_80201B44(void);
extern int fn_80201814(int);
extern int fn_80201C48(void *);
extern void fn_80201D14(void *, int);
extern void fn_80201D1C(void *, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D34(void *, int);
extern void fn_8011F114(Vec *, void *);
extern void fn_8011F778(void *, float);
extern void fn_8011FA8C(void *, int, int);
extern void fn_80120AD0(void *, int, int, int, float, float);
extern void fn_801261F4(void *);
extern void fn_80128A84(int, int, int);
extern int fn_80128E30(void *);
extern int fn_80128EAC(void *);
extern void fn_80128F40(void *);
extern void fn_80128F74(void *, int);
extern int fn_801290D0(void *);
extern void *fn_801294DC(void *, int, int, int);
extern void fn_801296F8(void *, int);
extern int fn_8012A1BC(void *, int);
extern void fn_8012B324(void *);
extern void fn_8012B344(void *);
extern void fn_8012C62C(void *, int, int *, int *, int *, int);
extern void fn_8012DBE8(void *, int, u8 *);
extern void fn_801A7228(int);
extern int fn_801A74C0(int);
extern void fn_801A7588(int, int);
extern void fn_801A977C(void *, int);
extern void fn_801AAE68(int, int, int, Vec *, int, int, int, u16, float, int);
extern void fn_801E8328(int, void *);
extern void fn_802006D4(int, int, int, int, int);
extern void fn_8020104C(int, int, int, int, float);
extern void fn_8020123C(int, int, int, int);
extern void fn_80204FDC(void *);
extern int fn_80035FB8(void *, char *, char *, char *, char *, char *);
extern int fn_80036D5C(void *);
extern void fn_80036DA4(void *, int);
extern int fn_80036E50(int);
extern void fn_8003C114(void *, void *, int);
extern void fn_8003E5DC(void *, void *, int, unsigned char *);
extern void fn_80064B38(void *, void *, int *);
extern int fn_800654F8(int);
extern void fn_80066754(void *, void *, int *);
extern void fn_80066888(void *, int, float, float);
extern void fn_80068994(void *, void *);
extern void fn_8008CC84(void *);
extern int fn_8008D6E4(void *, void *, void *);
extern void fn_8008E078(void *, void *, void *);
extern void fn_8008E294(void *, ActorState *, void *, Vec *, void *);
extern void fn_8008E3D8(void *, int, ActorState *, void *, void *);
extern void fn_8008E430(void *, int, ActorState *, void *, void *, int *, int);
extern void fn_8008E670(void *, int, void *, void *);
extern void fn_8008E810(int, ActorState *);
extern void fn_8008E88C(void *, void *, int, Vec *, ActorState *, void *, void *);
extern void fn_8008EA1C(void *, void *, int, Vec *, ActorState *, void *, void *, int);
extern void fn_8008ED9C(void *, void *, Vec *, void *);
extern void fn_8008EFA8(void *, void *, int *);
extern void fn_800BCE94(void *, int);
extern void fn_800BD2DC(void *, unsigned char *);
extern void fn_800BDEE4(void *, unsigned char *);
extern void fn_800BE010(void *, unsigned char *);
extern int fn_800BE70C(void *, unsigned char *, int, int, float, float, float);
extern void fn_800BE8D4(int);
extern int fn_800C9BA8(void *, ActorData *);
extern void fn_800C9E50(void *);
extern void fn_800CA2C8(void *);
extern void fn_800CF598(void *);
extern void fn_800DD314(void *, int, int, int);
extern int fn_800DE3F8(void);
extern void fn_800DFD54(int, void *, void *, void *);
extern void fn_800DFEB0(void *, void *, unsigned char *, int *, int *);
extern void fn_800DFF70(void *, void *, ActorData *, ActorState *, int *, int *);
extern void fn_800E00F0(void *, void *, ActorData *, unsigned char *, void *);
extern void fn_800E0330(void *);
extern void fn_800E03C4(void *, void *, void *, int *, int *);

typedef struct AnimNames {
    char idle[0x18];
    char walk[0xC];
    char run[0x18];
    char attackA[0x14];
    char attackB[0x14];
    char recover[0x10];
} AnimNames;

extern AnimNames lbl_80248C88;
extern int lbl_8064B798;
extern int lbl_8064B79C;
extern char lbl_8064B7A0[8];
extern char lbl_8064B7A8[8];
extern char lbl_8064B7B0[8];
extern int lbl_8064C570;
extern int lbl_8064CAD0;
extern int lbl_8064CAD4;
extern int lbl_8064D18C;
extern int lbl_8064D5A8;
extern const int lbl_8064F560;
extern const int lbl_8064F564;
extern const float lbl_8064F568;
extern const float lbl_8064F56C;
extern const float lbl_8064F570;
extern const float lbl_8064F574;
extern const float lbl_8064F578;
extern const float lbl_8064F57C;
extern const float lbl_8064F580;
extern const float lbl_8064F584;
extern const float lbl_8064F588;
extern const float lbl_8064F58C;
extern int lbl_80651B00;

int fn_800DEAD8(void *context, int phase, void *message, int *result)
{
    ActorState *state;
    unsigned char *target;
    void *owner;
    void *object;
    int id;
    int kind;
    AnimNames *names;
    ActorData *data;
    Vec pos;
    u8 color[4];
    int a;
    int b;
    int c;

    names = &lbl_80248C88;
    kind = fn_80200C10(message);
    object = fn_80201BC8(context);
    data = fn_80201B8C(context);
    state = data->state;
    target = data->unk8C;
    owner = fn_80201B94(context);
    id = fn_80201B54(context);
    fn_8011F114(&pos, object);

    if (kind == 3)
        fn_800DFF70(context, object, data, state, &lbl_8064B798, &lbl_8064B79C);

    if (phase == 0) {
        if (kind == 1) {
            fn_8008CC84(context);
            lbl_8064C570 = 0;
            fn_801261F4(object);
            fn_800DD314(context, 15, 127, 0);
            fn_8011F778(object, lbl_8064F568);
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 57) {
            fn_8012B324(object);
            fn_80201D34(context, 0);
            fn_80201D1C(context, 1);
            fn_801E8328(2, context);
            return 1;
        }
        if (kind == 61) {
            fn_800BD2DC(context, target);
            fn_800E0330(context);
            return 1;
        }
        if (kind == 201) {
            fn_8011FA8C(object, 0, 0x20000000);
            fn_801AAE68(0x1F1, 100, 0, &pos, 2, 2, 0, lbl_8064D18C, lbl_8064F56C, 0);
            return 1;
        }
        if (kind == 62) {
            fn_800C9E50(context);
            fn_800DFEB0(context, object, target, &lbl_8064B798, &lbl_8064B79C);
            return 1;
        }
        if (kind == 16) {
            c = lbl_8064F564;
            b = lbl_8064F560;
            a = lbl_80651B00;
            fn_8012C62C(object, 15, &a, &b, &c, 4);
            return 1;
        }
        if (kind == 59) {
            int sender;
            int link;
            sender = fn_80200C20(message);
            link = fn_80201814(sender);
            fn_8012DBE8(object, 15, color);
            if (color[3] > 20 && sender == fn_80201B44() && fn_80036E50(link) != 6 && result != 0)
                *result = 1;
            return 1;
        }
        if (kind == 237) {
            fn_8020123C(11, fn_80200C20(message), fn_80200C28(message), fn_80200C38(message));
            fn_801A7228(fn_80200C38(message));
            return 1;
        }
        if (kind == 58) {
            fn_8020123C(39, fn_80200C20(message), fn_80200C28(message), fn_80200C38(message));
            fn_801A7228(fn_80200C38(message));
            return 1;
        }
        if (kind == 11) {
            int value;
            fn_801A7588(fn_80200C38(message), 0x8000);
            value = fn_800654F8(fn_80200C38(message));
            if (result != 0)
                *result = value;
            return 1;
        }
        if (kind == 14) {
            fn_80068994(context, message);
            return 1;
        }
        if (kind == 39) {
            fn_80064B38(context, message, result);
            return 1;
        }
        if (kind == 230) {
            int value = fn_80200C38(message);
            void *self = fn_80201BC8(context);
            fn_80036DA4(context, fn_80036D5C(context) & ~0x100000);
            fn_801A7588(value, 2);
            fn_80066888(self, value, lbl_8064F570, lbl_8064F574);
            return 1;
        }
        if (kind == 53) {
            fn_8008EFA8(context, message, result);
            fn_80036DA4(context, fn_80036D5C(context) & ~0x100000);
            return 1;
        }
        if (kind == 27) {
            fn_800DFD54(1, context, object, message);
            return 1;
        }
        if (kind == 8) {
            fn_800E00F0(context, object, data, target, message);
            return 1;
        }
    } else if (phase == 1) {
        if (kind == 3) {
            fn_800E03C4(context, object, message, &lbl_8064B79C, &lbl_8064B798);
            return 1;
        }
    } else if (phase == 3) {
        if (kind == 1)
            return 1;
        if (kind == 3) {
            Vec p;
            if ((lbl_8064D5A8 & 0x1F) == 0 && fn_80201C48(owner) != 0)
                fn_800BDEE4(context, target);
            fn_800BE010(context, target);
            fn_800BCE94(context, 10);
            p = pos;
            fn_8008EA1C(context, object, id, &p, state, owner, message, 1);
            return 1;
        }
    } else if (phase == 102) {
        if (kind == 1)
            return 1;
        if (kind == 3) {
            Vec p;
            if ((lbl_8064D5A8 & 0x1F) == 0 && fn_80201C48(owner) != 0)
                fn_800BDEE4(context, target);
            fn_800BE010(context, target);
            fn_800BCE94(context, 10);
            p = pos;
            fn_8008E88C(context, object, id, &p, state, owner, message);
            return 1;
        }
    } else if (phase == 61) {
        if (kind == 1) {
            fn_800BDEE4(context, target);
            return 1;
        }
        if (kind == 3) {
            Vec p;
            if ((lbl_8064D5A8 & 0x1F) == 0 && fn_80201C48(owner) != 0)
                fn_800BDEE4(context, target);
            fn_800BE010(context, target);
            fn_800BCE94(context, 10);
            p = pos;
            fn_8008ED9C(context, object, &p, message);
            return 1;
        }
    } else if (phase == 6) {
        if (kind == 27) {
            fn_800DFD54(0, context, object, message);
            return 1;
        }
        if (kind == 12) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 7) {
            if (fn_80035FB8(context, names->idle, lbl_8064B7A0, names->walk, lbl_8064B7A8, names->run) == 0) {
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            return 1;
        }
        if (kind == 2) {
            fn_800DD314(context, 15, 10, 0);
            return 1;
        }
    } else if (phase == 7) {
        if (kind == 1) {
            fn_801296F8(object, 0x1FD70);
            fn_800DD314(context, 15, 10, 250);
            return 1;
        }
        if (kind == 27) {
            fn_800DFD54(0, context, object, message);
            return 1;
        }
        if (kind == 54) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 7) {
            if (fn_80035FB8(context, names->idle, lbl_8064B7B0, names->walk, lbl_8064B7A8, names->run) == 0) {
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            return 1;
        }
        if (kind == 2) {
            fn_800DD314(context, 15, 10, 0);
            return 1;
        }
    } else if (phase == 58) {
        if (kind == 1) {
            lbl_8064CAD0 = 0;
            return 1;
        }
        if (kind == 3) {
            if (lbl_8064CAD0++ > 130 && fn_8008D6E4(context, object, message) == 0) {
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            return 1;
        }
    } else if (phase == 59) {
        if (kind == 1) {
            fn_800DD314(context, 15, 10, 250);
            return 1;
        }
        if (kind == 27) {
            fn_800DFD54(0, context, object, message);
            return 1;
        }
        if (kind == 126) {
            fn_8008E3D8(context, id, state, object, message);
            return 1;
        }
        if (kind == 230) {
            fn_80066754(context, message, result);
            return 1;
        }
        if (kind == 53) {
            fn_80066754(context, message, result);
            return 1;
        }
        if (kind == 61) {
            state->unk14 = 0;
            state->unk10 = 0;
            state->unkC = 0;
            fn_800E0330(context);
            fn_8012B344(object);
            fn_800BD2DC(context, target);
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 6) {
            Vec p;
            p = pos;
            fn_8008E294(context, state, object, &p, message);
            return 1;
        }
        if (kind == 2) {
            lbl_8064B79C = 300;
            return 1;
        }
    } else if (phase == 56) {
        if (kind == 1) {
            int same = fn_800DE3F8() - state->unk10 == 0;
            state->unk22 = 0;
            lbl_8064CAD4 = same ? 0 : 240;
            return 1;
        }
        if (kind == 3) {
            fn_8008E430(context, id, state, object, message, &lbl_8064CAD4, 0);
            return 1;
        }
        if (kind == 27) {
            fn_800DFD54(0, context, object, message);
            return 1;
        }
        if (kind == 6) {
            fn_8008E078(context, object, message);
            return 1;
        }
        if (kind == 126) {
            fn_8008E670(context, id, object, message);
            return 1;
        }
        if (kind == 230) {
            fn_80066754(context, message, result);
            return 1;
        }
        if (kind == 53) {
            fn_80066754(context, message, result);
            return 1;
        }
        if (kind == 61) {
            fn_8020123C(126, id, state->unk10 != 0 ? state->unk10 : state->unk14, 0);
            fn_8020123C(122, id, state->unkC, 0);
            state->unk10 = 0;
            state->unkC = 0;
            fn_800E0330(context);
            fn_8012B344(object);
            fn_800BD2DC(context, target);
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 2) {
            fn_8008E810(id, state);
            lbl_8064B79C = 300;
            return 1;
        }
    } else if (phase == 60) {
        if (kind == 1) {
            fn_800DD314(context, 15, 5, 0);
            return 1;
        }
        if (kind == 61) {
            state->unk14 = 0;
            state->unk10 = 0;
            state->unkC = 0;
            fn_8012B344(object);
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            fn_800E0330(context);
            fn_800BD2DC(context, target);
            return 1;
        }
        if (kind == 6) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 2) {
            lbl_8064B79C = 300;
            return 1;
        }
    } else if (phase == 21) {
        if (kind == 1) {
            fn_8012B344(object);
            return 1;
        }
        if (kind == 3) {
            if (fn_800BE70C(object, target + 0x94, 2, 0, lbl_8064F578, lbl_8064F578, lbl_8064F57C) == 0) {
                fn_8012B344(object);
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            return 1;
        }
        if (kind == 2) {
            int model = fn_80128EAC(object);
            int flags = fn_801290D0(object);
            if ((flags & 4) && (model == 3 || model == 2))
                fn_80128F74(object, flags & ~4);
            return 1;
        }
    } else if (phase == 31) {
        if (kind == 1) {
            int model = fn_80128EAC(object);
            int slot = fn_8012A1BC(object, model);
            fn_80128F40(object);
            fn_800BE8D4(id);
            fn_801A977C(object, 0x33);
            fn_800CA2C8(context);
            fn_80204FDC(context);
            fn_8020104C(17, id, id, 0, lbl_8064F580);
            fn_80128A84(fn_80128E30(object), 0, slot);
            return 1;
        }
        if (kind == 3) {
            fn_8003E5DC(context, object, id, target);
            return 1;
        }
        if (kind == 27) {
            fn_800DFD54(0, context, object, message);
            return 1;
        }
        if (kind == 48) {
            int value = fn_800654F8(fn_80200C38(message));
            if (result != 0)
                *result = value;
            return 1;
        }
        if (kind == 61) {
            fn_800BD2DC(context, target);
            fn_8020123C(57, id, id, 0);
            return 1;
        }
        if (kind == 17) {
            fn_801294DC(object, 40, 37, 10);
            fn_800CF598(context);
            fn_80120AD0(object, 0, 0, 0x101, lbl_8064F584, lbl_8064F588);
            fn_80201D34(context, 21);
            fn_80201D1C(context, 1);
            return 1;
        }
        if (kind == 49) {
            fn_8003C114(context, object, id);
            return 1;
        }
        if (kind == 7) {
            fn_80035FB8(context, names->attackA, names->attackB, names->walk, names->recover, names->recover);
            return 1;
        }
        if (kind == 59)
            return 1;
        if (kind == 53)
            return 1;
        if (kind == 8)
            return 1;
        if (kind == 11)
            return 1;
        if (kind == 39)
            return 1;
        if (kind == 62)
            return 1;
        if (kind == 123)
            return 1;
    } else if (phase == 8) {
        if (kind == 1) {
            fn_8011FA8C(object, 0xC0, 0);
            fn_800DD314(context, 15, 5, 250);
            return 1;
        }
        if (kind == 27) {
            fn_800DFD54(0, context, object, message);
            return 1;
        }
        if (kind == 61) {
            fn_800BD2DC(context, target);
            fn_8020123C(57, id, id, 0);
            return 1;
        }
        if (kind == 17) {
            fn_801294DC(object, 40, 37, 10);
            fn_800CF598(context);
            fn_80120AD0(object, 0, 0, 0x101, lbl_8064F584, lbl_8064F588);
            fn_80201D34(context, 21);
            fn_80201D1C(context, 1);
            return 1;
        }
        if (kind == 193) {
            if (result != 0)
                *result = fn_800C9BA8(object, data);
            return 1;
        }
        if (kind == 47) {
            fn_80201D2C(context, 31);
            fn_80201D14(context, 1);
            return 1;
        }
        if (kind == 11) {
            int value = fn_80200C38(message);
            if (fn_801A74C0(value) & 0x20) {
                int handled = fn_800654F8(value);
                fn_8020123C(47, id, id, 0);
                fn_8020104C(49, id, id, 0, lbl_8064F58C);
                if (result != 0)
                    *result = handled;
            }
            return 1;
        }
        if (kind == 53) {
            fn_80066888(object, fn_80200C38(message), lbl_8064F570, lbl_8064F574);
            return 1;
        }
        if (kind == 2) {
            fn_802006D4(id, id, 8, 17, 0);
            return 1;
        }
        if (kind == 59)
            return 1;
        if (kind == 53)
            return 1;
        if (kind == 8)
            return 1;
        if (kind == 11)
            return 1;
        if (kind == 39)
            return 1;
        if (kind == 123)
            return 1;
        if (kind == 62)
            return 1;
    } else {
        return 0;
    }
    return 0;
}
