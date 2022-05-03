#include <iostream>
#include  <vector>
using namespace std;
   int uniquePaths(int m, int n) {
       vector<vector<int> > road;
       road.resize(m);
       for(int i = 0;i < m ;i++)
       {
           road[i].resize(n);
       }
       road[0][0] = 1;
       
       for(int i = 0;i < m ;i++)
       {
           for(int j = 0 ; j < n ;j++)
           {
                int up = 0;
                int left = 0;
                if(i - 1 >= 0 )
                {
                    up = road[i - 1][j];
                }
                if(j - 1 >= 0)
                {
                    left = road[i][j-1];
                }
                 if(i != 0 || j != 0)
                 
                    road[i][j] = left + up;

           }
       }
       return road[m-1][n-1];
    }
int main()
{
    int res = uniquePaths(3, 7);
    cout<<res<<endl;
    return 0;
}