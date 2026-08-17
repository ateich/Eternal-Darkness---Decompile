typedef struct Record {
    int key;
    int value;
    int data;
} Record;

typedef struct Allocation {
    int index;
    int count;
    Record* records;
} Allocation;

extern Allocation** lbl_8064CFF0;
extern void fn_80139E04(void*, int, int, int, int);

int fn_80139D10(unsigned char* object, int key)
{
    Allocation* allocation = lbl_8064CFF0[*(int*)(object + 0x244)];
    int found = 0;
    Record* record = allocation->records;
    int i;

    for (i = 0; i < allocation->count; i++, record++) {
        if (record->key == key) {
            fn_80139E04(object, record->value, (int)(allocation + 1), record->data, 0xAA);
            found = 1;
            break;
        }
    }
    return found;
}
