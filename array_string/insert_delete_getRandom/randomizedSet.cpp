/* Implement the RandomizedSet class:
 * You must implement the functions of the class
 * such that each function works in average O(1)
 * time complexity. */

// chat gpt version
#include <unordered_map>
#include <vector>
#include <cstdlib> // For rand() function

class RandomizedSet {
private:
    std::unordered_map<int, int> elementIndices;
    std::vector<int> elements;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (elementIndices.count(val) > 0) {
            return false; // Element already exists in the set
        }
        
        elements.push_back(val);
        elementIndices[val] = elements.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (elementIndices.count(val) == 0) {
            return false; // Element doesn't exist in the set
        }
        
        int index = elementIndices[val];
        int lastElement = elements.back();
        
        elements[index] = lastElement;
        elementIndices[lastElement] = index;
        
        elements.pop_back();
        elementIndices.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % elements.size();
        return elements[randomIndex];
    }
};

