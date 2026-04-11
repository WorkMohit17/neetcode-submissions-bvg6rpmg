class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int sum = 0;
        int left = 0, right = k;

        for(int i=0; i<k; i++)
            sum += arr[i];

        if((sum / k) >= threshold)
            count++;

        while(right < arr.size()){
            sum -= arr[left++];
            sum += arr[right++];
            if((sum / k) >= threshold)
                count++;
        }

        return count;

    }
};