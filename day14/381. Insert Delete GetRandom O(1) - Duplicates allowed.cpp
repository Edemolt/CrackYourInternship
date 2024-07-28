#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

class RandomizedCollection {
private:
    std::vector<int> nums;
    std::unordered_map<int, std::unordered_set<int>> val_to_indices;
    std::random_device rd;
    std::mt19937 gen;

public:
    RandomizedCollection() : gen(rd()) {}
    
    bool insert(int val) {
        nums.push_back(val);
        val_to_indices[val].insert(nums.size() - 1);
        return val_to_indices[val].size() == 1;
    }
    
    bool remove(int val) {
        if (val_to_indices[val].empty()) {
            return false;
        }
        
        int remove_idx = *val_to_indices[val].begin();
        int last_val = nums.back();
        
        nums[remove_idx] = last_val;
        val_to_indices[val].erase(remove_idx);
        val_to_indices[last_val].erase(nums.size() - 1);
        
        if (remove_idx < nums.size() - 1) {
            val_to_indices[last_val].insert(remove_idx);
        }
        
        nums.pop_back();
        
        if (val_to_indices[val].empty()) {
            val_to_indices.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<> dis(0, nums.size() - 1);
        return nums[dis(gen)];
    }
};