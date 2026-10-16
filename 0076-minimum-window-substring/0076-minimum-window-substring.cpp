
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        for (char ch : t) {
            need[ch]++;
        }

        int required = 0;
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0) {
                required++;
            }
        }

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int formed = 0;

        for (int right = 0; right < s.size(); right++) {
            char ch = s[right];
            window[ch]++;

            if (need[ch] > 0 && window[ch] == need[ch]) {
                formed++;
            }

            while (formed == required) {
                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                char leftChar = s[left];
                window[leftChar]--;

                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {
                    formed--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};
