class Solution {

public:

    string getPermutation(int n, int k) {

        //1-n������

        vector<int> vc;

        for (int i = 1; i <= n; i++) {

            vc.push_back(i);

        }

        string s;

        //�׳�����

        vector<int> factorial(n);

        factorial[0] = 1;

        for (int i = 1; i < n; ++i) {

            factorial[i] = factorial[i - 1] * i;

        }

        //���n=3��1��2��1��ͷ��3��4��2��ͷ�����Լ�1

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