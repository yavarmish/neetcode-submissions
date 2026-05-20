class Solution {
public:
    /*
        Topological Sort(Kahn's Algo)(detects cycle)
        Time O(V + E) Space O(V + E)
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> courseIndegrees(numCourses, 0);
        vector<vector<int>> adjCourses(numCourses);
        for(vector<int> &pre : prerequisites)  {
            ++courseIndegrees[pre[0]];
            adjCourses[pre[1]].push_back(pre[0]);
        }
        queue<int> entryCoursesQueue;
        for(int  i = 0; i < numCourses; ++i) if(courseIndegrees[i] == 0) entryCoursesQueue.push(i);
        int completedCourses = 0;
        while(entryCoursesQueue.size()) {
            int curCourse = entryCoursesQueue.front();
            entryCoursesQueue.pop();
            ++completedCourses;
            for(int &nbr : adjCourses[curCourse]) {
                --courseIndegrees[nbr];
                if(courseIndegrees[nbr] == 0) entryCoursesQueue.push(nbr);
            }
        }
        return completedCourses == numCourses;
    }
    // Add DFS based cycle detection
};
