typedef struct Entry80201814 Entry80201814;
typedef struct Object Object;
typedef struct Owner Owner;
typedef struct State State;
typedef struct Object800A4A60 Object800A4A60;

typedef struct ObjectDefinition {
    unsigned char pad[0x9E];
    unsigned char category;
    unsigned char subtype;
} ObjectDefinition;

extern int fn_80201A84(void *object);
extern Entry80201814 *fn_80201814(int id);
extern void *fn_80201B8C(unsigned char *object);
extern void fn_80007C48(void *object);
extern void fn_80045CE0(void *object);
extern void fn_80125EB8(Owner *owner, unsigned int enabled);
extern unsigned int fn_8011FA8C(void *object, unsigned int clear, unsigned int set);
extern void fn_801303F0(Object *object, int id, int index, float first, float second);
extern void fn_800A4A60(void *object, Object800A4A60 *definition);
extern int fn_8011EB04(Object *object);
extern void *fn_8011FB4C(void *object);
extern int fn_801E79FC(unsigned int *set, unsigned int index);
extern void fn_8012C478(State *object, int index, int enabled);
extern int fn_800CC2D8(void *object, int group);
extern unsigned int *lbl_8064C4E0;
extern float lbl_8064E35C;
extern float lbl_8064E360;
extern float lbl_8064E364;
extern float lbl_8064E368;

void fn_80045DBC(void *object)
{
    Entry80201814 *entry;
    ObjectDefinition *definition;
    int kind;

    entry = fn_80201814(fn_80201A84(object));
    if (entry == 0)
        return;
    definition = fn_80201B8C((unsigned char *)entry);
    if (definition == 0)
        return;

    switch (definition->category) {
    case 1:
        fn_80007C48(object);
        fn_80125EB8(object, 1);
        break;
    case 2:
        fn_80045CE0(object);
        switch (definition->subtype) {
        case 3:
            fn_8011FA8C(object, 0, 0x80000000U);
            fn_801303F0(object, 1, 0, lbl_8064E35C, lbl_8064E360);
            fn_801303F0(object, 0, 1, lbl_8064E364, lbl_8064E368);
            break;
        case 37:
            fn_8011FA8C(object, 0, 0x80000000U);
            fn_801303F0(object, 1, 0, lbl_8064E35C, lbl_8064E360);
            fn_801303F0(object, 0, 1, lbl_8064E364, lbl_8064E368);
            break;
        case 4:
            fn_8011FA8C(object, 0, 0x80000000U);
            fn_801303F0(object, 0, 0, lbl_8064E364, lbl_8064E368);
            break;
        case 10:
        case 5:
            fn_801303F0(object, 1, 0, lbl_8064E35C, lbl_8064E360);
            fn_801303F0(object, 0, 1, lbl_8064E364, lbl_8064E368);
            break;
        case 13:
            fn_800A4A60(object, (Object800A4A60 *)definition);
            break;
        }
        break;
    case 3:
        kind = fn_8011EB04(object);
        /* This field holds a numeric identifier in this object category. */
        if ((int)fn_8011FB4C(object) == 0x53) {
            switch (kind) {
            case 0xE6:
                if (fn_801E79FC(lbl_8064C4E0, 0x275))
                    fn_8012C478(object, 15, 1);
                else
                    fn_8012C478(object, 15, 0);
                break;
            case 0x35:
                if (fn_801E79FC(lbl_8064C4E0, 0x344))
                    fn_8012C478(object, 15, 1);
                else
                    fn_8012C478(object, 15, 0);
                break;
            }
        }
        break;
    case 4:
        fn_80045CE0(object);
        switch (definition->subtype) {
        case 0x12:
            if ((unsigned char)fn_800CC2D8(object, 0))
                fn_8012C478(object, 16, 0);
            if ((unsigned char)fn_800CC2D8(object, 1))
                fn_8012C478(object, 17, 0);
            break;
        }
        switch (fn_8011EB04(object)) {
        case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25:
        case 0x27: case 0x28: case 0x29: case 0x2A: case 0x2B: case 0x2C:
            fn_8012C478(object, 8, 0);
            fn_8012C478(object, 9, 0);
            break;
        }
        break;
    }
}
