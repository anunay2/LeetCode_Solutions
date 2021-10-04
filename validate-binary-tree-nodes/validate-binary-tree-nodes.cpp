class Solution {
public:
    vector<int> baap;
    vector<int> rank;
    int find_baap(int x){
        return baap[x] == x?x:baap[x] = find_baap(baap[x]);
    }
    bool uni(int x,int y){
        int px = find_baap(x);
        int py = find_baap(y);
        if(px==py || py!=y){
            return false;
        }
        baap[py] = px;
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(n +1, false);
        for(int i=0;i<n;i++){
            baap.push_back(i);
        }
        rank = vector<int> (n,0);
        int edges = 0;
        for(int i=0;i<n;i++){           
            if(leftChild[i]!=-1){
                if(!uni(i,leftChild[i] ))
                    return false;
                edges++;
                //vis[leftChild[i]]=true;
            }
            
            if(rightChild[i] != -1){
                if(!uni(i,rightChild[i])){
                    return false;
                }
                edges++;
               // vis[rightChild[i]] = true;
            }            
            
        }
        if(edges ==  n-1){
            return true;
        }
        return false;
        
    }
};