typedef signed short s16;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

int fn_8017DD28(Vec3s* current, Vec3s* target, Vec3s* delta)
{
    int x_done = 0;
    int y_done = 0;
    int z_done = 0;

    delta->x = target->x - current->x;
    delta->y = target->y - current->y;
    delta->z = target->z - current->z;

    if (delta->x < 0) {
        if (delta->x < -1000) {
            delta->x = -50;
        } else if (delta->x < -500) {
            delta->x = -40;
        } else if (delta->x < -300) {
            delta->x = -20;
        } else if (delta->x < -200) {
            delta->x = -10;
        } else if (delta->x < -100) {
            delta->x = -8;
        } else if (delta->x < -50) {
            delta->x = -4;
        } else if (delta->x < -30) {
            delta->x = -2;
        } else {
            x_done = 1;
        }
    } else if (delta->x > 0) {
        if (delta->x > 1000) {
            delta->x = 50;
        } else if (delta->x > 500) {
            delta->x = 40;
        } else if (delta->x > 300) {
            delta->x = 20;
        } else if (delta->x > 200) {
            delta->x = 10;
        } else if (delta->x > 100) {
            delta->x = 8;
        } else if (delta->x > 50) {
            delta->x = 4;
        } else if (delta->x > 30) {
            delta->x = 2;
        } else {
            x_done = 1;
        }
    } else {
        x_done = 1;
    }

    if (delta->y < 0) {
        if (delta->y < -1000) {
            delta->y = -50;
        } else if (delta->y < -500) {
            delta->y = -40;
        } else if (delta->y < -300) {
            delta->y = -20;
        } else if (delta->y < -200) {
            delta->y = -10;
        } else if (delta->y < -100) {
            delta->y = -8;
        } else if (delta->y < -50) {
            delta->y = -4;
        } else if (delta->y < -30) {
            delta->y = -2;
        } else {
            y_done = 1;
        }
    } else if (delta->y > 0) {
        if (delta->y > 1000) {
            delta->y = 50;
        } else if (delta->y > 500) {
            delta->y = 40;
        } else if (delta->y > 300) {
            delta->y = 20;
        } else if (delta->y > 200) {
            delta->y = 10;
        } else if (delta->y > 100) {
            delta->y = 8;
        } else if (delta->y > 50) {
            delta->y = 4;
        } else if (delta->y > 30) {
            delta->y = 2;
        } else {
            y_done = 1;
        }
    } else {
        y_done = 1;
    }

    if (delta->z < 0) {
        if (delta->z < -1000) {
            delta->z = -40;
        } else if (delta->z < -500) {
            delta->z = -25;
        } else if (delta->z < -300) {
            delta->z = -15;
        } else if (delta->z < -200) {
            delta->z = -12;
        } else if (delta->z < -150) {
            delta->z = -10;
        } else if (delta->z < -60) {
            delta->z = -15;
        } else if (delta->z < -20) {
            delta->z = -20;
        } else {
            z_done = 1;
        }
    } else if (delta->z > 0) {
        if (delta->z > 1000) {
            delta->z = 40;
        } else if (delta->z > 500) {
            delta->z = 25;
        } else if (delta->z > 300) {
            delta->z = 15;
        } else if (delta->z > 200) {
            delta->z = 12;
        } else if (delta->z > 150) {
            delta->z = 10;
        } else if (delta->z > 60) {
            delta->z = 15;
        } else if (delta->z > 20) {
            delta->z = 20;
        } else {
            z_done = 1;
        }
    } else {
        z_done = 1;
    }

    current->x += delta->x;
    current->y += delta->y;
    current->z += delta->z;

    return x_done && y_done && z_done;
}
