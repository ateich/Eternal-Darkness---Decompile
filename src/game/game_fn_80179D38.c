typedef signed char s8;

typedef struct Coord2 {
    float x;
    float y;
} Coord2;

typedef struct Coord3 {
    float x;
    float y;
    float z;
} Coord3;

typedef struct Coord2List {
    int count;
    Coord2* entries;
} Coord2List;

extern void fn_80179C10(Coord3*, const Coord3*, float, float, float, s8);

void fn_80179D38(Coord3* destination, float constant, const Coord2List* list,
                 unsigned int index, const Coord3* plane, s8 axis)
{
    fn_80179C10(destination, plane, list->entries[index].x,
                list->entries[index].y, constant, axis);
}
