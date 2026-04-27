class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefix = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            int num = nums[i];
            prefix += num;

            int needed = prefix - k;
            if(freq.count(needed))
                count += freq[needed];
            
            freq[prefix]++;
        }

        return count;
    }
};