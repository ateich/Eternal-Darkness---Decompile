typedef signed short s16;

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

typedef struct HitResult {
    Coord3 position;
    unsigned char rest[12];
} HitResult;

typedef struct Shape {
    unsigned char bytes[64];
} Shape;

extern void* fn_8015C2FC(int);
extern void fn_80179B08(ShortCoord3*, Coord3*);
extern void fn_80179B64(Coord3*, ShortCoord3*);
extern void fn_8017DCA8(ShortCoord3*, s16, ShortCoord3*);
extern void fn_8013F3C0(Shape*, Coord3*, Coord3*, float);
extern int fn_8013FBE4(void*, Shape*, HitResult*, int, int);

int fn_8017E40C(ShortCoord3* position, s16 acceleration,
                ShortCoord3* velocity, float radius)
{
    Coord3 start;
    Coord3 end;
    Shape shape;
    HitResult hit;
    void* collision = fn_8015C2FC(2);
    int result;

    fn_80179B08(position, &start);
    fn_8017DCA8(position, acceleration, velocity);
    fn_80179B08(position, &end);
    fn_8013F3C0(&shape, &start, &end, radius);
    result = fn_8013FBE4(collision, &shape, &hit, 0, 0);
    if (result != 0) {
        fn_80179B64(&hit.position, position);
        return result;
    }
    return 0;
}
