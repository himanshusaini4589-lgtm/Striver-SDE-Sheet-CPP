
#include <iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    // output [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    sol.setZeroes(matrix);
    return 0;
}
