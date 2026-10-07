typedef unsigned char u8;
typedef signed char s8;
typedef short s16;
typedef unsigned int u32;
typedef struct Color { u8 r, g, b, a; } Color;

typedef struct Spark {
    s16 x;
    s16 y;
    s8 dx;
    s8 dy;
    u8 life;
    u8 done;
} Spark;

typedef struct SparkBurst {
    Spark sparks[32];
} SparkBurst;

extern int fn_800FBFB0(void);
extern void fn_801A8D38(int);
extern void fn_801ED3F4(int);
extern void fn_80225F4C(int, void*, int);
extern void fn_801A85D4(Color, int, int, u32);
extern void fn_801A8F08(s16, s16, s16, s16, int, int, int);

extern SparkBurst lbl_80331A3C[7];
extern int lbl_8064CD7C;
extern u8 lbl_802515D0[];
extern Color lbl_8064C2A8;

void fn_80117AE0(s16 x, s16 y, int slot, int mode) {
    Spark* spark;
    int i;
    int j;
    int idx = slot - 1;

    if (slot != 0) {
        if (mode != 1) {
            for (i = 0; i < 32; i++) {
                lbl_80331A3C[idx].sparks[i].x = x;
                lbl_80331A3C[idx].sparks[i].y = y;
                lbl_80331A3C[idx].sparks[i].dx = fn_800FBFB0() % 30 - 15;
                lbl_80331A3C[idx].sparks[i].dy = fn_800FBFB0() % 15 - 15;
                lbl_80331A3C[idx].sparks[i].life = fn_800FBFB0() % 100 + 155;
            }
            lbl_80331A3C[idx].sparks[0].done = 0;
        } else {
            for (i = 0; i < 32; i++) {
                lbl_80331A3C[idx].sparks[i].x = x;
                lbl_80331A3C[idx].sparks[i].y = y;
                lbl_80331A3C[idx].sparks[i].dx = fn_800FBFB0() % 40 - 20;
                lbl_80331A3C[idx].sparks[i].dy = fn_800FBFB0() % 30 - 20;
                lbl_80331A3C[idx].sparks[i].life = fn_800FBFB0() % 100 + 50;
            }
            lbl_80331A3C[idx].sparks[0].done = 0;
        }
    } else if (mode == 0) {
        fn_801A8D38(6);
        fn_801ED3F4(lbl_8064CD7C);
        fn_80225F4C(13, lbl_802515D0, 4);
        for (i = 0; i < 7; i++) {
            if (lbl_80331A3C[i].sparks[0].done == 0) {
                lbl_80331A3C[i].sparks[0].done = 1;
                for (j = 0; j < 32; j++) {
                    spark = &lbl_80331A3C[i].sparks[j];
                    if (spark->life >= 10) {
                        Color color = lbl_8064C2A8;
                        int size;
                        color.a = spark->life;
                        size = (spark->dx >> 1) + 4;
                        fn_801A85D4(color, 18, 18, 0x80000000);
                        lbl_80331A3C[i].sparks[0].done = 0;
                        fn_801A8F08(spark->x - size, spark->y - size, size + spark->x, size + spark->y, -1, 0, 5);
                        spark->x += spark->dx >> 1;
                        spark->y += spark->dy >> 1;
                        spark->life -= 10;
                        if (spark->dx > 0) {
                            spark->dx--;
                        } else if (spark->dx < 0) {
                            spark->dx++;
                        }
                        if (spark->dy < 50) {
                            spark->dy++;
                        }
                    }
                }
            }
        }
    } else {
        lbl_80331A3C[0].sparks[0].done = 1;
        lbl_80331A3C[1].sparks[0].done = 1;
        lbl_80331A3C[2].sparks[0].done = 1;
        lbl_80331A3C[3].sparks[0].done = 1;
        lbl_80331A3C[4].sparks[0].done = 1;
        lbl_80331A3C[5].sparks[0].done = 1;
        lbl_80331A3C[6].sparks[0].done = 1;
    }
}
