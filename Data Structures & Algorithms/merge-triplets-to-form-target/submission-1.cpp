class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // Ignore triplets that exceed the target, then check if the remaining triplets can provide all three target values
        bool a=0,b=0,c=0;
        for(auto& t: triplets){
            if(t[0]>target[0] || t[1]>target[1] || t[2]>target[2]) continue;
            if(t[0]==target[0]) a=1;
            if(t[1]==target[1]) b=1;
            if(t[2]==target[2]) c=1;

        }
        return a&&b&&c;
    }
};
