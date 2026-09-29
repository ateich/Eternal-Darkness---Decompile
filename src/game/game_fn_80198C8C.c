typedef signed char s8;
typedef unsigned char u8;

typedef struct Channel {
    u8 active;
    u8 kind;
    u8 pad2[2];
    u8 value;
    s8 step;
    u8 pad6;
    u8 limit;
    u8 pad8[0x18];
    u8 envelope[0xB];
    u8 level;
    u8 pad2C[3];
    u8 balance;
    u8 pad30[8];
} Channel;

typedef struct Voice {
    u8 pad0;
    u8 count;
    u8 pad2[0x4A];
    Channel* channels;
    u8 pad50[0x52];
    u8 state;
    u8 padA3;
    u8 mode;
} Voice;

extern void fn_8018E230(Channel*, u8*, u8, u8, s8, u8);
extern void fn_8018E8B8(u8*, u8, int);

void fn_80198C8C(Voice* object, u8 mode, u8 value, s8 step, u8 kind, u8 limit)
{
    Channel* entry = object->channels;
    u8 count = object->count;
    int i;

    if (mode == 6) {
        object->state = 9;
        if (limit != 0) {
            if (entry->limit != 0 && limit >= entry->limit)
                goto done;
            entry->value = value;
            entry->step = step;
            entry->kind = kind;
            entry->limit = limit;
        } else {
            u8 level;
            u8 half;
            Channel* p;

            half = count >> 1;
            level = (step / 2) * ((value - 150) / step) + 60;
            entry->kind = kind;
            entry->step = step;
            p = object->channels;
            for (i = 0; i < count; i++) {
                p->level = level;
                p++;
            }
            p = object->channels;
            for (i = 0; i < half; i++) {
                p->balance = level;
                p++;
            }
            p = object->channels + half;
            for (i = 0; i < half; i++) {
                p->balance = value;
                p++;
            }
        }
    } else {
        object->state = 8;
        if (limit != 0) {
            if (entry->limit != 0 && limit >= entry->limit)
                goto done;
            for (i = 0; i < count;) {
                fn_8018E230(entry, &entry->value, mode, value, step, kind);
                entry->limit = limit;
                entry++;
                i++;
            }
        } else {
            for (i = 0; i < count;) {
                fn_8018E230(entry, &entry->level, mode, value, step, kind);
                fn_8018E8B8(entry->envelope, entry->level, 0);
                fn_8018E8B8(entry->envelope, entry->level, 1);
                entry++;
                i++;
            }
        }
    }
done:
    object->mode = mode;
}
