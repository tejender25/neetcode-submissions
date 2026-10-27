class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int cmpt = target-nums[i];
            if(mp.find(cmpt) != mp.end()){
                return {mp[cmpt],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
