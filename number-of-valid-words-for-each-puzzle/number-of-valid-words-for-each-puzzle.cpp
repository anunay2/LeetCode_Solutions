class Solution {
public:
    unordered_map<int,vector<int>> allwords;
    void formAllPossibleWordMask(int firstcharBitPosition, int mask, int i, int pos){
        if(i==26){
            allwords[mask].push_back(pos);
            return;
        }
        if((1<<i)!=(1<<firstcharBitPosition) && ((1<<i) & mask)){
            formAllPossibleWordMask(firstcharBitPosition, mask, i+1,pos);
            formAllPossibleWordMask(firstcharBitPosition, mask & ~(1<<i),i+1,pos);
        }
        else{
            formAllPossibleWordMask(firstcharBitPosition, mask, i+1,pos);
        }
        
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string> &puzzles) {
        
        vector<int> wordmask(words.size());
        vector<int> puzzlesmask(puzzles.size());
        int index =0;
        for(string word : words){
            int mask=0;
            for(char ch: word){
                mask = mask | (1<<(ch-'a'));
            }
            wordmask[index++] = mask;
            
        }
        
        index = 0;
        for(string puzzle : puzzles){
            int mask = 0;
            for( char ch : puzzle){
                mask = mask | (1<<(ch - 'a'));
            }
            formAllPossibleWordMask(puzzle[0]-'a', mask, 0, index++);
            //puzzlesmask[index++] = mask;
        }
        
        
        vector<int> ans(puzzles.size(),0);
        for(int mask : wordmask){
            if(allwords.find(mask) != allwords.end()){
                for(auto index : allwords[mask])
                 ans[index]++;

            }
        
        }
        
        return ans;
        
    }
};