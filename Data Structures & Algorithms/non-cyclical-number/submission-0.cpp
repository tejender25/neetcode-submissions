class Solution {
public:
    int getSumSq(int x){
        int sum=0;
        while(x>0){
            int digit = x%10;
            sum+= digit * digit;
            x/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int>seen;
        while(n!=1){
            if(seen.count(n)) return false;
            seen.insert(n);
            n=getSumSq(n);
        }
        return true;
    }
};
