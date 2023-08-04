/* There are n gas stations along a circular route, where
 * the amount of gas at the ith station is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs
 * cost[i] of gas to travel from the ith station to its next
 * (i + 1)th station. You begin the journey with an empty
 * tank at one of the gas stations.
 *
 * Given two integer arrays gas and cost, return the
 * starting gas station's index if you can travel
 * around the circuit once in the clockwise direction,
 * otherwise return -1. If there exists a solution, it is
 * guaranteed to be unique. */

// chatgpt solution, runs in O(n)
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0;  // Total tank
        int currentTank = 0;  // Current tank
        int start = 0;  // Starting station

        for (int i = 0; i < gas.size(); ++i) {
            totalTank += gas[i] - cost[i];
            currentTank += gas[i] - cost[i];

            // If the current tank is negative, reset the starting station to the next station
            if (currentTank < 0) {
                start = i + 1;
                currentTank = 0;
            }
        }

        // If the total tank is negative, it's not possible to complete the circuit
        if (totalTank < 0) {
            return -1;
        }

        return start;
    }
};


/* my soln, too slow, runs in O(n^2)
 *
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, tank = 0, end = 0;
        bool soln_found = false;
        // start at each index

        for (int i = 0; i < gas.size(); ++i) {
            start = i;
            end = 0;
            tank = 0;

            for (int j = 0; j < gas.size(); ++j) {
                tank += gas[(j+i)%gas.size()];
                if (tank >= cost[(j+i)%gas.size()]) {
                    end = (j+i+1) % gas.size();
                    tank -= cost[(j+i)%gas.size()];
                } else break;
            }

            if (end == start) {
                soln_found = true;
            }
        }

        if (soln_found == false) {
            return -1;
        }

        return start;
    }
};  */
