typedef struct Entry {
    unsigned char prefix[124];
    unsigned int first;
    unsigned int second;
} Entry;

extern Entry lbl_8060B430[];
extern int fn_801ADAF8(unsigned int);

int fn_801ADB70(unsigned int id)
{
    unsigned int index;

    index = fn_801ADAF8(id);
    if (index != -1) {
        return lbl_8060B430[index].first + lbl_8060B430[index].second;
    }
    return -1;
}
