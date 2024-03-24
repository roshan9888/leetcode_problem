class Solution {
public:
    vector<int>hours={1,2,4,8};
    vector<int>minutes={1,2,4,8,16,32};
    void solve(vector<string>&ans,pair<int,int>time,int turnedOn,int start_point){
        if(turnedOn==0){
            ans.push_back(to_string(time.first) + (time.second < 10 ? ":0" : ":") + to_string(time.second));
            return;
        }

        for(int i=start_point;i<hours.size()+minutes.size();i++){
            if(i<hours.size()){
                time.first+=hours[i];
                if(time.first<12) solve(ans,time,turnedOn-1,i+1);
                time.first-=hours[i];
            }
            else{
                time.second+=minutes[i-hours.size()];
                if(time.second<60) solve(ans,time,turnedOn-1,i+1);
                time.second-=minutes[i-hours.size()];
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        solve(ans,make_pair(0,0),turnedOn,0);
        return ans;
    }
};