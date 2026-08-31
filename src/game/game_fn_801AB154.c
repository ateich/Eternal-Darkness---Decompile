typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Entry {
    short x;
    short y;
    short z;
    unsigned char flags;
    unsigned char arg9;
    unsigned int magnitude;
    unsigned char pad0C[4];
    unsigned int id;
    float arg4;
} Entry;

typedef struct State {
    unsigned char pad00[0xB8];
    unsigned short count;
    unsigned char padBA[2];
    Entry* entries;
    unsigned char padC0[0x8080];
    short kind;
} State;

extern unsigned short fn_80050728(void);
extern int fn_801AAE68(unsigned short, int, unsigned char, float,
                       Vec3*, signed char, unsigned char, unsigned char,
                       unsigned short, unsigned int);

void fn_801AB154(State* state)
{
    unsigned int count = state->count;
    int i;
    unsigned short id;
    int arg4;
    unsigned int magnitude;
    unsigned int flags;
    Entry* entry;
    Vec3 position;

    if (count != 0) {
        entry = state->entries;
        if (count > 68)
            count = 68;

        for (i = 0; i < (int)count; i++, entry++) {
            id = entry->id;
            flags = (entry->flags & 0x13) | 0x20;
            arg4 = entry->arg4;
            magnitude = entry->magnitude;

            position.x = entry->x;
            position.y = entry->y;
            position.z = entry->z;
            if (id == 489)
                id = 488;
            if ((flags & 1) && (flags & 2))
                flags &= 0xFFFFFFFCu;

            if ((id < fn_80050728() || (flags & 0x10)) &&
                (id < 731 || !(flags & 0x10))) {
                fn_801AAE68(id, arg4, 0, magnitude, &position, 1, 1,
                            entry->arg9, state->kind, flags);
            }
        }
    }
}
