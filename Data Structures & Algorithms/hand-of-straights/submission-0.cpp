class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize !=0) return false;
        map<int,int>mp;
        for(int h : hand){
            mp[h]++;
        }

        for(auto it=mp.begin(); it!=mp.end(); it++){
            int start = it->first;
            int freq = it->second;
            if(freq==0) continue;
            for(int x = start; x<start+groupSize; x++){
                auto jt = mp.find(x);
                if(jt==mp.end() || jt->second<freq) return false;
                jt->second -= freq;
            }
        }
        return true;
    }
};
