class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // checking if this number has appeared already
        /*
        for(int i=0; i<nums.size(); i++){
            int index = abs(nums[i]);
            if(nums[index] < 0)
                return index;
            nums[index] = -1 * nums[index];
        }
        return -1;
        */

        // Floyd's Algo
        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];          
            fast = nums[nums[fast]];    
        } while (slow != fast);

        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};