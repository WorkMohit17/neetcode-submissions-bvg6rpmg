class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        /*
            ye aise hoga ki pehle apn niklte hai prefix sum
            eg:         1   2   3       ---> example testcase
            prefix :    1   3   6
            neeeded:    -2  0   3       ----> needed = prefix - k

            abb apn check krte hai agr freq(needed) hai to count += freq(needed) krdo
            kyu kra?
            ---> humko pata hai ki agar kisi previous index tak ka prefix sum = needed 
                    aur current prefix sum = prefixSum hai
                    to in dono ka difference:
                        prefixsum - needed = k  hoga

            ---> us prev index k next se lekr current index tak ka subarray ka sum = k hoga
            ---> freq(needed) btata hai ki aise kitne prefix already mil chuke hai
                    issliye jitne baar needed mila, utni valid subarray mil jayegi
        */

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