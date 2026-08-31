typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Record {
    unsigned char pad00[0x50];
    Vec3 position;
    unsigned char pad5C[0x28];
    unsigned short kind;
    unsigned short id;
    unsigned char pad88[7];
    signed char active;
    unsigned char pad90[8];
} Record;

extern Record lbl_806080E0[80];

int fn_801AAD58(unsigned short id, unsigned short kind, const Vec3* position)
{
    Record* record;
    int i;

    record = lbl_806080E0;
    i = 0;
    while (i < 80) {
        if (record->active != 0) {
            if (record->active != 4) {
                if (record->id == id && record->kind == kind &&
                    record->position.x == position->x &&
                    record->position.y == position->y &&
                    record->position.z == position->z) {
                    return 1;
                }
            }
        }
        i++;
        record++;
    }
    return 0;
}
