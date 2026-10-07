typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct TriggerEntry {
    u8 pad00[0x2C];
    u32 object;
    u8 pad30[0x38];
    u32 flags;
    s16 type;
    u8 pad6E[6];
} TriggerEntry;

typedef struct ObjectEntry {
    u32 object;
    u8 pad04[0x38];
} ObjectEntry;

extern ObjectEntry *fn_8015C5E4(int selector, u16 *count);
extern TriggerEntry *fn_8015C5A0(int selector, u16 *count);
extern void *fn_80201BC8(void *object);
extern int fn_8013B8C0(void *state, TriggerEntry *entry);
extern void fn_800475E8(void *state, u32 object);

void fn_80047700(void *object, u32 flags)
{
    u16 objectCount;
    u16 triggerCount;
    ObjectEntry *objects;
    TriggerEntry *triggers;
    void *state;
    u16 triggerIndex;
    TriggerEntry *trigger;

    if (object == 0)
        return;
    objects = fn_8015C5E4(2, &objectCount);
    if (objects == 0)
        return;
    triggers = fn_8015C5A0(2, &triggerCount);
    if (triggers == 0)
        return;
    state = fn_80201BC8(object);
    for (triggerIndex = 0; triggerIndex < triggerCount; triggerIndex++) {
        u16 objectIndex;
        u32 objectValue;
        trigger = &triggers[triggerIndex];
        if ((flags & trigger->flags) && trigger->type == 1) {
            for (objectIndex = 0; objectIndex < objectCount; objectIndex++) {
                objectValue = objects[objectIndex].object;
                if (objectValue == trigger->object &&
                    fn_8013B8C0(state, trigger) != 0) {
                    fn_800475E8(state, objects[objectIndex].object);
                }
            }
        }
    }
}
