typedef unsigned short u16;
typedef unsigned int u32;

extern u32 lbl_8064D18C;
extern void fn_801AAE68(int, int, int, float, void*, int, int, int, u16, int);

void fn_801AC8AC(int sound, int volume, u32 intensity, void* position)
{
    fn_801AAE68(sound, volume, 0, (float)intensity, position, 1, 1, 0,
                (u16)lbl_8064D18C, 0);
}
