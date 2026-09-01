typedef unsigned char u8;

typedef struct Event Event;
typedef struct List {
    u8 pad00[0x1C];
    Event* head;
} List;

extern u8* lbl_8064D380;
extern Event* fn_801B443C(u8);
extern void fn_801B4654(List*, Event*);

void fn_801B4E48(void)
{
    unsigned int i;
    Event* event;
    u8* state = lbl_8064D380;

    if (*(u8**)(state + 0x14E4) == 0) {
        for (i = 0; i < 0x40; i++) {
            event = fn_801B443C((u8)i);
            if (event != 0)
                fn_801B4654((List*)(lbl_8064D380 + 0x14E8), event);
        }
    } else {
        for (i = 0; i < 0x40; i++) {
            event = fn_801B443C((u8)i);
            if (event != 0) {
                state = lbl_8064D380;
                fn_801B4654((List*)(state + 0x14E8 +
                                    (*(u8**)(state + 0x14E4))[i] * 0x38),
                            event);
            }
        }
    }
}
