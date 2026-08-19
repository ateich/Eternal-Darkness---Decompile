typedef struct Root {
    char pad0[0x18];
    int* values;
} Root;

typedef struct Object {
    Root* root;
    char pad4[8];
    int allocator;
    int count;
} Object;

extern signed char lbl_8024F3AC[];
extern char lbl_8024F2D4[];
extern unsigned fn_8015EAA0(Object*);
extern void fn_8015EC60(Object*, int);
extern void fn_8015F8B4(Object*);
extern int* fn_8016393C(int, int*, int, int, int, void*, unsigned int);

int fn_8015F9D4(Object* object, int type, int a, int b)
{
    unsigned value = fn_8015EAA0(object);
    int delta = lbl_8024F3AC[type * 3 + 1] - lbl_8024F3AC[type * 3 + 2];
    int changed = 0;

    switch (type) {
    case 0: delta = 1 - b; break;
    case 1: delta = -b; break;
    case 2: if (b == 0) return -1; delta = -b; break;
    case 3: if (a == 0) return -1; delta = -(a * 2); break;
    case 4:
        if ((value & 0x3f) == 2 && ((value >> 6) & 0x1ff) == 0xff) {
            value = (value & ~0x7fc0) | (a << 6) | 3;
            changed = 1;
        }
        break;
    case 5:
        if (a == 0) return -1;
        if ((value & 0x3f) == 4) {
            value = (((value >> 6) + a) << 6) | 4;
            changed = 1;
        }
        delta = a;
        break;
    case 6:
        if (a == 0) return -1;
        delta = -a;
        if ((value & 0x3f) == 0x14) {
            value = (value & ~0x7fc0) | ((((value >> 6) & 0x1ff) + a) << 6);
            changed = 1;
        }
        break;
    case 7:
        if ((value & 0x3f) == 7) { value = (value & ~0x3f) | 0xe; changed = 1; }
        else if ((value & 0x3f) == 0xb) { value = (value & ~0x3f) | 0xf; changed = 1; }
        break;
    case 8:
        if ((value & 0x3f) == 6) { value = (value & ~0x3f) | 0x18; changed = 1; }
        break;
    case 9:
        if ((value & 0x3f) == 6) { value = ((0x1ffffff - ((value >> 6) - 0x1ffffff)) << 6) | 0x18; changed = 1; }
        break;
    case 10:
        delta = 1 - a;
        if ((value & 0x3f) == 0x1d) { value = (((value >> 6) + 1) << 6) | 0x1d; changed = 1; }
        break;
    }

    fn_8015EC60(object, delta);
    if (changed) {
        object->root->values[object->count - 1] = value;
        return object->count - 1;
    }

    switch (lbl_8024F3AC[type * 3]) {
    case 0: value = type; break;
    case 1: value = type | (a << 6); break;
    case 2: value = type | ((a + 0x1ffffff) << 6); break;
    case 3: value = type | (a << 15) | (b << 6); break;
    }
    fn_8015F8B4(object);
    object->root->values = fn_8016393C(object->allocator, object->root->values,
                                       object->count, 1, 4, lbl_8024F2D4,
                                       0x7ffffffd);
    object->root->values[object->count++] = value;
    return object->count - 1;
}
