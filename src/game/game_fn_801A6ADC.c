typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct InputEntry {
    int value;
    s16 first;
    s16 pad;
    s16 second;
    u8 tail[2];
    u8 active;
    u8 rest[3];
} InputEntry;

extern InputEntry lbl_80251140[3][4];
extern int lbl_80251200[3];

void fn_801A6ADC(void* state)
{
    u8* data = state;
    int group;
    int result = -1;
    s16 position;
    int index;

    if (lbl_80251200[0] == 0 && lbl_80251200[1] == 0 &&
        lbl_80251200[2] == 0) {
        return;
    }

    group = -1;
    position = *(s16*)(data + 0xB0);
    switch (*(u16*)(data + 0xAC)) {
    case 2:
        group = 2;
        break;
    case 4:
        group = 0;
        break;
    case 1:
        group = 1;
        break;
    case 8:
    case 16:
        group = 1;
        break;
    }

    if (lbl_80251200[group] > 0) {
        InputEntry* entries = lbl_80251140[group];
        for (index = 0; index < 4; index++) {
            InputEntry* entry = &entries[index];
            if (entry->active != 0 && position >= entry->first &&
                position <= entry->second) {
                result = entries[index].value;
                break;
            }
        }
    }
    *(int*)(data + 0xA4) = result;
}
