typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Progress {
    u8 pad[4];
    u16 limit;
    u16 current;
    u8 active;
} Progress;

extern void fn_8011FA8C(void *, int, int);
extern void fn_8011F0C0(void *, float, float, float);
extern float lbl_8064F418;
extern float lbl_8064F424;

void fn_800D8AD8(void *unused, void *object, Progress *progress)
{
    (void)unused;
    if (progress->active != 0) {
        if (progress->current == 0) {
            fn_8011FA8C(object, 0, 0x800);
        }
        if (progress->current == progress->limit) {
            fn_8011FA8C(object, 0x800, 0);
        } else {
            fn_8011F0C0(object, lbl_8064F418, lbl_8064F418, lbl_8064F424);
        }
    }
}
