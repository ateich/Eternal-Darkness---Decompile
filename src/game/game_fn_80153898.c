extern int fn_800FBFB0(void);
extern void fn_801534D8(void*, float, short*);

void fn_80153898(void* object, short* rotation)
{
    float fraction = (float)(fn_800FBFB0() & 15) / 15.0f;
    fn_801534D8(object, fraction, rotation);
}
