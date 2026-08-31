int fn_801ABCA8(int value, int distance, int near_distance, int far_distance,
                int near_percent, int far_percent)
{
    int result;

    if (distance < 0)
        distance = -distance;

    if (distance < near_distance) {
        result = value * (near_percent +
            (100 - near_percent) * (near_distance - distance) / near_distance) / 100;
    } else if (distance < far_distance) {
        result = value * (near_percent * (far_distance - distance) /
            (far_distance - near_distance)) / 100;
    } else {
        result = far_percent;
    }

    return result > far_percent ? result : far_percent;
}
