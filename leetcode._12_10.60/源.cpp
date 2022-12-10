class Solution {

public:

    string getPermutation(int n, int k) {

        //1-n的数组

        vector<int> vc;

        for (int i = 1; i <= n; i++) {

            vc.push_back(i);

        }

        string s;

        //阶乘数组

        vector<int> factorial(n);

        factorial[0] = 1;

        for (int i = 1; i < n; ++i) {

            factorial[i] = factorial[i - 1] * i;

        }

        //如果n=3；1和2是1开头、3和4是2开头，所以减1

        k--;

        for (int i = 1; i <= n; i++)

        {

            int tmp = k / factorial[n - i] + 1;

            k = k % factorial[n - i];



            for (int j = 0; j < vc.size(); j++)

            {

                if (vc[j] != 0)

                {

                    if (tmp == 1)

                    {

                        s.push_back(vc[j] + '0');

                        vc[j] = 0;

                        break;

                    }

                    else

                        tmp--;

                }

            }

        }

        return s;

    }

};