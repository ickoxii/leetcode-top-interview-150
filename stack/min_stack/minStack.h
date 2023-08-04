 /* Design a stack that supports push, pop, top, and
  * retrieving the minimum element in constant time.
  *
  * Implement the MinStack class:
  * MinStack() - initializes the stack object
  * void push(int val) pushes val to the stack
  * void pop() removes the element on the top of the stack
  * int top() gets the top element of the stack
  * int getMin() retrieves the minimum element in the stack
  *
  * pop, top, and getMin will always be called on 
  * non-empty stacks. */

/* this stack implements a circular array to maintain
 * constant time complexity. */
class MinStack {
private:
    int *data;
    int size, capacity;

    void resize() {
        int *temp = new int[capacity];

        for (int i = 0; i < size; ++i) {
            temp[i] = data[i];
        }

        delete[] data;
        capacity *= 2;
        data = new int[capacity];

        for (int i = 0; i < size; ++i) {
            data[i] = temp[i];
        }
    }
public:
    MinStack() {
        capacity = 4;
        size = 0;
        data = new int[capacity];
    }
    
    void push(int val) {
        if (size+1 >= capacity) {
            resize();
        }
        data[size] = val;
        size++;
    }
    
    void pop() {
        size--;
    }
    
    int top() {
        return data[size-1];
    }
    
    int getMin() {
        int minVal = data[0];
        for (int i = 0; i < size; ++i) {
            minVal = min(minVal, data[i]);
        }
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */