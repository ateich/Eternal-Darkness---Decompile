extern void fn_8012B344();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

typedef struct Data8008E3D8 {
    unsigned char pad0[0xc];
    void* valueC;
    void* value10;
    void* value14;
} Data8008E3D8;

void fn_8008E3D8(void* object, void* unused4, Data8008E3D8* data,
                 void* resource)
{
    data->value14 = 0;
    data->value10 = 0;
    data->valueC = 0;
    fn_8012B344(resource);
    fn_80201D2C(object, 1);
    fn_80201D14(object, 1);
}
