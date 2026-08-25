float fn_80179F20(float value)
{
    if (value > 6.2831855f) {
        return value - 6.2831855f;
    }
    if (value < 0.0f) {
        value += 6.2831855f;
    }
    return value;
}
