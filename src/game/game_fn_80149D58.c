/* NonMatching: honest scalar reconstruction of the Gekko quantized paired-single
 * store. Canonical C emits scalar conversion rather than retail's psq_st. */
void fn_80149D58(float* input, short* output)
{
    *output = (short)*input;
}
