#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
vector<vector<int> > preSolve(vector<vector<int> > forest)
{
    int count =1;
    int row = forest.size();
    int column = forest[0].size();
    for(int i = 0 ;i < row; i++)
    {
        for(int j = 0 ; j < column ;j++)
        {
            if(forest[i][j] == 1)
            {
                forest[i][j] = count;
                count++;
            }
        }
    }
    return forest;
};
vector<int> connect_variable ( vector<vector<int> > forest)
{
    vector<int> result;
    int count_temp = 1;
    vector<vector<int> > position;
    forest = preSolve(forest);
    int row = forest.size();
    int column = forest[0].size();
    int first_not_0 = 0;
    int first_heng = 0, first_zong = 0;
    int left = -1 ,right = -1 ,up = -1 ,down = -1;
    for(int i = 0; i < row ; i++)
    {
        if(first_not_0 != 0)
        {
            break;
        }
        for(int j = 0; j < column; j++)
        {
            if(forest[i][j] != 0)
            {
                first_not_0 = forest[i][j];
                first_heng = i;
                first_zong = j;
                break;
            }
        }
    }
    if(first_not_0 == 0)
    {
        //说明矩阵里面全是0，一块陆地都没有
        return result;
    }
    //接下来就是根据这个 first_not_0 来找出第一个连通分量
    //应该用一个while循环，因为你也不知道什么时候连通分量找完
    //结束标志就是left right up down 
    result.push_back(first_not_0);
    position.resize(count_temp);
    count_temp++;
    position[0].push_back(first_heng);
    position[0].push_back(first_zong);
    while(true)
    {
        int left = -1 ,right = -1 ,up = -1 ,down = -1;
        int left_heng = -1, left_zong = -1 , right_heng = -1, right_zong = -1,
        up_heng = -1 , up_zong = -1, down_heng = -1, down_zong = -1;
        if(position.size() == 0)
        {   
            return result;
        }
        
        int start_heng = position[0][0];
        int start_zong = position[0][1];
        if(start_zong - 1 >=0)
            {
               
                if(forest[start_heng][start_zong - 1] != 0)
                { 
                    left = forest[start_heng][start_zong - 1] ;
                    left_heng = start_heng;
                    left_zong = start_zong -1;
                }
            }
        if(start_zong + 1 < column)
            {
                if(forest[start_heng][start_zong + 1] != 0)
                {   
                    right = forest[start_heng][start_zong + 1] ;
                    right_heng = start_heng;
                    right_zong = start_zong + 1;
                }
            }
        if(start_heng - 1 >= 0 )
        {
            if(forest[start_heng - 1][start_zong] != 0 )
            { 
                up = forest[start_heng - 1][start_zong];
                up_heng = start_heng - 1;
                up_zong = start_zong;
            }
        }
        if(start_heng + 1 < row)
        {
            if(forest[start_heng + 1][ start_zong] != 0)
            {   
                down =forest[start_heng + 1][start_zong];
                down_heng = start_heng + 1;
                down_zong = start_zong;
            }
        }

        //开始添加
        //result 和 position 添加
        if(left != -1)
        {
            if(count(result.begin(),result.end(),left) == 0 )
            {   
            result.push_back(left);
            int old_row = position.size();
            position.resize(old_row + 1);
            position[old_row].push_back(left_heng);
            position[old_row].push_back(left_zong);
    
            }
        }
        if(right != -1)
        {
            
              if(count(result.begin(),result.end(),right) == 0 )
            {
          
          result.push_back(right);
          int old_row = position.size();
            position.resize(old_row + 1);
         
            position[old_row].push_back(right_heng);
            position[old_row].push_back(right_zong);

            }
        }
            if(up != -1)
        {
           
               if(count(result.begin(),result.end(),up) == 0 )
            {
            result.push_back(up);
              int old_row = position.size();
            position.resize(old_row + 1);
         
            position[old_row].push_back(up_heng);
            position[old_row].push_back(up_zong);
       
            }
        }
            if(down != -1)
        {
         
               if(count(result.begin(),result.end(),down) == 0 )
            {
            result.push_back(down);
              int old_row = position.size();
            position.resize(old_row + 1);
         
            position[old_row].push_back(down_heng);
            position[old_row].push_back(down_zong);
       
            }
        }
        

        //开始删除原来的位置
        //不管怎样都要删除第一个位置
      
        position.erase(position.begin());

    }
    return result;
}
vector<vector<int> > findBridge(vector<vector<int> > forest)
{
    vector<vector<int> >bridge;
    int row = forest.size();
    int column = forest[0].size();
    int left = 0 ,right = 0,up = 0, down = 0,left_up = 0 ,right_up = 0,left_down = 0, right_down = 0;
    int count = 1,bridge_num = 0;
    for(int i = 0;i < row ;i++)
    {
        for(int j = 0 ;j < column ;j++)
        {
            if(forest[i][j] != 0)
            {
                
            left = 0 ;
            right = 0;
            up = 0;
             down = 0;
             left_up = 0 ;
             right_up = 0;
             left_down = 0;
              right_down = 0;
                if(j - 1 >=0)
                {
                    left =  forest[i][j-1];
        
                }
                if(j + 1 < column)
                {
                    right = forest[i][j+1];
                  
                }
                if(i - 1 >= 0)
                {
                    up = forest[i-1][j];
                   
                }
                if(i + 1 < row )
                {
                    down = forest[i+1][j];
                   
                }
                  if(i - 1 >= 0 && j-1 >= 0 )
                {
                    left_up =forest[i-1][j-1];
                }
                if(i - 1 >= 0  && j + 1 < column )
                {
                   right_up =forest[i-1][j+1];
                }
                if(i+1 < row && j-1 >= 0 )
                {
                    left_down =forest[i+1][j-1];
                }
                if(i+1 < row && j+1 < column  )
                {
                    right_down =forest[i+1][j+1];
                }
                if(left ==1 && right ==1 && up == 1 && down ==1 &&left_down == 1 && left_up ==1 && right_down == 1 && right_up == 1)
                {
                   continue;
                }
                if(left != 0 || right != 0 || up != 0 && down !=0)
                {
                    bridge.resize(count);
                    bridge[bridge_num ].push_back(i);
                    bridge[bridge_num ].push_back(j);
                    count += 1;
                    bridge_num += 1;
                }
             
            }
        }
    }
    return bridge;
};
int not_0_num (vector<vector<int> > forest)
{
    int count = 0;
    for(int i = 0 ; i < forest.size() ; i++)
    {
        for(int j = 0 ;j < forest[i].size() ; j++)
        {
            if(forest[i][j] != 0)
            {
                count++;
            }
        }
    }
    return count;
}
 int minDays(vector<vector<int>>& island) 
        
{
   
vector<int> result = connect_variable(island);
int not_0 = not_0_num(island);
if(result.size() != not_0)
{
    //意味着有多个岛屿
    cout<<"0"<<endl;
    return 0;
}
if(not_0 == 1)
{
    return 1;
}
if(not_0 == 0)
{
    return 0;
}
 vector<vector<int> > bridge = findBridge(island);
 if(bridge.size() == 0)
    {
        cout<<"2"<<endl;
        return 2;
    }
for(int i = 0 ;i < bridge.size(); i++)
    {
        //砸桥 将1置位 0

      island[bridge[i][0]][bridge[i][1]] = 0;
      result = connect_variable(island);
      
     if(result.size() != not_0-1)
     {
       cout<<"1"<<endl;
       return 1;
     }
     else if (result.size() == not_0 -1 && not_0-1 == 1) {
      cout<<"2"<<endl;
       return 2;
     }
     else {
      island[bridge[i][0]][bridge[i][1]] = 1;
     }
    }
    cout<<"2"<<endl;
    return 2;



}
};