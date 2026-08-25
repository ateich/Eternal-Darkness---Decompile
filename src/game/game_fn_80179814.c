typedef struct ShortCoord3 {
    short x;
    short y;
    short z;
} ShortCoord3;

typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

extern void fn_8017974C(ShortCoord3*, ShortCoord3*, Coord3*, float);
extern void fn_8017970C(Coord3*, Coord3*, Coord3*, float);

void fn_80179814(ShortCoord3* first, ShortCoord3* second,
                 ShortCoord3* third, ShortCoord3* fourth, Coord3* output,
                 float amount)
{
    Coord3 first_edge;
    Coord3 second_edge;
    Coord3 middle_edge;

    fn_8017974C(first, third, &first_edge, amount);
    fn_8017974C(fourth, second, &second_edge, amount);
    fn_8017974C(third, fourth, &middle_edge, amount);
    fn_8017970C(&first_edge, &middle_edge, &first_edge, amount);
    fn_8017970C(&middle_edge, &second_edge, &second_edge, amount);
    fn_8017970C(&first_edge, &second_edge, output, amount);
}
