typedef unsigned char u8;

typedef struct Sample Sample;
struct Sample {
    Sample* next;
    u8 pad04[0xC];
    float x;
    float y;
    float z;
};

typedef struct Target Target;
struct Target {
    Target* next;
    u8 pad04[8];
    float x;
    float y;
    float z;
    float mean_square_distance;
    u8 state;
};

extern Sample* lbl_8064D4C0;
extern Target* lbl_8064D4C4;
extern float lbl_80650FB0;

void fn_801C8160(void)
{
    Sample* sample;
    Target* target;
    unsigned int count;
    float delta[3];
    float sum;

    count = 0;
    sample = lbl_8064D4C0;
    while (sample != 0) {
        sample = sample->next;
        count++;
    }

    if (count != 0) {
        target = lbl_8064D4C4;
        while (target != 0) {
            if (target->state != 0xFF) {
                sum = lbl_80650FB0;
                sample = lbl_8064D4C0;
                while (sample != 0) {
                    delta[0] = target->x - sample->x;
                    delta[1] = target->y - sample->y;
                    delta[2] = target->z - sample->z;
                    sample = sample->next;
                    sum += delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
                }
                target->mean_square_distance = sum / count;
            }
            target = target->next;
        }
    }
}
