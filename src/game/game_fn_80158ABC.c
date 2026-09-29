typedef struct Record {
    char pad00[0x2C];
    char payload[0x0C];
    float angles[3];
    float scale;
} Record;

extern Record* fn_80158C0C(int, int);
extern float fn_80179FE4(float*, int, float);

void* fn_80158ABC(int index, int key, float* value)
{
    void* result = 0;
    Record* record = fn_80158C0C(index, key);

    if (record != 0) {
        result = record->payload;
        if (value != 0) {
            *value = fn_80179FE4(record->angles, 1, record->scale);
        }
    }
    return result;
}
