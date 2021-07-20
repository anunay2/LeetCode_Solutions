class Solution {
public:
    struct TrieNode{
        TrieNode* child[2];
        TrieNode(){
            child[0]= NULL;
            child[1] = NULL;
        }
        
    };
    struct TrieNode* getNode(){
        struct TrieNode* newNode = new TrieNode();
        return newNode;
    }
    int findMaximumXOR(vector<int>& nums) {
        if( nums.size()==0){
            return 0;
        }
        TrieNode *root = getNode();
        int max =0;
        for(int num: nums){
            TrieNode *current = root,*complement = root;
            int value =0;
            
            for(int i=31;i>=0;i--){
                int bit = (num >> i) & 1;
                
                if(current->child[bit] == NULL){
                    current->child[bit] = getNode();
                }
                current = current->child[bit];
                
                if(complement->child[1-bit] != NULL){
                    complement = complement->child[1-bit];
                    value += (1<<i);
                }
                else{
                    complement = complement->child[bit];
                }
                max = max>value?max:value;
            }
        }
        
        return max;
        
    }
};