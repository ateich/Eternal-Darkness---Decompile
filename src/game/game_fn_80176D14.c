typedef unsigned int u32;

typedef struct PacketTemplate {
    u32 word0;
    u32 word1;
    u32 word2;
} PacketTemplate;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201BC8();
extern void fn_80205868(void*, int, const PacketTemplate*, int);
extern const char lbl_8024FF00[];
extern const PacketTemplate lbl_8023A988;

int fn_80176D14(void* state)
{
    PacketTemplate packet;
    int first;
    int second;
    void* object;

    if (fn_8016A598(state) != 2) {
        fn_80163BB4(state, lbl_8024FF00, 2, fn_8016A598(state));
        return 0;
    }

    first = (int)fn_8016A694(state, 1);
    second = (int)fn_8016A694(state, 2);
    object = fn_80201814(first);
    if (object != 0) {
        object = fn_80201BC8(object);
        if (object != 0) {
            packet = lbl_8023A988;
            fn_80205868(object, second, &packet, 0x2000);
        }
    }
    return 0;
}
