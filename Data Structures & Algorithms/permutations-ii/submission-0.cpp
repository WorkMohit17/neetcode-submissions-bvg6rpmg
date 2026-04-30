class Solution {
private:
    void solve(vector<int>& nums, int index, vector<vector<int>>& ans) {
        if (index >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for (int j = index; j < nums.size(); j++) {
            if (seen.find(nums[j]) != seen.end()) 
                continue;
            
            seen.insert(nums[j]);
            swap(nums[j], nums[index]);
            solve(nums, index + 1, ans);
            swap(nums[j], nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(nums, 0, ans);
        return ans;
    }
};