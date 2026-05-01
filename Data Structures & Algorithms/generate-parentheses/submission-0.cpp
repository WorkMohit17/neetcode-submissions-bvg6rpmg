class Solution {
public:
    void solve(int n, int open, int close, string pattern, vector<string>& ans){
        if(open == n && close == n){
            ans.push_back(pattern);
            return;
        }

        if(open < n){
            pattern.push_back('(');
            solve(n, open+1, close, pattern, ans);
            pattern.pop_back();
        }

        if(close < open){
            pattern.push_back(')');
            solve(n, open, close+1, pattern, ans);
            pattern.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string pattern = "";
        vector<string> ans;
        solve(n, open, close, pattern, ans);
        return ans;
    }
};