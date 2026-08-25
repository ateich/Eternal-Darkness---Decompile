extern int lbl_8064A98C[];
extern int fn_8017BB60(void);
extern int fn_8017BB98(void);
extern int fn_8021EB20(int);
extern int fn_8017B8AC(void);
extern int fn_8017B904(void);

float fn_8017B4F4(int index)
{
    float value;
    int elapsed;
    int base;

    switch (fn_8017BB60()) {
    case 1:
    case 4:
        elapsed = fn_8021EB20(index);
        base = lbl_8064A98C[index];
        value = (elapsed - base) / 60.0f;
        break;
    case 5:
    case 8:
        elapsed = fn_8021EB20(index);
        base = lbl_8064A98C[index];
        value = (elapsed - base) / 30.0f;
        break;
    case 6:
        value = fn_8017B8AC();
        elapsed = fn_8021EB20(index);
        base = lbl_8064A98C[index];
        value = (elapsed - base) / value;
        break;
    case 7:
        value = fn_8017B904();
        elapsed = fn_8021EB20(index);
        base = lbl_8064A98C[index];
        value = (elapsed - base) / value;
        break;
    default:
        value = 1.0f;
        break;
    }

    if (fn_8017BB98() == 0) {
        value = 0.0f;
    }
    if (value > 1.0f) {
        value = 1.0f;
    }
    if (value < 0.0f) {
        value = 0.0f;
    }
    return value;
}
