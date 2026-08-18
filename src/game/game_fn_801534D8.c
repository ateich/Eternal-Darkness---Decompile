typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct QueryResult {
    unsigned char pad[8];
    Vec3 position;
    unsigned char tail[20];
} QueryResult;

extern void* fn_80201BC8(void*);
extern void fn_8011F6A4(void*, int, int, int, QueryResult*, int);
extern void fn_8017970C(Vec3*, Vec3*, Vec3*, float);

void fn_801534D8(void* object, float fraction, short* rotation)
{
    QueryResult first;
    QueryResult second;
    Vec3 first_position;
    Vec3 second_position;
    Vec3 result;
    void* state;
    float saved_fraction;
    short* saved_rotation;

    saved_fraction = fraction;
    saved_rotation = rotation;
    state = fn_80201BC8(object);
    fn_8011F6A4(state, 21, 15, -1, &first, 1);
    fn_8011F6A4(state, 22, 15, -1, &second, 1);
    first_position.x = first.position.x;
    first_position.y = first.position.y;
    first_position.z = first.position.z;
    second_position.x = second.position.x;
    second_position.y = second.position.y;
    second_position.z = second.position.z;
    fn_8017970C(&first_position, &second_position, &result, saved_fraction);
    saved_rotation[0] = (short)result.x;
    saved_rotation[1] = (short)result.y;
    saved_rotation[2] = (short)result.z;
}
