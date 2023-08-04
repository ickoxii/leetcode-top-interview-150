#ifndef SIMPLIFY_PATH_H
#define SIMPLIFY_PATH_H

/* Given a string path, which is an absolute path
 * (starting with a slash '/') to a file or directory
 * in a Unix-style file system, convert it to the 
 * simplified canonical path.
 *
 * In a Unix-style file system, a period '.' refers
 * to the current directory, a double period '..'
 * refers to the directory up a level, and any
 * multiple consecutive slashes (i.e. '//') are treated
 * as a single slash '/'. For this problem, any other
 * format of periods such as '...' are treated as
 * file/directory names.
 *
 * The canonical path should have the following format:
 *
 * The path starts with a single slash '/'.
 * 
 * Any two directories are separated by a single slash '/'.
 *
 * The path does not end with a trailing '/'.
 *
 * The path only contains the directories on the path
 * from the root directory to the target file or directory
 * (i.e., no period '.' or double period '..')
 *
 * Return the simplified canonical path */

#include <string>
#include <stack>
#include <sstream>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string);
};

string Solution::simplifyPath(string path) {
    istringstream inSS;
    inSS.str(path);
    string word;
    stack<string> reversePath;

    // parse string
    while (getline(inSS, word, '/')) {
        if (word == "..") {
            if (!reversePath.empty()) {
                reversePath.pop();
            }
        }
        else if (word == "." || word.empty()) {
        }
        else {
            reversePath.push(word);
        }
    }

    string cannon = "";
    while (!reversePath.empty()) {
        string dir = "/";
        dir += reversePath.top();
        cannon.insert(0, dir);
        reversePath.pop();
    }

    if (cannon.empty()) {
        cannon = "/";
    }

    return cannon;
}

#endif
