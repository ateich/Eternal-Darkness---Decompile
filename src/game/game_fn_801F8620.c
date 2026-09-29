typedef struct SavedState {
    float first_value;
    float second_value;
    unsigned int first_handle;
    unsigned int second_handle;
    unsigned int token;
} SavedState;

typedef struct LiveState {
    unsigned char pad0[0x30];
    float value;
    unsigned char pad34[0x3C];
    unsigned int handle;
    unsigned char pad74[0x14];
} LiveState;

typedef struct Globals {
    unsigned char pad0[0xCC0];
    LiveState first;
    LiveState second;
    SavedState saved[1];
} Globals;

extern Globals lbl_8063C6B8;
extern volatile int lbl_8064D7BC;
extern unsigned int fn_801FA44C(void);

/* Keep the two live-state reads together before storing their handles. */
static inline void snapshot(volatile SavedState* saved,
                            volatile LiveState* first,
                            volatile LiveState* second)
{
    float first_value = first->value;
    unsigned int first_handle = first->handle;
    float second_value;
    unsigned int second_handle;

    saved->first_value = first_value;
    second_value = second->value;
    second_handle = second->handle;
    saved->second_value = second_value;
    saved->first_handle = first_handle;
    saved->second_handle = second_handle;
}

void fn_801F8620(void)
{
    volatile Globals* globals = &lbl_8063C6B8;
    volatile SavedState* saved;
    volatile LiveState* first;
    volatile LiveState* second;
    int count;

    saved = globals->saved;
    count = lbl_8064D7BC;
    saved = &saved[count];
    first = &globals->first;
    lbl_8064D7BC = count + 1;
    second = &globals->second;
    snapshot(saved, first, second);
    saved->token = fn_801FA44C();
}
