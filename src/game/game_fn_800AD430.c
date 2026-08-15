extern char lbl_802458D8[];
extern char lbl_802458E4[];
extern int fn_8015D9C8(char*, int);

int fn_800AD430(void)
{
    int result = fn_8015D9C8(lbl_802458D8, 0xDBCAA0);
    fn_8015D9C8(lbl_802458E4, result + 0xDBCAA0);
    return result;
}
