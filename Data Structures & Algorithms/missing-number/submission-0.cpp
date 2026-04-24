class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i<n){
            int cindex = nums[i];
            if(nums[i] < n && nums[i] != nums[cindex])
                swap(nums[i], nums[cindex]);
            else
                i++;
        }
        for(int j=0; j<n; j++){
            if(nums[j] != j)
                return j;
        }
        return n;
    }
};