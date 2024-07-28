class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a hash map to store the grouped anagrams
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& str : strs) {
            // Sort the string to use as the key for the hash map
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            // Add the original string to the corresponding anagram group
            anagramGroups[sortedStr].push_back(str);
        }

        // Prepare the result vector from the hash map
        vector<vector<string>> ans;
        for (auto& group : anagramGroups) {
            ans.push_back(group.second);
        }

        return ans;
    }
};
