extern void fn_8016A830(void*, double);
extern void fn_8016AB20(void*, const char*);
extern void fn_8016AA34(void*, const char*);
extern void fn_8016A694(void*, int);
extern void fn_8016A5B0(void*, int);

extern char lbl_80250588[];
extern const double lbl_80650710;
extern const double lbl_80650718;
extern const double lbl_80650720;
extern const double lbl_80650728;
extern const double lbl_80650730;
extern const double lbl_80650738;
extern const double lbl_80650740;
extern const double lbl_80650748;
extern const double lbl_80650750;
extern const double lbl_80650758;
extern const double lbl_80650760;
extern const double lbl_80650768;
extern const double lbl_80650770;
extern const double lbl_80650778;
extern const double lbl_80650780;
extern const double lbl_80650788;
extern const double lbl_80650790;
extern const double lbl_80650798;
extern const double lbl_806507A0;
extern const double lbl_806507A8;
extern const double lbl_806507B0;
extern const double lbl_806507B8;
extern const double lbl_806507C0;
extern const double lbl_806507C8;
extern const double lbl_806507D0;
extern const double lbl_806507D8;
extern const double lbl_806507E0;
extern const double lbl_806507E8;
extern const double lbl_806507F0;
extern const double lbl_806507F8;
extern const double lbl_80650800;
extern const double lbl_80650808;
extern const double lbl_80650810;
extern const double lbl_80650818;
extern const double lbl_80650820;
extern const double lbl_80650828;
extern const double lbl_80650830;
extern const double lbl_80650838;
extern const double lbl_80650840;
extern const double lbl_80650848;
extern const double lbl_80650850;
extern const double lbl_80650858;

#define REGISTER_CONSTANT(value, offset)               \
    do {                                               \
        if (flag == 0) {                               \
            fn_8016A830(context, value);               \
            fn_8016AB20(context, names + offset);      \
        } else {                                       \
            fn_8016AA34(context, names + offset);      \
            fn_8016A694(context, 1);                   \
            fn_8016A5B0(context, -2);                  \
        }                                              \
    } while (0)

void fn_80177434(void* state, int mode)
{
    char* names;
    int flag;
    void* context;

    names = lbl_80250588;
    flag = mode;
    context = state;

    REGISTER_CONSTANT(lbl_80650710, 0);
    REGISTER_CONSTANT(lbl_80650718, 16);
    REGISTER_CONSTANT(lbl_80650720, 32);
    REGISTER_CONSTANT(lbl_80650728, 48);
    REGISTER_CONSTANT(lbl_80650730, 60);
    REGISTER_CONSTANT(lbl_80650738, 76);
    REGISTER_CONSTANT(lbl_80650740, 92);
    REGISTER_CONSTANT(lbl_80650748, 108);
    REGISTER_CONSTANT(lbl_80650750, 124);
    REGISTER_CONSTANT(lbl_80650758, 140);
    REGISTER_CONSTANT(lbl_80650760, 156);
    REGISTER_CONSTANT(lbl_80650768, 172);
    REGISTER_CONSTANT(lbl_80650770, 188);
    REGISTER_CONSTANT(lbl_80650778, 204);
    REGISTER_CONSTANT(lbl_80650780, 220);
    REGISTER_CONSTANT(lbl_80650788, 236);
    REGISTER_CONSTANT(lbl_80650790, 256);
    REGISTER_CONSTANT(lbl_80650798, 276);
    REGISTER_CONSTANT(lbl_806507A0, 296);
    REGISTER_CONSTANT(lbl_806507A8, 312);
    REGISTER_CONSTANT(lbl_806507B0, 328);
    REGISTER_CONSTANT(lbl_806507B8, 348);
    REGISTER_CONSTANT(lbl_806507C0, 364);
    REGISTER_CONSTANT(lbl_806507C8, 380);
    REGISTER_CONSTANT(lbl_806507D0, 400);
    REGISTER_CONSTANT(lbl_806507D8, 416);
    REGISTER_CONSTANT(lbl_806507E0, 432);
    REGISTER_CONSTANT(lbl_806507E8, 448);
    REGISTER_CONSTANT(lbl_806507F0, 464);
    REGISTER_CONSTANT(lbl_806507F8, 492);
    REGISTER_CONSTANT(lbl_80650800, 520);
    REGISTER_CONSTANT(lbl_80650808, 548);
    REGISTER_CONSTANT(lbl_80650810, 568);
    REGISTER_CONSTANT(lbl_80650818, 592);
    REGISTER_CONSTANT(lbl_80650710, 612);
    REGISTER_CONSTANT(lbl_80650718, 636);
    REGISTER_CONSTANT(lbl_80650720, 660);
    REGISTER_CONSTANT(lbl_80650730, 688);
    REGISTER_CONSTANT(lbl_80650750, 712);
    REGISTER_CONSTANT(lbl_80650790, 740);
    REGISTER_CONSTANT(lbl_80650820, 768);
    REGISTER_CONSTANT(lbl_80650828, 800);
    REGISTER_CONSTANT(lbl_80650830, 832);
    REGISTER_CONSTANT(lbl_80650738, 860);
    REGISTER_CONSTANT(lbl_80650798, 892);
    REGISTER_CONSTANT(lbl_80650788, 932);
    REGISTER_CONSTANT(lbl_80650760, 956);
    REGISTER_CONSTANT(lbl_80650758, 980);
    REGISTER_CONSTANT(lbl_80650750, 1004);
    REGISTER_CONSTANT(lbl_80650748, 1028);
    REGISTER_CONSTANT(lbl_80650740, 1056);
    REGISTER_CONSTANT(lbl_80650738, 1080);
    REGISTER_CONSTANT(lbl_80650738, 1104);
    REGISTER_CONSTANT(lbl_80650730, 1144);
    REGISTER_CONSTANT(lbl_80650720, 1176);
    REGISTER_CONSTANT(lbl_80650718, 1200);
    REGISTER_CONSTANT(lbl_80650718, 1224);
    REGISTER_CONSTANT(lbl_80650838, 1252);
    REGISTER_CONSTANT(lbl_80650840, 1268);
    REGISTER_CONSTANT(lbl_80650848, 1284);
    REGISTER_CONSTANT(lbl_80650710, 1300);
    REGISTER_CONSTANT(lbl_80650718, 1320);
    REGISTER_CONSTANT(lbl_80650720, 1340);
    REGISTER_CONSTANT(lbl_80650728, 1372);
    REGISTER_CONSTANT(lbl_80650730, 1400);
    REGISTER_CONSTANT(lbl_80650738, 1432);
    REGISTER_CONSTANT(lbl_80650740, 1456);
    REGISTER_CONSTANT(lbl_80650760, 1488);
    REGISTER_CONSTANT(lbl_80650710, 1512);
    REGISTER_CONSTANT(lbl_80650718, 1524);
    REGISTER_CONSTANT(lbl_80650720, 1536);
    REGISTER_CONSTANT(lbl_80650728, 1552);
    REGISTER_CONSTANT(lbl_80650730, 1568);
    REGISTER_CONSTANT(lbl_80650738, 1584);
    REGISTER_CONSTANT(lbl_80650740, 1600);
    REGISTER_CONSTANT(lbl_80650748, 1620);
    REGISTER_CONSTANT(lbl_80650750, 1640);
    REGISTER_CONSTANT(lbl_80650758, 1652);
    REGISTER_CONSTANT(lbl_80650760, 1664);
    REGISTER_CONSTANT(lbl_80650768, 1676);
    REGISTER_CONSTANT(lbl_80650770, 1688);
    REGISTER_CONSTANT(lbl_80650778, 1700);
    REGISTER_CONSTANT(lbl_80650780, 1712);
    REGISTER_CONSTANT(lbl_80650788, 1724);
    REGISTER_CONSTANT(lbl_80650790, 1736);
    REGISTER_CONSTANT(lbl_80650798, 1748);
    REGISTER_CONSTANT(lbl_80650778, 1760);
    REGISTER_CONSTANT(lbl_80650780, 1780);
    REGISTER_CONSTANT(lbl_80650788, 1800);
    REGISTER_CONSTANT(lbl_80650790, 1824);
    REGISTER_CONSTANT(lbl_80650850, 1848);
    REGISTER_CONSTANT(lbl_80650858, 1864);
    REGISTER_CONSTANT(lbl_80650858, 1880);
}
