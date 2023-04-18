int numSpecial(int** mat, int matSize, int* matColSize)
{
    int m = matSize, n = matColSize[0];
    int* rowMat = (int*)malloc(sizeof(int) * m);//行数组
    int* colMat = (int*)malloc(sizeof(int) * n);//列数组
    memset(rowMat, 0, sizeof(int) * m);//初始
    memset(colMat, 0, sizeof(int) * n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rowMat[i] += mat[i][j];//一列的和
            colMat[j] += mat[i][j];//一行的和
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1 && rowMat[i] == 1 && colMat[j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}