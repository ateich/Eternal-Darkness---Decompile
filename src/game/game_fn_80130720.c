/*
 * Honest-C recovery of the cutscene/state-transition routine.  The retail
 * function is dominated by ordered subsystem calls and small stack color
 * values.  This reconstruction intentionally stays NonMatching while those
 * types and the exact MWCC scheduling are recovered.
 */
typedef unsigned char u8;
typedef struct Object Object;

extern int lbl_8064CF30;
extern Object* lbl_8064C4E4;
extern u8 lbl_802FC53C[];
extern float lbl_805AADC8[];
extern void fn_80125ECC(void *);
extern void fn_801ED468(int);
extern void fn_80226D28(int);
extern void fn_801ED118(void);
extern void fn_801EDA7C(void*, int, int, int);
extern void fn_801ECF50(int);
extern void fn_80226C18(int, int);
extern void fn_801ECD74(void*);
extern void fn_80226AB4(int, int, int);
extern void fn_80130980(void);
extern void fn_80130984(float, float, float);

static void emit3(const float* value)
{
    fn_80130984(value[0], value[1], value[2]);
}

void fn_80130720(Object* object)
{
    u8 color[4];

    fn_80125ECC(object);
    if (lbl_8064CF30 == 0 || object != lbl_8064C4E4) {
        return;
    }

    fn_801ED468(27);
    fn_80226D28(0);
    fn_801ED118();
    fn_801EDA7C(lbl_802FC53C, 0, 703, 0);
    fn_801ECF50(4);
    fn_80226C18(18, 0);

    color[0] = color[1] = color[2] = color[3] = 0xFF;
    fn_801ECD74(color);
    fn_80226AB4(168, 3, 2);

    /* Remaining retail work emits several paired vertices and state colors. */
    emit3(lbl_805AADC8 + 21);
    emit3(lbl_805AADC8 + 24);
    fn_80130980();
}
