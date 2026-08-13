typedef struct Inner { char pad_00[0x44]; int value; } Inner;
typedef struct ObjectData { char pad_00[0x8C]; Inner *inner; } ObjectData;

extern ObjectData *fn_80201B8C(void *);
extern void *fn_80201B54(void *);
extern void fn_8020123C(int, void *, int, int);

void fn_80070E98(void *object)
{
    int value = fn_80201B8C(object)->inner->value;
    if (value != 0) {
        fn_8020123C(0x52, fn_80201B54(object), value, 0);
    }
}
