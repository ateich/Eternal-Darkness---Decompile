typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct TransformData {
    float unused[2];
    float position[3];
    float direction[3];
} TransformData;

/* Honest reconstruction; paired-single u16 conversion remains unmatched. */
void fn_8011F140(void* object, int index, TransformData* output)
{
    u8* owner = *(u8**)((u8*)object + 60);
    u8* record = *(u8**)(owner + 188) + index * 28;

    output->position[0] = (float)*(s16*)(record + 8) * 4.0f * 0.0625f;
    output->position[1] = (float)*(s16*)(record + 10) * 4.0f * 0.0625f;
    output->position[2] = (float)*(s16*)(record + 12) * 4.0f * 0.0625f;
    output->direction[0] = (float)*(u16*)(record + 14);
    output->direction[1] = (float)*(u16*)(record + 16);
    output->direction[2] = (float)*(u16*)(record + 18);
    if (output->direction[0] == 0.0f && output->direction[1] == 0.0f &&
        output->direction[2] == 0.0f) {
        output->direction[1] = 1.0f;
    }
}
