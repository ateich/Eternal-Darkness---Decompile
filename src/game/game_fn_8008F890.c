typedef struct SceneEntry {
    unsigned char pad[0xE];
    short value;
} SceneEntry;

extern SceneEntry lbl_8031D3F8[][2][4];
extern int lbl_8064C560;
extern int lbl_8064C564;
extern int lbl_8064C578;

extern void fn_800DD314(void*, int, int, int);
extern void fn_800DD050(void);
extern void fn_8008F860(void*);
extern void fn_8020104C(int, void*, void*, int, float);
extern void fn_80201D2C(void*, int);
extern void fn_80201D14(void*, int);

void fn_8008F890(void* object, void* actor)
{
    short value;

    fn_800DD314(object, 15, 255, 0);
    fn_800DD050();
    value = lbl_8031D3F8[lbl_8064C578][lbl_8064C560][lbl_8064C564].value;
    fn_8008F860(actor);
    fn_8020104C(23, actor, actor, -1, (float)value);
    fn_80201D2C(object, 1);
    fn_80201D14(object, 1);
}
