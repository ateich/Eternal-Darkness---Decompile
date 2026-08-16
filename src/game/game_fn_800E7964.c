extern int fn_80200C20(void *);
extern int fn_80201B44(void);
extern void *fn_80201814(int);
extern int fn_80201B5C(void *);
extern unsigned char *fn_80201B8C(void *);

int fn_800E7964(void *object)
{
    int id = fn_80200C20(object);
    int result = 0;

    if (id == fn_80201B44()) {
        void *current = fn_80201814(id);
        result = 1;
        if (current != 0 && fn_80201B5C(current) == 50 && fn_80201B8C(current)[0x9F] == 6) {
            result = 0;
        }
    }
    return result;
}
