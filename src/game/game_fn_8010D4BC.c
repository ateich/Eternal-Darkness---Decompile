typedef short s16;

typedef struct ScrollEntry {
    int value;
    void* object;
    char pad08[0x1C];
    void* range;
    char pad28[0x4];
} ScrollEntry;

typedef struct ScrollState {
    char pad000[0x108];
    ScrollEntry entries[12];
    ScrollEntry shadows[12];
    char pad528[0x9A0 - 0x528];
    void* lists[6];
} ScrollState;

typedef struct ScrollPos {
    int x;
    int y;
    int z;
} ScrollPos;

extern ScrollState lbl_80330D80;
extern float lbl_8064CCB8;
extern int lbl_8064CCC4;
extern int lbl_8064CCC8;
extern int lbl_8064CCD4;
extern const float lbl_8064FE70;
extern const float lbl_8064FE98;

extern void fn_80144C40(void);
extern int fn_801E8D24(void*);
extern int fn_801E8D34(void*);
extern int fn_801E8D3C(void*);
extern void fn_801E8B6C(void*, s16);
extern int fn_80157858(void*);
extern s16 fn_8010D36C(void*);
extern void fn_801F69F0(ScrollPos*, float*, int);
extern void fn_8011F0E8(void*, float*);
extern void fn_80117EF0(void);
extern int fn_8010A32C(int, int, int);
extern void fn_801E5FB0(int);

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void fn_8010D4BC(s16 delta)
{
    ScrollState* state = &lbl_80330D80;
    void** lists;
    ScrollEntry* entry;
    ScrollEntry* shadow;
    float out[3];
    ScrollPos pos;
    s16 limit;
    int current;
    int offset;
    int steps;
    float frac;
    int oldPage;
    int oldLine;
    int newPage;
    int newLine;

    fn_80144C40();
    switch (lbl_8064CCD4) {
    case 4:
        lists = state->lists;
        offset = fn_801E8D24(lists[1]) * 2;
        offset = fn_801E8D24(state->lists[0]) + offset;
        offset *= sizeof(ScrollEntry);
        entry = (ScrollEntry*)((char*)state->entries + offset);
        fn_80157858(entry->range);
        steps = 0;
        current = fn_8010D36C(entry->range);
        frac = (float)(current - fn_80157858(entry->range)) / lbl_8064FE98;
        lbl_8064CCB8 += frac;
        if (frac < lbl_8064FE70) {
            entry->value += delta;
        } else {
            while (lbl_8064CCB8 >= lbl_8064FE70) {
                lbl_8064CCB8 -= lbl_8064FE70;
                steps++;
            }
            entry->value += delta * steps;
        }
        limit = fn_8010D36C(entry->range);
        entry->value = MIN(limit, MAX(entry->value, fn_80157858(entry->range)));
        pos.x = 0x140;
        pos.y = 0xA5;
        pos.z = entry->value;
        fn_801F69F0(&pos, out, 0);
        fn_8011F0E8(entry->object, out);

        shadow = (ScrollEntry*)((char*)state->shadows + offset);
        if (shadow->range != 0) {
            fn_80157858(shadow->range);
            pos.x = 0x140;
            pos.y = 0xA5;
            pos.z = shadow->value;
            if (frac < lbl_8064FE70) {
                shadow->value += delta;
            } else {
                shadow->value += delta * steps;
            }
            shadow->value = MIN(limit, MAX(shadow->value, fn_80157858(shadow->range)));
            fn_801F69F0(&pos, out, 0);
            fn_8011F0E8(shadow->object, out);
        }
        break;
    case 3:
    case 5:
        break;
    case 2:
        lists = state->lists;
        oldPage = fn_801E8D3C(lists[4]) * 2;
        oldLine = fn_801E8D34(lists[4]) * 2;
        fn_801E8B6C(lists[4], delta);
        newPage = fn_801E8D3C(lists[4]) * 2;
        newLine = fn_801E8D34(lists[4]) * 2;
        if (oldPage != newPage) {
            fn_80117EF0();
            lbl_8064CCC4 = fn_8010A32C(newPage, 0, 6);
        }
        if (newLine != oldLine) {
            fn_801E5FB0(lbl_8064CCC8);
            lbl_8064CCC8 = 0;
        }
        break;
    case 1:
        lists = state->lists;
        fn_801E8B6C(lists[2], delta);
        break;
    case 0:
        lists = state->lists;
        oldPage = fn_801E8D3C(lists[1]) * 2;
        oldLine = fn_801E8D34(lists[1]) * 2;
        fn_801E8B6C(lists[1], delta);
        if (lbl_8064CCC4 != 0) {
            newPage = fn_801E8D3C(lists[1]) * 2;
            newLine = fn_801E8D34(lists[1]) * 2;
            if (oldPage != newPage) {
                fn_80117EF0();
                lbl_8064CCC4 = fn_8010A32C(newPage, 0, 6);
            }
            if (newLine != oldLine) {
                fn_801E5FB0(lbl_8064CCC8);
                lbl_8064CCC8 = 0;
            }
        }
        break;
    }
}
