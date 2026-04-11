class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int current = 0;
        int right = 0;

        while(right < nums.size()){
            current += nums[right];
            sum = max(sum, current);
            if(current < 0)
                current = 0;
            right++;
        }

        return sum;
    }
};
