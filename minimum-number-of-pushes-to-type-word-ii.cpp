/*

LeetCode_problem_link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/

*/

class Solution {
public:
    int minimumPushes(string word) {

        int numOfTimesButtonPressed = 1, ans = 0;
        map<char, int> letterFreq;
        priority_queue<pair<int, char>> pq;
        for (char ch : word) {
            letterFreq[ch]++;
        }
        int numOfLetters = 0;
        for (auto it = letterFreq.rbegin(); it != letterFreq.rend(); ++it) {
            pq.push({it->second, it->first});
        }
        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            numOfLetters++;
            // cout<<ch<<"\t"<<numOfTimesButtonPressed<<"\n";
            ans += numOfTimesButtonPressed * freq;
            if (numOfLetters % 8 == 0) {
                numOfTimesButtonPressed++;
            }
        }
        return ans;
    }
};
