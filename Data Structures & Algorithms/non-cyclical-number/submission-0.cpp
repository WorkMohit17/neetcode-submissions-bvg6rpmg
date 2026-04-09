class Solution {
public:
    int sumOfDigits(int n){
        int ans = 0;
        while(n > 0){
            int d = n%10;
            ans += d*d;
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = sumOfDigits(slow);
            fast = sumOfDigits(sumOfDigits(fast));
        }while(slow != fast);

        return slow == 1;
    }
};