 /**
  * There are a total of 'numCourses' courses you have to take, labeled from 0 to
  * numCourses - 1. You are given an array prerequisites where 
  * prerequisites[i] = [a_i, b_i] 
  * indicates that you must take course b_i first if you want to take course a_i.
  *
  * For example, the pair [0, 1], indicates that to take course 0 you must have
  * to first take course 1.
  *
  * Return true if you can finish all courses, Otherwise, return false. */

/**
 * Hints:
 * 1. This problem is equivalent to finding if a cycle exists in a 
 * directed graph. If a cycle exists, no topological ordering exists
 * and therefore it will be impossible to take all courses.
 *
 * 2. Topological Sort via DFS - a great tutorial explaining the
 * basic concepts of topological sort.
 *
 * 3. Topological sort could also be done via BFS. */

class Solution {
public:
    /* can Finish
     *
     * This function checks if all courses are able to be complete by
     * implementing an algorithm to find a cycle in a directed graph.
     * If a cycle exists, then the courses cannot be completed.
     * To do this, we keep a set of all nodes that have been visited.
     * If we encounter a node we have already visited, then the graph
     * contains a cycle and the classes, therefore, cannot be completed.
     *
     * parameters:
     * numCourses - number of courses in the graph
     * prerequisites - vector of pairs according to the problem
     *                 description above
     *
     * return:
     * true - no cycle, courses can be completed
     * false - has cycle, courses cannot be completed */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // build graph
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> visit(numCourses);

        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) {
                return false;
            }
        }

        return true;
    }

private:
    bool canFinishDFS(vector<vector<int>>& graph, vector<int>& visit, int i) {
        if (visit[i] == -1) return false; // being visited in same path
        if (visit[i] == 1) return true; // already visited and validated
        
        visit[i] = -1; // mark being visited for this path
        for (int j : graph[i]) {
            if (!canFinishDFS(graph, visit, j)) return false;
        }

        visit[i] = 1; // mark it as visited and validated
        
        return true;
    }
};
