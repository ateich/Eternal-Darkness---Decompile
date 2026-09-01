typedef unsigned char u8;

typedef struct VoiceUpdate {
    u8 pad[0x28];
    void* voice;
    u8 type;
} VoiceUpdate;

extern void fn_801B3770(void*);
extern void fn_801B35BC(void*);
extern void fn_801B3C14(void*, int, int);

void fn_801B7A10(VoiceUpdate* update)
{
    switch (update->type) {
    case 1:
        fn_801B3770(update->voice);
        break;
    case 2:
        fn_801B35BC(update->voice);
        break;
    case 3:
        fn_801B3C14(update->voice, 0, 0);
        break;
    }
}
