class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int count;


    
    int regionsBySlashes(vector<string>& grid) {

        int n = grid.size();
        int dots = n + 1;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;

        int dotslength = dots * dots;

        for(int i = 0;i<dotslength;i++){
            parent[i] = i;
            rank[i] = 1;
        }

        // connecting the border dots
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                if(i==0 || j==0 || i==dots-1 || j==dots-1){ // only when we encounter i j positions at the border
                    int cellno = i*dots + j;
                    unionbyrank(0,cellno);
                }
            }
        }

        //traverse the grid and connect the dots using DSU

        for(int i=0;i<n;i++){  
            for(int j=0;j<n;j++){
                if(grid[i][j] == '/'){ // forward slash at i,j(of grid) always connects the i,j+1 and i+1,j dots
                    int cell1 = i * dots + j+1;
                    int cell2 = (i+1) * dots + j;
                    unionbyrank(cell1, cell2);
                }else if(grid[i][j] == '\\'){ // backward slash at i,j always connects the i,j and i+1,j+1 dots.
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionbyrank(cell1, cell2);

                }
            }
        }

        return count;
        
    }


    int findparent(int node){

        if(parent[node] == node) return node;
        else return parent[node] = findparent(parent[node]);
           
    }

    void unionbyrank(int x, int y){
        int upx = findparent(x);
        int upy = findparent(y);

        if(upx != upy){
            if(rank[upx] > rank[upy]){
                parent[upy] = upx;
            }else if(rank[upx] < rank[upy]){
                parent[upx] = upy;
            }
            else{
                parent[upx] = upy;
                rank[upy]++;
            }
        }else{
            count++;
        }

    }
};