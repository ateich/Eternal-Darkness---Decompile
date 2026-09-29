typedef signed short s16;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Record {
    char pad00[0x2C];
    s16 position[3];
    char pad32[6];
    Vec3 angles;
    float scale;
} Record;

extern Record* fn_80158C0C(int, int);

int fn_80158B20(int index, int key, Vec3* position, Vec3* angles, float* scale)
{
    int result = 0;
    Record* record = fn_80158C0C(index, key);

    if (record != 0) {
        position->x = (float)record->position[0];
        position->y = (float)record->position[1];
        position->z = (float)record->position[2];
        if (angles != 0) {
            angles->x = record->angles.x;
            angles->y = record->angles.y;
            angles->z = record->angles.z;
        }
        if (scale != 0) {
            *scale = record->scale;
        }
        result = 1;
    }
    return result;
}
