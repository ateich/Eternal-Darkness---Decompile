extern unsigned int lbl_8024E388[];
extern int fn_801E7AD0(unsigned int*, int, int);

unsigned int fn_801116A4(unsigned int count)
{
    unsigned int i;
    unsigned int present = 0;

    for (i = 0; i < count; i++) {
        if (fn_801E7AD0(lbl_8024E388, 3, i) != 0) {
            present++;
        }
    }
    return present;
}
