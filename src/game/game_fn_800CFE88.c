extern int fn_800A4F98(int);
extern void *fn_80201814();
extern int fn_80201EB8(void *);

int fn_800CFE88(void *object)
{
    int result = 0;
    void *other;

    if (fn_800A4F98(0) != 0) {
        other = fn_80201814();
        if (other != 0) {
            int object_id = fn_80201EB8(object);
            int other_id = fn_80201EB8(other);
            result = object_id == other_id;
        }
    }
    return result;
}
