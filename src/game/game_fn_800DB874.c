typedef unsigned int u32;

typedef struct FourWords {
    u32 words[4];
} FourWords;

extern FourWords lbl_80239998;
extern void *fn_80201BC8();
extern void *fn_80201C24(void *);
extern void fn_8012B7A0(void *, float);
extern void fn_8012CDF0(void *, int, FourWords, int);
extern void fn_8012C198(void *);
extern void fn_8011FABC(void *, int, int);
extern void fn_8011FA8C(void *, int, int);
extern void fn_80157C98(void *, int, int);
extern float lbl_8064F464;

void fn_800DB874(void *context)
{
    FourWords value = lbl_80239998;
    void *object = fn_80201BC8(context);
    void *state = fn_80201C24(context);

    fn_8012B7A0(object, lbl_8064F464);
    fn_8012CDF0(object, 15, value, 1);
    fn_8012C198(object);
    fn_8011FABC(object, 0x48, 0);
    fn_8011FA8C(object, 0, 0x100);
    fn_80157C98(state, 0x100, 0);
}
