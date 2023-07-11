#include <iostream>
using namespace std;

int IsPalindrome(string& s)
{
    int left = 0, right = s.size() - 1;
    while (left < right)
    {
        if (s[left] == s[right])
        {
            left++;
            right--;
        }
        else {
            if (s[left + 1] == s[right])
            {
                return left;
            }
            else {
                return right;
            }
        }
    }
    return -1;
}
int main() {
    int num;
    cin >> num;
    string s;
    while (num--)
    {
        cin >> s;
        cout << IsPalindrome(s) << endl;
        s.clear();
    }
}