class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int result = 0, totalExpreience = initialExperience;
        for (int e : experience)
        {
            if (totalExpreience <= e)
            {
                result += e - totalExpreience + 1;
                totalExpreience += e - totalExpreience + 1;
            }
            totalExpreience += e;
        }
        int tmp = 0;
        for (int e : energy)
        {
            tmp += e;
        }
        if (tmp >= initialEnergy)
        {
            result += tmp - initialEnergy + 1;
        }
        return result;
    }
};