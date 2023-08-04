class Solution {
private:
    const int decimals[13] = {1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    const string numerals[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
public:
    string intToRoman(int num) {
        int ndx = 12; // start at the current greatest base
        int repeat = 1; // number of times the current base is repeated
        string roman = ""; // final answer
        
        while (num > 0) {
            if (num >= decimals[ndx]) {
                repeat = num / decimals[ndx];
                for (int i = 0; i < repeat; ++i) {
                    roman += numerals[ndx];
                }
                num %= decimals[ndx];
            }
            ndx--;
        }

        return roman;
    }
};
