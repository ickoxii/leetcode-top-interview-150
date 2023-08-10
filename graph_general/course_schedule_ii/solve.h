 /**
  * There are a total of numCourses course you have to take, labeled
  * from 0 to numCourses-1. You are given an array prerequisites
  * where prerequisites[i] = [a_i, b_i] indicates that you must take
  * course b_i first if you want to take course a_i.
  *
  * For example, the pair [0, 1], indicates that to take course 0
  * you have to first take course 1.
  *
  * Return the ordering of courses you should take to finish all courses.
  * If there are many valid answers, return any of them. If it is
  * impossible to finish all courses, return an empty array. */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create an adjacency list representation of the graph
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        
        vector<int> result;
        vector<int> visited(numCourses, 0); // 0 = white, 1 = gray, 2 = black
        
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && !dfs(i, graph, visited, result)) {
                return {};
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool dfs(int curr, vector<vector<int>>& graph, vector<int>& visited, vector<int>& result) {
        if (visited[curr] == 1) return false; // cycle detected
        if (visited[curr] == 2) return true; // already visited
        
        visited[curr] = 1; // mark as currently visiting
        
        for (int next : graph[curr]) {
            if (!dfs(next, graph, visited, result)) return false;
        }
        
        visited[curr] = 2; // mark as visited
        result.push_back(curr);
        return true;
    }
};

