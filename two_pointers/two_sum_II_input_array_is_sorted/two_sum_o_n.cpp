class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> answer(2, -1);

        unordered_map<int, int> numMap; // Map to store number-frequency pairs

        for (int i = 0; i < n; ++i) {
            // find the difference between target and the current element
            int complement = target - numbers[i];

            // check to see if the complement exists in the hash map
            if (numMap.find(complement) != numMap.end()) {
                answer[0] = numMap[complement]+1;
                answer[1] = i+1;
                break;
            }

            numMap[numbers[i]] = i;
        }

        return answer;
    }
};

