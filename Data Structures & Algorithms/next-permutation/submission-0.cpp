class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i>=0 && nums[i] >= nums[i+1])
            i--;
        if(i >= 0){
            int j = nums.size()-1;
            while(nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        int left = i+1, right = nums.size()-1;
        while(left < right){
            swap(nums[left], nums[right]);
            left++; right--;
        }

    }
};
