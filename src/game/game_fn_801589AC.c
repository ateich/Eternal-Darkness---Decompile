typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct FrameRecord {
    int field00;
    Vec3 position;
    char pad10[8];
    float value18;
    Vec3 direction;
} FrameRecord;

extern FrameRecord* fn_80158A44(int, int);

int fn_801589AC(int index, int key, Vec3* position, Vec3* direction,
                float* value)
{
    int found = 0;
    FrameRecord* record = fn_80158A44(index, key);

    if (record != 0) {
        found = 1;
        position->x = record->position.x;
        position->y = record->position.y;
        position->z = record->position.z;
        direction->x = record->direction.x;
        direction->y = record->direction.y;
        direction->z = record->direction.z;
        *value = record->value18;
    }
    return found;
}
