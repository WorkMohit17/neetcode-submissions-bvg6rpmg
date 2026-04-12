class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        sort(s1.begin(), s1.end());
        int size = s1.size();

        for(int j=0; j<=s2.size() - size; j++){
            string check = s2.substr(j, size);
            sort(check.begin(), check.end());
            int i = 0;
            while(i < size){
                if(s1[i] != check[i])
                    break;
                i++;
            }
            if(i == size)
                return true;
        }

        return false;
    }
};