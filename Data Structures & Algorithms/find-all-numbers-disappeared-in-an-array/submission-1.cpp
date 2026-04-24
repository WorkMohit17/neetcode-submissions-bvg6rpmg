class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while(i < n){
            int ci = nums[i] - 1;

            if(nums[i] != nums[ci])
                swap(nums[i], nums[ci]);
            else
                i++;
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1)
                ans.push_back(i + 1);
        }

        return ans;
    }
};