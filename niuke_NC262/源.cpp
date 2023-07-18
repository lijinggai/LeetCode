class Solution {
public:
    void Reverse(string& str, int left, int right) {
        while (left < right) {
            char tmp = str[left];
            str[left] = str[right];
            str[right] = tmp;
            left++, right--;
        }
    }
    string LeftRotateString(string str, int n) {
        if (str == "")
            return "";
        //ģ���ַ�������
        n = n % str.size();
        if (n != 0) {
            //�ֲ���ת
            Reverse(str, 0, n - 1);
            Reverse(str, n, str.size() - 1);
            //������ת
            Reverse(str, 0, str.size() - 1);
        }
        return str;
    }
};