extern int fn_8016A5F4(void*, int);

int fn_8016A650(void* context, int index)
{
    int type = fn_8016A5F4(context, index);
    return type == 2 || type == 3;
}
