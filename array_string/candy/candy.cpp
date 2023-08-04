/* There are n children standing in a line. Each child
 * is assigned a rating value given in the integer
 * array ratings.
 *
 * You are giving candies to these children subjected
 * to the following requirements.
 *
 * Each child must have at least one candy.
 *
 * Children with a higher rating get more candies than
 * their neighbors.
 *
 * Return the minimum number of candies you need to
 * have to distribute the candies to the children. */

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        int num_candy = 0;

        // check left neighbors
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i-1] < ratings[i]) {
                candy[i] = candy[i-1] + 1;
            }
        }

        // check right neighbors
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1] && candy[i] < candy[i+1]) {
                candy[i] = candy[i+1] + 1;
            }
        }

        // sum total candy
        for (int i = 0; i < ratings.size(); ++i) {
            num_candy += candy[i];
        }

        return num_candy;
    }
};

