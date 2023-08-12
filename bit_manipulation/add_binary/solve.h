 /**
  * Given two binary strings a and b, return their sum as a
  * binary string. */

class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        bool carry = false;
        int size_a = a.size(), size_b = b.size();
        int size_diff;

        if (b.size() == 0) return a;
        if (a.size() == 0) return b;

        // string b will always be the larger string
        if (size_a > size_b)
            return addBinary(b, a);

        size_diff = size_b - size_a;

        /*
         * a[i] b[i] carry  sum new carry
         *  0    0    0      0      0
         *  0    0    1      1      0
         *  0    1    0      1      0
         *  0    1    1      0      1
         *  1    0    0      1      0
         *  1    0    1      0      1
         *  1    1    0      0      1
         *  1    1    1      1      1 */
        /*
         * a^b  (a^b)^c ((a^b)^c)^sum  a&b carry*(a^b) A&B+carry*(a^b)
         *  0      0         0          0      0            0
         *  0      1         0          0      0            0
         *  1      1         0          0      0            0
         *  1      0         0          0      1            1
         *  1      1         0          0      0            0
         *  1      0         0          0      1            1
         *  0      0         0          1      0            1
         *  0      1         0          1      0            1 */
        // carry = (a&b) + carry*(a^b)
        // sum = (a^b)^c
        for (int i = size_a - 1; i >= 0; --i) {
            bool a_set = (a[i] == '1') ? true : false;
            bool b_set = (b[i] == '1') ? true : false;
            
            // sum
            if (a_set ^ b_set ^ carry)
                sum.insert(0, "1");
            else
                sum.insert(0, "0");

            // new carry
            carry = (a_set & b_set) + carry * (a_set ^ b_set);
        }

        if (size_a == size_b) {
            if (carry)
                sum.insert(0, "1");
            return sum;
        }
        
        for (int i = size_b - size_a - 1; i >= 0; --i) {
            bool b_set = (b[i] == '1') ? true : false;

            // sum
            if (b_set ^ carry)
                sum.insert(0, "1");
            else
                sum.insert(0, "0");

            // new carry
            carry = (b_set) + carry * b_set;
        }

        if (carry)
            sum.insert(0, "1");

        return sum;
    }
};
