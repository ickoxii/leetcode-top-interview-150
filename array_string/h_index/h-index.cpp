/* Given an array of integers 'citations' where
 * 'citations[i]' is the number of citations
 * a researcher received for their ith paper,
 * return the researchers h-index.
 *
 * According to the definition of h-index on 
 * Wikipedia: The h-index is defined as the maximum
 * value of h such that the given researcher
 * has published at least h papers that have each
 * been cited at least h times. */

// elegant chatgpt solution
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend()); // Sort the citations in descending order

        int h = 0;
        while (h < citations.size() && citations[h] > h) {
            h++;
        }

        return h;
    }
};

/* my soln, does not work
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int curr_h = citations[0], max_h = 0;

        for (int i = 0; i < citations.size(); ++i) {
            int num_papers = 0; // keeps track of number of papers greater than h
            curr_h = citations[i];

            for (int j = 0; j < citations.size(); ++j) {
                if (citations[j] >= curr_h) {
                    num_papers++;
                }
            }
            
            if (num_papers >= curr_h) {
                max_h = max(max_h, curr_h);
            }
        }

        return max_h;
    }
};*/
