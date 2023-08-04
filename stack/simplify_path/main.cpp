#include "simplifyPath.h"

int main() {
    string line;
    Solution solution;

    while (getline(cin, line)) {
        cout << solution.simplifyPath(line) << endl;
    }

    return 0;
}

