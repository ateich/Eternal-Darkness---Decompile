extern int fn_8015EBDC(void*, int);
extern void fn_8015EB30(void*, int, int);

void fn_8015F2B0(void* object, int* head, int value)
{
    int index;

    if (*head == -1) {
        *head = value;
    } else {
        index = *head;
        while (1) {
            int next = fn_8015EBDC(object, index);
            if (next == -1) {
                fn_8015EB30(object, index, value);
                break;
            }
            index = next;
        }
    }
}
