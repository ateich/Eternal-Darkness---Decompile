typedef unsigned char u8;

extern u8 lbl_80248730[];

/* NonMatching: size-exact honest C at 84.0% (120/120 bytes). The nine
 * comparisons and early returns agree; MWCC folds pointer increments into
 * fixed offsets instead of retail's sequence of update-form byte loads. */
void fn_800C3958(void *unused, u8 value)
{
    u8 *entry = lbl_80248730;

    if (value == *entry++) return;
    if (value == *entry++) return;
    if (value == *entry++) return;
    if (value == *entry++) return;
    if (value == *entry++) return;
    if (value == *entry++) return;
    if (value == *entry++) return;
    if (value == *entry++) return;
    if (value == *entry) return;
}
