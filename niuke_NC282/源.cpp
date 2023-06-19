class Solution {
public:
	void replaceSpace(char* str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (str[i] == ' ')
				count++;
		}
		int back = length + 2 * count;
		while (back >= 0)
		{
			if (str[length] == ' ')
			{
				str[back--] = '0';
				str[back--] = '2';
				str[back--] = '%';
				length--;
			}
			else
			{
				str[back--] = str[length--];
			}
		}
	}
};
