class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;

        for (int i = 0; i < columnTitle.size(); i++)
        {
            // Convert columnTitle[i] into a value from 1 to 26
            int value = columnTitle[i] - 'A' +  1;

            // Update result using the base-26 logic
            result=result*26+value;
        }
        return result;
    }
};