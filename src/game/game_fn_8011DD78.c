void fn_8011DD78(unsigned short first, unsigned short second, unsigned short third)
{
    volatile unsigned short* fifo = (volatile unsigned short*)0xCC008000;

    *fifo = first;
    *fifo = second;
    *fifo = third;
}
