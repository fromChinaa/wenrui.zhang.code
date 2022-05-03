#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define NOROAD 10000
vector<vector<int> > minPath(vector<vector<int> > road_map,int start)
{
    //俩个矩阵

    vector<vector<int> > road;
    int node_num = road_map.size();
    vector<int> no_walked;
    road.resize(node_num);
    for(int i = 0; i < node_num; i++)
    {
        no_walked.push_back(i);
    }
    vector<int> need_iterator ;
    need_iterator.push_back(start);
    road[start].push_back(start);
    road[start].push_back(start);
    vector<int> temp ;
    
    while( need_iterator.size() != 0)
    {
            int current = need_iterator[0];
            
            //第一步添加need,第二步更改road
       
           
            for(int j = 0; j < road_map[current].size(); j++)
            {  
                if(road_map[current][j] != NOROAD && road_map[current][j] != 0)
                {  
                    if(count(temp.begin(),temp.end(),j) != 0)
                    {
                        
                    }
                    else {
                    need_iterator.push_back(j);
                    temp.push_back(j);
                    }
                   
                    

                    //改road[j]
                    if(road[j].size() == 0)
                    {
                        
                        road[j].assign(road[current].begin(),road[current].end());
                        road[j].push_back(j);
                      
                       
                    }
                    else {
                      
                        int old_num = 0;
                        int new_num = 0;
                      
                        for(int m = 0 ;m< road[j].size() - 1;m++)
                        {
                            int first = road[j][m];
                            int next = road[j][m+1];
                            old_num = old_num + road_map[first][next];
                        }
                        
                        for(int k = 0; k < road[current].size() - 1;k++)
                        {
                            int first = road[current][k];
                            int next = road[current][k+1];
                            new_num = new_num + road_map[first][next];
                        }
                        new_num += road_map[current][j];
                        if(new_num < old_num)
                        {
                           
                            road[j].assign(road[current].begin(),road[current].end());
                            road[j].push_back(j);
                          
                        }
            
                    }
                    
               
                }
            }
        
          
             need_iterator.erase(need_iterator.begin());
           
            
            
        
    }
    return road;
    
}
int main()
{
  vector<vector<int>> MAP = {{0, 4, NOROAD, 2, NOROAD},
                             {4, 0, 4, 1, NOROAD},
                             {NOROAD, 4, 0, 1, 3},
                             {2, 1, 1, 0, 7},
                             {NOROAD, NOROAD, 3, 7, 0}};
  vector<vector<int>> road = minPath(MAP, 0);
  for (int i = 0; i < road.size(); i++) {
    for (int j = 0; j < road[i].size(); j++)
      cout << road[i][j] << " ";
    cout << endl;
    }
    cout<<endl;
    return 0;
}