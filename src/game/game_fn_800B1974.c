typedef void (*Callback800B1974)(void);

extern Callback800B1974 lbl_8064CA1C;

void fn_800B1974(void)
{
    if (lbl_8064CA1C != 0) {
        lbl_8064CA1C();
    }
}
