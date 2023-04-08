int xorOperation(int n, int start)
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            tmp = start + 2 * i;
        }
        else
        {
            tmp ^= start + 2 * i;
        }
    }
    return tmp;

}