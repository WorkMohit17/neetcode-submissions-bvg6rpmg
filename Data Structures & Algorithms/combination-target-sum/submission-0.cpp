class Solution {
public:
    void solve(vector<int>& candidates, int index, int target, vector<int>& output, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(output);
            return;
        }
        
        if (index >= candidates.size() || target < 0)
            return;

        output.push_back(candidates[index]);
        solve(candidates, index, target - candidates[index], output, ans);

        output.pop_back();

        solve(candidates, index + 1, target, output, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates, 0, target, output, ans);
        return ans;
    }
};