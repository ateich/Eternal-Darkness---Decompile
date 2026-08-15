typedef struct Entry {
    unsigned char pad[0x98];
    signed short kind;
    unsigned char pad_9a[5];
    unsigned char state;
} Entry;

extern void fn_800A4F98(int);
extern int fn_80201B5C(void *);
extern int fn_80201B64(void *);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern int fn_80200614(int, int, int);
extern Entry *fn_80201B8C();
extern unsigned int fn_80204B10(void *, void *);

#pragma use_lmw_stmw on

int fn_800BA124(void *object, unsigned int check_id, int wanted_id)
{
    int type;
    int subtype;
    void *data;
    int id;
    int blocked;
    int is_kind_19;
    int is_kind_91;
    int kind;
    Entry *entry;
    unsigned int scratch[2];

    fn_800A4F98(2);
    blocked = 0;
    type = fn_80201B5C(object);
    subtype = fn_80201B64(object);
    data = fn_80201BC8(object);
    id = fn_80201B54(object);
    if (type == 6 && subtype == 6) {
        blocked = fn_80200614(id, -1, 8);
    }
    if (data != 0 && !blocked && type != 35 && type != 79 && type != 21 &&
        type != 83 && (type != 88 || subtype != 8)) {
        entry = fn_80201B8C(object);
        if (entry != 0) {
            kind = entry->kind;
            is_kind_19 = kind == 19;
            is_kind_91 = kind == 91;
        } else {
            return 0;
        }
        if (entry->state == 10 && subtype == 8) {
            return 0;
        }
        if (fn_80204B10(object, scratch) == 0 && !is_kind_19 && !is_kind_91 &&
            (!check_id || id != wanted_id)) {
            return 1;
        }
    }
    return 0;
}
