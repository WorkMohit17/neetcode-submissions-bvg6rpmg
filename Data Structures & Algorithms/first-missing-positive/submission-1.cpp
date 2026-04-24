class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        int n = nums.size();

        while (i < n) {
            if (nums[i] > 0 && nums[i] <= n) {
                int ci = nums[i] - 1;

                if (nums[i] != nums[ci]) {
                    swap(nums[i], nums[ci]);
                    continue;
                }
            }
            i++;
        }

        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};