typedef struct Object Object;
typedef struct Object80201C2C Object80201C2C;
typedef struct Entry80201B3C Entry80201B3C;
typedef struct Node80204A94 Node;
typedef struct Node EventNode;
typedef struct Owner Owner;

extern void *fn_80201BC8(void *object);
extern int fn_8011EB04(Object *object);
extern int fn_8011EB1C(Object *object);
extern Entry80201B3C *fn_80201B3C(void);
extern void *fn_80201C2C(Object80201C2C *object);
extern int fn_80036E50(void *object);
extern Node *fn_80204A94(Node *node, void *object);
extern void *fn_80047D78(void);
extern void fn_80047FFC(int enabled);
extern int fn_801E855C(int kind, void *owner, EventNode **result);
extern void fn_801E8430(EventNode *node);
extern void fn_8007C13C(Owner *owner);
extern void fn_801E79A0(unsigned char *bits, unsigned int index);
extern unsigned char *lbl_8064C4E0;

void fn_800720C8(void *target)
{
    Object *data = fn_80201BC8(target);
    Object80201C2C *object;
    Node *owner;
    Node *node;
    int state;
    Owner *active;
    EventNode *event;

    if (fn_8011EB04(data) == 0x63 && fn_8011EB1C(data) == 4) {
        object = (Object80201C2C *)fn_80201B3C();
        if (object != 0) {
            owner = fn_80201C2C(object);
            if (owner != 0) {
                state = fn_80036E50(object);
                node = fn_80204A94(owner, target);
                if (state == 1 && node == 0) {
                    active = fn_80047D78();
                    event = 0;
                    fn_80047FFC(0);
                    if (fn_801E855C(0x14, active, &event) != 0) {
                        fn_801E8430(event);
                    }
                    fn_8007C13C(active);
                    fn_801E79A0(lbl_8064C4E0, 0x29A);
                }
            }
        }
    }
}
