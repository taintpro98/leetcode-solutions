// class Solution {
// public:
    
//     bool isCyclicUtil(int s, vector<bool> &recStack, vector<bool> &visited, unordered_map<int, vector<int>> graph){
//         if(!visited[s]){
//             visited[s] = true;
//             recStack[s] = true;
            
//             for(auto t: graph[s]){
//                 if(!visited[t] && isCyclicUtil(t, recStack, visited, graph)) return true;
//                 else if(recStack[t]) return true;
//             }
//         }
//         recStack[s] = false;
//         return false;
//     }
    
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         unordered_map<int, vector<int>> graph;
//         for (auto p: prerequisites)
//         {
//             graph[p[0]].push_back(p[1]);
//         }
        
//         vector<bool> recStack(numCourses, false);
//         vector<bool> visited(numCourses, false);
        
//         for(int i=0; i<numCourses; i++){
//             if(isCyclicUtil(i, recStack, visited, graph)) return false;
//         }
        
//         return true;
//     }
// };
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {        
                
        unordered_map<int, vector<int>> um;
        vector<int> visited(numCourses, 0);
        
        //Make list of prerequisites of all courses and add to a map
        for (auto p: prerequisites)
        {
            um[p[0]].push_back(p[1]);
        }
        
        //Traverse each course, return true if each prerequisite of the course can be traversed
        for (int i=0; i<numCourses; i++)
        {
            if (!traverse(visited, um, i))
                return false;
        }
        
        return true;
    }
    
    bool traverse (vector<int>& visited, unordered_map<int, vector<int>>& um, int i)
    {
        
        if (visited[i]==10) //Already visiting (a cycle exists)
            return false;
        if (visited[i]==1)
            return true;
        visited[i]=10;      //Mark as visiting
        for (auto c: um[i])
        {
            if (!traverse(visited, um, c))
                return false;
        }
        visited[i] = 1;     //Visited
        return true;
    }
    
};