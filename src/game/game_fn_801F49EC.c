typedef struct Vec3Source {
    unsigned int words[3];
} Vec3Source;

typedef struct Vec3Destination {
    unsigned int words[3];
} Vec3Destination;

extern Vec3Destination lbl_802FC678;
extern float lbl_8064C394;
extern float lbl_8064C398;

void fn_801F49EC(volatile Vec3Source* value, float first, float second)
{
    unsigned int x = value->words[0];
    unsigned int y = value->words[1];
    unsigned int z = value->words[2];

    lbl_802FC678.words[0] = x;
    lbl_802FC678.words[1] = y;
    lbl_802FC678.words[2] = z;
    lbl_8064C394 = first;
    lbl_8064C398 = second;
}
