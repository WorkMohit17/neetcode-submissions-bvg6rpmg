class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int left = 0;          
        int right = 0;         
        int index = 0;         

        while(right < n){
            left = right;

            while(right < n && chars[right] == chars[left]) 
                right++;

            int length = right - left;
            chars[index++] = chars[left];

            if(length > 1){
                string cnt = to_string(length);
                for (char c : cnt) 
                    chars[index++] = c;
            }
        }

        return index;
    }
};