typedef unsigned char u8;
typedef unsigned int u32;

typedef struct InputEntry {
    u32 bit;
    u8 pad[8];
    u8 active;
    u8 tail[3];
} InputEntry;

extern InputEntry lbl_80251140[3][4];
extern u32 lbl_80251200[3];
extern void fn_801A68C4(void*);

void fn_801A67C4(void* state, u32 mask)
{
    unsigned char* data = state;
    int group;
    int entry;

    if (*(int*)(data + 0x98) != 0) {
        for (group = 0; group < 3; group++) {
            lbl_80251200[group] = 0;
            for (entry = 0; entry < 4; entry++) {
                InputEntry* item = &lbl_80251140[group][entry];
                if (mask & (1 << item->bit)) {
                    item->active = 1;
                    lbl_80251200[group]++;
                } else {
                    item->active = 0;
                }
            }
        }
        fn_801A68C4(state);
    }
}
