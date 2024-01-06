 /**
  * A gene string can be represented by an 8-character long string, with choices
  * from 'A', 'C', 'G', and 'T'.
  *
  * Suppose we need to investigate a mutation from a gene string startGene to a 
  * gene string endGene where one mutation is defined as one single character 
  * changed in the gene string.
  *     EX: "AACCGGTT" --> "AACCGGTA" is one mutation
  *
  * There is also a gene bank bank that records all the valid gene mutations.
  * A gene must be in the bank to make it a valid gene string.
  *
  * Given the two gene strings startGene and endGene and the gene bank bank, 
  * return the minimum number of mutations needed to mutate from startGene to
  * endGene. If there is no such a mutation, return -1.
  *
  * Note that the starting point is assumed to be valid, so it might not be 
  * included in the bank
  *
  * EX 1:
  * Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
  * Output: 1
  *
  * EX 2:
  * Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA",
  * "AACCGCTA", "AAACGGTA"]
  * Output: 2
  */
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

 /**
  * I need a way to store each consecutive mutation.
  * I need a way to store at which point in the iteration I am at
  */

class Solution {
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            const int NUM_VALID = 4;
            const char validChar[NUM_VALID] = { 'A', 'C', 'G', 'T' };
            vector<int> distances(bank.size());
            unordered_map<string, string> path;
            unordered_set<string> seen;
            bool found = false;

            queue<string> frontier;
            frontier.push(startGene);
            seen.insert(startGene);
            path[startGene] = startGene;

            // bfs loop?
            while(frontier.size() > 0 && !found) {
                string curr = frontier.front();
                for(int i = 0; i < curr.size(); ++i) {
                    // change every letter
                    for(const char &c : validChar) {
                        string neighbor = curr;
                        neighbor[i] = c;
                        if(neighbor != curr && neighbor != startGene && isValidMutation(neighbor, bank) && seen.count(neighbor) == 0) {
                            frontier.push(neighbor);
                            seen.insert(neighbor);
                            path[neighbor] = curr;
                            if (neighbor == endGene)
                                found = true;
                        }
                    }
                }
            }

            if(!found) return -1;

            int dist = 0;
            string curr = endGene;
            string next = path[endGene];
            while(curr != startGene) {
                dist++;
                curr = next;
                next = path[next];
            }

            return dist;
        }

        bool isValidMutation(string mutation, vector<string>& bank) {
            for(const string &valid : bank)
                if(mutation == valid) return true;
            return false;
        }
};

int main(int argc, char *argv[]) {
    int numCases = (argc > 1) ? argv[1] : 0;

    for(int i = 0; i < numCases; ++i) {
        

    return 0;
}
