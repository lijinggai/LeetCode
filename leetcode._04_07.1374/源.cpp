char* generateTheString(int n)
{
    if (n == 0)
    {
        return NULL;
    }
    char* arr = (char*)malloc(sizeof(char) * (n + 1));
    memset(arr, 'a', sizeof(char) * n);
    arr[n] = '\0';
    if (n % 2 == 0)
    {
        arr[0] = 'b';
        return arr;
    }
    return arr;
    free(arr);
}