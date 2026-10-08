typedef struct Manager {
    char pad_0[0x34];
    int value_34;
} Manager;

typedef struct Batch Batch;

typedef struct GameState {
    char pad_0[0x1C8];
    int selected;
} GameState;

extern GameState lbl_8030F540;
extern int lbl_8064CF6C;

extern Manager* fn_8015E4A4(void);
extern Batch* fn_8015E1A8(int);
extern Batch* fn_80132794(Manager*, Batch*);
extern Batch* fn_80131E8C(Manager*, Batch*);
extern void fn_8013310C(Batch*);
extern void fn_80132B24(Batch*, int);
extern void fn_80132DD0(Batch*, int);
extern void fn_80133C20(Manager*, Batch*);

void fn_80134BFC(void)
{
    int selected = lbl_8030F540.selected >> 1;
    Manager* manager = fn_8015E4A4();
    Batch* batch = fn_8015E1A8(selected);

    fn_80132794(manager, batch);
    fn_80131E8C(manager, batch);
    fn_8013310C(batch);
    fn_80132B24(batch, manager->value_34 - selected);
    fn_80132DD0(batch, selected);
    lbl_8064CF6C = 1;
    fn_80133C20(manager, batch);
}
