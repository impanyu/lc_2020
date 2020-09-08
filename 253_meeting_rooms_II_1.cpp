//boundary count
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> count; //time -> incidents count(start +1, end -1)
        for(vector<int> interval : intervals){
            count[interval[0]]++;
            count[interval[1]]--;
        }
        int ans = 0;
        int rooms = 0;
        for(auto p : count){
            rooms += p.second;
            ans = max(ans, rooms);
        }
        return ans;
    }
};
