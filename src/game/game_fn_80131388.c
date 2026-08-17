extern int lbl_8064CF70;
extern int lbl_8064CF74;
extern int lbl_8064CF78;

void fn_80131388(int frames)
{
    int seconds = frames / 30;
    int minutes = seconds / 60;

    lbl_8064CF70 = minutes;
    lbl_8064CF78 = frames - seconds * 30;
    seconds -= minutes * 60;
    lbl_8064CF74 = seconds;
}
