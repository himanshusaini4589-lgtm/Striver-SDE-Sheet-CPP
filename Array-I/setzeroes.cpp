/*
 * Problem   : <Problem Name>
 * Link      : <LeetCode/GfG link>
 * Topic     : <Arrays / LinkedList / Graph / DP / ...>
 *
 * Approach  : <one-line intuition — e.g. "two pointers after sorting">
 *
 * Time      : O(?)
 * Space     : O(?)
 */

#include <iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        // basic approach space - o(n*m)
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<pair<int,int> >v;
        // for(int i = 0 ; i<n ; i++ ){
        //     for(int j = 0; j<m ; j++){
        //         if(matrix[i][j]==0){
        //             v.push_back({i,j});
        //         }
        //     }
        // }
        // for(int k = 0 ;k<v.size() ; k++){
        //     auto ele = v[k];
        //     for(int i = 0 ; i<m ; i++){
        //         matrix[ele.first][i] = 0;
        //     }
        //     for(int i = 0 ; i<n ; i++){
        //         matrix[i][ele.second] = 0;
        //     }
        // }


        //space complexity = O(n+m)
        // int n = matrix.size();
        // int m = matrix[0].size();
        // set<int>sr;
        // set<int>sc;
        // for(int i = 0 ; i<n ; i++ ){
        //     for(int j = 0; j<m ; j++){
        //         if(matrix[i][j]==0){
        //             sr.insert(i);
        //             sc.insert(j);
        //         }
        //     }
        // }
        // for(auto ele : sr){
        //     for(int i = 0 ; i<m ; i++){
        //         matrix[ele][i] = 0;
        //     }
        // }
        // for(auto ele : sc){
        //     for(int i = 0 ; i<n ; i++){
        //         matrix[i][ele] = 0;
        //     }
        // }


        //constant space
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;
        for(int j = 0; j < m; j++)
            if(matrix[0][j] == 0)
                 firstRow = true;

        for(int i = 0; i < n; i++)
            if(matrix[i][0] == 0)
                firstCol = true;

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                 }
            }
        }

        for(int i = 1; i < n; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < m; j++)
                    matrix[i][j] = 0;
            }
        }

        for(int j = 1; j < m; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < n; i++)
                    matrix[i][j] = 0;
            }
        }
        if(firstRow){
            for(int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
        if(firstCol){
         for(int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    // output [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
    sol.setZeroes(matrix);
    return 0;
}
