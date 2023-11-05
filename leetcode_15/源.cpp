class Solution {
    void DFS(vector<vector<int>>& res, set<vector<int>>& memo, vector<int>& v, vector<int>& nums, int curTotal, int cur, int index)
    {
        if (cur == 3)
        {
            if (curTotal == 0)
            {
                if (memo.find(v) == memo.end())
                {
                    res.push_back(v);
                    memo.insert(v);
                }
            }
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            DFS(res, memo, v, nums, curTotal + nums[i], cur + 1, i + 1);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> v;

        //set<vector<int>> memo;
        for (int l = 0; l < nums.size() - 2; l++)
        {
            if (l != 0 && nums[l] == nums[l - 1])
                continue;
            int k = l + 1, r = nums.size() - 1;
            while (k < r)
            {
                int sum = nums[l] + nums[k] + nums[r];
                //cout<<sum<<" ";
                if (sum == 0)
                {
                    vector<int> v{ nums[l], nums[k], nums[r] };
                    ans.push_back(v);
                    while (k < r && nums[k] == nums[++k]);
                    while (k < r && nums[r] == nums[--r]);
                }
                else if (sum < 0) {
                    while (k < r && nums[k] == nums[++k]);
                }
                else {
                    while (k < r && nums[r] == nums[--r]);
                }
            }
            //cout<<endl;
        }
        return ans;
    }
};