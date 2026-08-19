typedef struct Record {
    unsigned int words[22];
} Record;

extern Record* fn_801E880C(void*, int, int);
extern Record* fn_8017CDB4(void*);
extern void* lbl_8064D104;
extern void* lbl_8064D10C;

Record* fn_801576C4(int index, int value)
{
    Record* source;
    Record* destination;

    if (index < 0) {
        return 0;
    }
    source = fn_801E880C(lbl_8064D104, index, value);
    destination = fn_8017CDB4(lbl_8064D10C);
    *destination = *source;
    return destination;
}
