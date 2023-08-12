class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string result = "";
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; // Initialize sum with carry
            if (i >= 0) sum += a[i--] - '0'; // Add the bit from string 'a' if it exists
            if (j >= 0) sum += b[j--] - '0'; // Add the bit from string 'b' if it exists
            
            result.insert(result.begin(), (sum % 2) + '0'); // Append the resulting bit to the result
            carry = sum / 2; // Compute the carry for the next iteration
        }
        
        return result;
    }
};

