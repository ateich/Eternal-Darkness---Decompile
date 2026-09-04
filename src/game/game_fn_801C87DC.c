typedef unsigned int u32;

typedef struct Listener Listener;
typedef struct SoundPoint SoundPoint;
typedef struct Direction Direction;

struct Direction {
    float value[3];
    u32 pad;
};

struct Listener {
    char pad00[0x10];
    u32 flags;
    float position[3];
    float velocity[3];
    float radius;
    float inner;
    float outer;
    float curve;
};

struct SoundPoint {
    SoundPoint* next;
    char pad04[8];
    u32 flags;
    float position[3];
    float scale;
    float velocity[3];
    float offset[3];
    char pad38[0x18];
    float matrix[12];
    float negative_limit;
    float positive_limit;
    float distance_scale;
    float gain;
};

extern SoundPoint* lbl_8064D4C0;
extern float lbl_80650FB0;
extern double lbl_80650FB8;
extern float lbl_80650FC0;
extern double lbl_80650FC8;
extern float lbl_80650FD4;
extern double lbl_80650FD8;
extern float lbl_80650FE0;
extern double __frsqrte(double);

extern void fn_801CA3D8(float*, float*, float*);
extern void fn_801CA484(float*);

static float magnitude(float x, float y, float z, float zero,
                       double half, double three_halves)
{
    float value = x * x + y * y + z * z;
    double estimate;
    volatile float result;

    if (value > zero) {
        estimate = __frsqrte(value);
        estimate = half * estimate *
                   (three_halves - estimate * estimate * value);
        estimate = half * estimate *
                   (three_halves - estimate * estimate * value);
        estimate = half * estimate *
                   (three_halves - estimate * estimate * value);
        result = value * estimate;
        return result;
    }
    return value;
}

void fn_801C87DC(Listener* listener, float* gain, float* distance_mix,
                 float* direction_x, float* direction_y, float* vertical_mix)
{
    SoundPoint* point;
    u32 count;
    double half;
    float prediction_scale;
    double three_halves;
    float one;
    float zero;
    float vertical;
    float direction_y_sum;
    float direction_x_sum;
    float delta[3];

    count = 0;
    zero = lbl_80650FB0;
    vertical = zero;
    *gain = zero;
    one = lbl_80650FD4;
    *distance_mix = one;
    direction_y_sum = vertical;
    direction_x_sum = direction_y_sum;
    point = lbl_8064D4C0;
    prediction_scale = lbl_80650FE0;
    half = lbl_80650FC8;
    three_halves = lbl_80650FD8;

    while (point != 0) {
        float distance;
        delta[0] = listener->position[0] -
                   (point->position[0] + point->offset[0] * point->scale);
        delta[1] = listener->position[1] -
                   (point->position[1] + point->offset[1] * point->scale);
        delta[2] = listener->position[2] -
                   (point->position[2] + point->offset[2] * point->scale);
        distance = magnitude(delta[0], delta[1], delta[2], zero, half,
                             three_halves);

        if (listener->radius >= distance) {
            float ratio = distance / listener->radius;

            if (listener->curve >= zero) {
                float attenuation = one -
                    ((one - listener->curve) * ratio +
                     ratio * (listener->curve * ratio));
                *gain += point->gain *
                         (listener->outer +
                          (listener->inner - listener->outer) * attenuation);
            } else {
                float inverse = one - ratio;
                float attenuation = one -
                    ((one + listener->curve) * ratio -
                     listener->curve * (one - inverse * inverse));
                *gain += point->gain *
                         (listener->outer +
                          (listener->inner - listener->outer) * attenuation);
            }

            if ((listener->flags & 0x00080000) == 0 &&
                ((listener->flags & 8) != 0 || (point->flags & 1) != 0)) {
                float velocity_distance;
                delta[0] = point->velocity[0] - listener->velocity[0];
                delta[1] = point->velocity[1] - listener->velocity[1];
                delta[2] = point->velocity[2] - listener->velocity[2];
                velocity_distance = magnitude(delta[0], delta[1],
                                              delta[2], zero, half,
                                              three_halves);

                if (velocity_distance > zero) {
                    float projected_distance;
                    delta[0] = listener->position[0] + listener->velocity[0] * prediction_scale -
                               (point->position[0] + point->velocity[0] * prediction_scale);
                    delta[1] = listener->position[1] + listener->velocity[1] * prediction_scale -
                               (point->position[1] + point->velocity[1] * prediction_scale);
                    delta[2] = listener->position[2] + listener->velocity[2] * prediction_scale -
                               (point->position[2] + point->velocity[2] * prediction_scale);
                    projected_distance = magnitude(delta[0], delta[1],
                                                   delta[2], zero, half,
                                                   three_halves);

                    if (projected_distance < distance) {
                        *distance_mix = point->distance_scale /
                                        (point->distance_scale - velocity_distance);
                    } else {
                        *distance_mix = point->distance_scale /
                                        (point->distance_scale + velocity_distance);
                    }
                }
            }

            if (distance != zero) {
                Direction direction;
                fn_801CA3D8(point->matrix, listener->position, direction.value);
                if (direction.value[2] <= zero) {
                    if (-point->negative_limit < direction.value[2]) {
                        vertical += -direction.value[2] / point->negative_limit;
                    } else {
                        vertical += one;
                    }
                } else {
                    if (point->positive_limit > direction.value[2]) {
                        vertical += -direction.value[2] / point->positive_limit;
                    } else {
                        vertical += lbl_80650FC0;
                    }
                }
                if (direction.value[0] != zero ||
                    direction.value[1] != zero ||
                    direction.value[2] != zero) {
                    fn_801CA484(direction.value);
                }
                direction_x_sum += direction.value[0];
                direction_y_sum -= direction.value[1];
            }
        }
        point = point->next;
        count++;
    }

    if (count != 0) {
        *direction_x = direction_x_sum / count;
        *direction_y = direction_y_sum / count;
        *vertical_mix = vertical / count;
    }
}
