class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans(obstacles.size(),1),list;
        for(int i=0;i<obstacles.size();i++){
            int it = upper_bound(list.begin(),list.end(),obstacles[i]) - list.begin();
            if(it == list.size()) list.push_back(obstacles[i]);
            else  list[it] = obstacles[i];
            ans[i] = it+1;
        }
        return ans; 
    }
};