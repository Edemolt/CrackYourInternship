class Solution {
public:
    int calculate(string s) {
        stack<int> nums; // Stack to store numbers
        stack<char> ops; // Stack to store operators
        int num = 0;
        char sign = '+'; // Default sign

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // Form the number
            }
            if (!isdigit(ch) && !isspace(ch) || i == s.size() - 1) {
                if (sign == '+') {
                    nums.push(num);
                } else if (sign == '-') {
                    nums.push(-num);
                } else if (sign == '*') {
                    int temp = nums.top();
                    nums.pop();
                    nums.push(temp * num);
                } else if (sign == '/') {
                    int temp = nums.top();
                    nums.pop();
                    nums.push(temp / num);
                }
                sign = ch; // Update sign
                num = 0; // Reset number
            }
        }

        int result = 0;
        while (!nums.empty()) {
            result += nums.top();
            nums.pop();
        }
        return result;
    }
};
