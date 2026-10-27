class Solution {
public:
    bool isPalindrome(string s) {

        string ss;
        for(char c:s){
            if(isalnum(c)) ss.push_back(tolower(c));
        }

        int n = ss.size();

        int i=0,j=n-1;
        while(i<=j){
            if(ss[i]==ss[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
};
