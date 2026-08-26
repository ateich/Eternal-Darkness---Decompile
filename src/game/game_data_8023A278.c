typedef signed short s16;

typedef struct Coordinates {
    s16 first;
    s16 second;
    s16 third;
    s16 fourth;
} Coordinates;

typedef struct CoordinateTable {
    Coordinates entries[4];
} CoordinateTable;

/* MWCC schedules the consumer differently when this aggregate is const. */
__declspec(section ".rodata") CoordinateTable lbl_8023A278 = {
    {
        {0x0126, 0x002B, 0x0078, 0x0020},
        {0x00D9, 0x003E, 0x0048, 0x0020},
        {0x01A4, 0x003E, 0x0056, 0x0020},
        {0x0124, 0x0057, 0x0079, 0x0020},
    },
};
