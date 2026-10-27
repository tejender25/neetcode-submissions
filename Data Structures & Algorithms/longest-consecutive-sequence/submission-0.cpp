class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        unordered_map<int,bool> present, visited;
        for(auto a : nums){
            present[a]=1;
        }

        for(auto a : nums){
            if(!visited[a] && !present[a-1]){
                int curr=0;
                int start=a;
                while(present[start]){
                    curr++;
                    visited[start]=1;
                    start++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};