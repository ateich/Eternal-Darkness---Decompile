typedef struct Event {
    unsigned char pad[0x14];
    void* object;
} Event;

extern void *fn_80201814();
extern void fn_8012B344();
extern void fn_80201D34(void*, int);
extern void fn_80201D1C(void*, int);
extern unsigned int fn_80036D5C(void*);
extern void fn_80036DA4(void*, unsigned int);

void fn_8008EF28(void* object, void* actor, Event* event)
{
    void* target = fn_80201814(event->object);

    fn_8012B344(actor);
    fn_80201D34(object, 73);
    fn_80201D1C(object, 1);
    if (target != 0) {
        fn_80036DA4(target, fn_80036D5C(target) | 0x80000);
    }
}
