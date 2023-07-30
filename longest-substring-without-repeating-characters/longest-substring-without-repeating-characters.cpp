class Solution {
public:
    int lengthOfLongestSubstring( string s ) {

        int left = 0, maxSub = 0;
        unordered_map<int, int> charCount;
        for(int right = 0; right < s.size(); right++) {
            charCount[s[right]]++;

            while(charCount[s[right]] > 1){
                charCount[s[left]]--;
                left++;
            }

            maxSub = max( maxSub, right - left + 1);

        }
        return maxSub;

    }

    
};