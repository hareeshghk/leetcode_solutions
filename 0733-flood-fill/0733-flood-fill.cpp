class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int dir[4][2] = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
        };
        queue<pair<int, int>> q;
        int src_color = image[sr][sc];
        image[sr][sc] = color;
        if(color == src_color)return image;
        q.push(make_pair(sr, sc));
        int nr, nc;
        while(!q.empty()){
            auto front = q.front();
            int r = front.first;
            int c = front.second;
            q.pop();
            for(int i=0;i<4;i++){
                nr = r + dir[i][0];
                nc = c + dir[i][1];
                if(nr < 0 || nc < 0 || nr >= n || nc >=m || image[nr][nc] != src_color)continue;
                image[nr][nc] = color;
                q.push(make_pair(nr, nc));
            }
        }
        return image;
    }
};