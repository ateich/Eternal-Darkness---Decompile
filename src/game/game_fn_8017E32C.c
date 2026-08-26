typedef signed short s16;
typedef unsigned char u8;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

extern void fn_80179B08(ShortCoord3*, Coord3*);
extern void fn_80179B64(Coord3*, ShortCoord3*);
extern int fn_8017E4E4(Coord3*, Coord3*, float, float, float, float);

int fn_8017E32C(ShortCoord3* first, s16 third_arg, ShortCoord3* second,
                u8 fifth_arg, float fourth_arg)
{
    Coord3 first_coord;
    Coord3 second_coord;
    int result;

    fn_80179B08(first, &first_coord);
    fn_80179B08(second, &second_coord);
    result = fn_8017E4E4(&first_coord, &second_coord, (float)third_arg,
                         fourth_arg, (float)fifth_arg, 0.92f);
    fn_80179B64(&first_coord, first);
    fn_80179B64(&second_coord, second);
    return result;
}
