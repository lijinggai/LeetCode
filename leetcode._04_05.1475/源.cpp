/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* finalPrices(int* prices, int pricesSize, int* returnSize)
{
    int i = 0;
    while (i < pricesSize)
    {
        int tmp = prices[i];
        int j = i + 1;
        while (j < pricesSize)
        {
            if (tmp < prices[j])
            {
                j++;
            }
            else
            {
                prices[i] = prices[i] - prices[j];
                break;
            }
        }
        i++;
    }
    *returnSize = pricesSize;
    return  prices;
}