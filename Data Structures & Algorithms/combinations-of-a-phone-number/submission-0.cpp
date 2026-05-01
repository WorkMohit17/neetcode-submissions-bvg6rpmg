class Solution {
public:
    void solve(string& digits, int index, vector<string>& map, string output, vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(output);
            return ;
        }

        string pattern = map[digits[index] - '0'];
        for(int i=0; i<pattern.size(); i++){
            char c = pattern[i];
            output.push_back(c);
            solve(digits, index+1, map, output, ans);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) 
            return {};
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", 
                                "pqrs", "tuv", "wxyz"};
        string output = "";
        vector<string> ans;
        solve(digits, 0, map, output, ans);
        return ans;
    }
};