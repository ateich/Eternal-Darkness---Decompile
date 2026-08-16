typedef struct VaList {
    signed char gpr;
    signed char fpr;
    char *input_arg_area;
    char *reg_save_area;
} VaList;

void *__va_arg(VaList *list, int type)
{
    signed char *counter = &list->gpr;
    int index = list->gpr;
    int limit = 8;
    int size = 4;
    int step = 1;
    int round = 0;
    int save_offset = 0;
    int alignment = 4;
    char *result;

    if (type == 3) {
        counter = &list->fpr;
        index = list->fpr;
        size = 8;
        save_offset = 32;
        alignment = 8;
    }
    if (type == 2) {
        size = 8;
        limit = 7;
        if (index & 1) {
            round = 1;
        }
        step = 2;
    }
    if (index < limit) {
        index += round;
        *counter = index + step;
        result = list->reg_save_area + save_offset + index * alignment;
    } else {
        *counter = 8;
        result = (char *)(((unsigned int)(list->input_arg_area + size - 1)) & ~(size - 1));
        list->input_arg_area = result + size;
    }
    if (type == 0) {
        result = *(char **)result;
    }
    return result;
}
