typedef struct ModeState {
    int unk0;
    int unk4;
    int mode;
} ModeState;

extern int lbl_8064D18C;
extern void *lbl_8064C4E0;
extern void *lbl_8064C4E4;
extern int lbl_8064C578;
extern ModeState lbl_803003C8;

extern void *fn_80201B3C();
extern int fn_800462C8(int);
extern int fn_801E79FC(void *, int);
extern int fn_80036D5C(void *);
extern int fn_800E783C(void);
extern int fn_8014B7B0(void *);
extern int fn_8007D834(void);
extern int fn_80201EB8();
extern void *fn_80201B9C();
extern int fn_80201B4C(void *);
extern int fn_80201B5C(void *);
extern int fn_80201B64(void *);
extern void *fn_80201B8C();
extern void *fn_80201BC0(void *);

int fn_800AF844(void) {
    void *target;
    void *obj;
    ModeState *state;
    int kind;
    int type;
    int sub;
    unsigned char *data;

    target = fn_80201B3C();
    if (fn_800462C8(1) != 0) {
        return 0;
    }
    if (lbl_8064D18C == 0x53) {
        return 0;
    }
    if (lbl_8064D18C == 5) {
        return 0;
    }
    if (lbl_8064D18C == 0xeb) {
        return 0;
    }
    if (lbl_8064D18C == 0xb8) {
        return 0;
    }
    if (fn_801E79FC(lbl_8064C4E0, 0x11e) != 0 && fn_801E79FC(lbl_8064C4E0, 0x11d) == 0) {
        return 0;
    }
    state = &lbl_803003C8;
    if (state->mode == 4) {
        if (fn_801E79FC(lbl_8064C4E0, 0x296) != 0 || fn_801E79FC(lbl_8064C4E0, 0xbd) != 0) {
            return 0;
        }
    }
    if (state->mode == 5 && lbl_8064D18C == 0xff && fn_801E79FC(lbl_8064C4E0, 0x373) != 0) {
        return 0;
    }
    if ((fn_80036D5C(target) & 0x80) || (fn_80036D5C(target) & 0x8000)) {
        return 0;
    }
    if (state->mode == 9 && lbl_8064C578 < 4 && fn_801E79FC(lbl_8064C4E0, 0x206) != 0) {
        return 0;
    }
    if (fn_800E783C() == 0) {
        return 0;
    }
    if (fn_8014B7B0(lbl_8064C4E4) != 0) {
        return 0;
    }
    if (fn_8007D834() == 5) {
        return 0;
    }
    if (target != 0) {
    for (obj = fn_80201B9C(fn_80201EB8(target)); obj != 0; obj = fn_80201BC0(obj)) {
        if (obj == target) {
            continue;
        }
        if (lbl_8064D18C != fn_80201EB8(obj)) {
            continue;
        }
        kind = fn_80201B4C(obj);
        type = fn_80201B5C(obj);
        fn_80201B64(obj);
        switch (kind) {
        case 1:
            data = fn_80201B8C(obj);
            if (type == 0x15) {
                break;
            }
            if (data == 0) {
                break;
            }
            switch (data[0x9f]) {
            case 3: case 4: case 5: case 6: case 7: case 8: case 9:
            case 12: case 13: case 22: case 24: case 28: case 29:
            case 34: case 37: case 39: case 41:
                return 0;
            case 10: case 11: case 38:
                if (fn_80036D5C(obj) & 0x80) {
                    return 0;
                }
                break;
            case 31: case 32: case 33: case 35: case 36: case 40:
                return 0;
            }
            break;
        case 3:
            return 0;
        case 2:
            type = fn_80201B5C(obj);
            sub = fn_80201B64(obj);
            switch (type) {
            case 0x39:
            case 0x48:
                return 0;
            case 0x50:
                if (sub == 0xb) {
                    return 0;
                }
                break;
            case 0x51:
                if (sub == 1) {
                    return 0;
                }
                break;
            case 0x55:
                if (sub == 0xf) {
                    return 0;
                }
                break;
            }
            break;
        }
    }
    return 1;
    }
    return 0;
}
