 /**
  * You are given an array of variable pairs equations 
  * and an array of real numbers values, where
  * equations[i] = [A_i, B_i] and values[i] represent
  * the equation A_i / B_i = values[i]. Each A_i or B_i
  * is a string that represents a single variable.
  *
  * You are also given some queries, where
  * queries[j] = [C_j, D_j] represents the j_th query
  * where you must find the answer for C_j / D_j = ?.
  *
  * Return the answers to all queries. If a single
  * answer cannot be dtermined, return -1.0.
  *
  * Note: the input is always valid. there is no division
  * by zero and there is no contradiction
  *
  * Note: variables that do not occur in the list of
  * equations are undefined, so the answer cannot be
  * determined for them. */

/*
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
    }
}; */

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <string>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        // Step 1: Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            double quotient = values[i];
            graph[numerator].push_back({denominator, quotient});
            graph[denominator].push_back({numerator, 1.0 / quotient});
        }
        // Step 2: Process each query
        vector<double> results;
        for (const auto& query : queries) {
            string start = query[0];
            string end = query[1];
            if (!graph.count(start) || !graph.count(end)) {
                // The variable does not exist.
                results.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(DFS(graph, start, end, visited));
            }
        }
        return results;
    }
private:
    double DFS(unordered_map<string, vector<pair<string, double>>>& graph, string start, string end, unordered_set<string>& visited) {
        // The end variable is reached
        if (start == end) return 1.0;
        visited.insert(start);
        for (const auto& neighbor : graph[start]) {
            if (visited.count(neighbor.first) == 0) {
                double product = DFS(graph, neighbor.first, end, visited);
                // If the end variable is reached
                if (product > 0) return product * neighbor.second;
            }
        }
        // If there is no path to the end
        return -1.0;
    }
};
