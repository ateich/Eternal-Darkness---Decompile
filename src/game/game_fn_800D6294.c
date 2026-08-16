typedef struct Actor {
    unsigned char pad_000[0x25c];
    signed char field_25c;
} Actor;

extern Actor *fn_800A1D28(void *);
extern int fn_8011F130(void *);
extern int fn_800A4DD4(void *, int, int, int);

int fn_800D6294(void *object, void *other, int value)
{
    int result = 0;
    Actor *actor = fn_800A1D28(object);

    if (actor->field_25c == 0) {
        result = fn_800A4DD4(object, fn_8011F130(other), value, 120);
    }
    return result;
}
