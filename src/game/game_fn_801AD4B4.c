typedef unsigned short u16;

typedef struct EffectNode {
    struct EffectNode* next;
    int state;
    int object_id;
    int timer;
    int resource;
    int value;
    u16 tag;
} EffectNode;

extern int fn_800E45C0(void);
extern EffectNode* fn_801ACE30(int);

EffectNode* fn_801AD4B4(int object_id, int value, int resource, u16 tag)
{
    EffectNode* node = 0;

    if (object_id < fn_800E45C0() && object_id >= 0) {
        node = fn_801ACE30(1);
        if (node != 0) {
            node->object_id = object_id;
            node->resource = resource;
            node->tag = tag;
            node->value = value;
        }
    }
    return node;
}
