class Solution {
public:
    int lengthOfLastWord(string s) {
        int ndx = s.size() - 1, size = 0;        
        char *front = (&s[0])+ndx, *rear = NULL;

        while (*front == ' ') {
            front--;
            ndx--;
        }

        rear = front;

        while (ndx > 0 && *front != ' ') {
            front--;
            ndx--;
        }

        size = (int)(rear-front);
        if (ndx == 0 && *front != ' ') {
            size++;
        }
        return size;
    }
};
