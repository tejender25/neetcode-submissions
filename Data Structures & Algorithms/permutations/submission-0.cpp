class Solution {
    vector<vector<int>>ans;
public:
    void solve(vector<int>& nums,vector<int>& curr, vector<bool>& used){
        if(nums.size()==curr.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            curr.push_back(nums[i]);
            used[i]=true;
            solve(nums,curr,used);
            curr.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        vector<bool>used(nums.size(),false);
        solve(nums,curr,used);
        return ans;
    }
};
