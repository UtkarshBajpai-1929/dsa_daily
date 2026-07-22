class Solution {
public:
    void changeColor(vector<vector<int>> &img, int i, int j, int newCol, int oldCol){
        if(i<0 || j<0 || i>=img.size() || j>=img[0].size() || img[i][j] != oldCol || img[i][j] == newCol){
            return;
        }
        img[i][j] = newCol;
        changeColor(img, i-1, j, newCol, oldCol);
        changeColor(img, i+1, j, newCol, oldCol);
        changeColor(img, i, j-1, newCol, oldCol);
        changeColor(img, i, j+1, newCol, oldCol);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        changeColor(image, sr, sc, color, image[sr][sc]);

        return image;
    }
};