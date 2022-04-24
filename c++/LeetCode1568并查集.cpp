#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
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
    count = count -1;
    forest[row-1].push_back(count);
    return forest;
};
vector<vector<int> > combine(vector<vector<int> > smallset,int target)
{
    vector<int> temp;
    int row = smallset.size();
    for(int i = 0; i< row ;i++)
    {
        if(count(smallset[i].begin(), smallset[i].end(),target) != 0)
        {
            temp.push_back(i);
        }
    }
    if(temp.size() == 1)
    {
        return smallset;
    }
    else {
    
        //第一步添加，第二步删除
        for(int i = 1;i < temp.size(); i++)
        {
            smallset[temp[0]].insert(smallset[temp[0]].end(),smallset[temp[i]].begin(),smallset[temp[i]].end());
        }
          for(int i = 1;i < temp.size(); i++)
        {
            smallset.erase(smallset.begin()+temp[i]-i+1);
        }

    }
    return smallset;

}
vector<vector<int> > findBridge(vector<vector<int> > forest)
{
    vector<vector<int> >bridge;
    int row = forest.size();
    int column = forest[0].size();
    cout<<column<<endl;
    cout<<row<<endl;
    int left = 0 ,right = 0,up = 0, down = 0,left_up = 0 ,right_up = 0,left_down = 0, right_down = 0;
    int count = 1,bridge_num = 0;
    for(int i = 0;i < row ;i++)
    {
        for(int j = 0 ;j < column ;j++)
        {
            left = 0 ;
            right = 0;
            up = 0;
             down = 0;
             left_up = 0 ;
             right_up = 0;
             left_down = 0;
              right_down = 0;
              cout<< i<< " "<<j<<endl;
            if(forest[i][j] != 0)
            {
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
                // if( i == 0 && j ==5)
                // {
                //     cout<<left<<" "<<right<<" "<<right_down<<" "<<right_up<<" "<<left_down<<" "<<left_up<<" "<<up<<" "<<down<<endl;
                // }
                if(left ==1 && right ==1 && up == 1 && down ==1 &&left_down == 1 && left_up ==1 && right_down == 1 && right_up == 1)
                {
                   continue;;
                }
                if(left != 0 || right != 0 || up != 0 || down !=0 )
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
}
vector<vector<int> > jointSearchSet(vector<vector<int> > forest)
{
    //第一步找出有多少个数字1 n
    //第二步建立n个数组，使用vector
    //第三步，根据森林中的一个个数字和并数组
    forest = preSolve(forest);
    int row = forest.size();
    int column = forest[0].size();
    int n = 0;
    if(row == 1)
    {
        n = forest[0][column-1];
        column = column -1;
    }   
    else {
        n = forest[row -1][column];
    }
    vector<vector<int> > smallSet;
    smallSet.resize(n);
    int count = 0;
    int center =0 ,left = 0,right = 0,up = 0,down = 0;
     for(int i = 0 ;i < row; i++)
    {
        for(int j = 0 ; j < column ;j++)
        {
            if(forest[i][j] != 0)
            {
                center = forest[i][j];
                smallSet[count].push_back(center);
                if(j - 1 >=0)
                {
                    left =  forest[i][j-1];
                    smallSet[count].push_back(left);
                }
                if(j + 1 < column )
                {
                    right = forest[i][j+1];
                    smallSet[count].push_back(right);
                }
                if(i - 1 >= 0)
                {
                    up = forest[i-1][j];
                    smallSet[count].push_back(up);
                }
                if(i + 1 < row )
                {
                    down = forest[i+1][j];
                    smallSet[count].push_back(down);
                }
                count++;
            }
        }
    }
    //根据forest中的数字进行数组合并
    //  for(int i = 0 ; i < smallSet.size(); i++)
    // {
    //     for(int j = 0; j<smallSet[i].size(); j++)
    //     {
    //         cout<< smallSet[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i = 0; i < row ;i++)
    {
        for(int j = 0; j < column ; j++)
        {
            if(forest[i][j] != 0)
            smallSet = combine(smallSet, forest[i][j]);
        }
    }
    return smallSet;

};
int main()
{
    vector<vector<int> > island ={
    {1,1,1,1,0,1},{1,1,1,1,1,1},{0,1,1,1,0,1},{1,1,0,1,1,1},
    {1,1,1,1,1,1},{0,1,1,0,1,1}
    }
;

    vector<vector<int> > island1 ={ { 1,0,0,0 } ,{0,1,1,1}};
    vector<vector<int> > result = combine( island1 ,0 );
    // for(int i = 0 ; i < result.size(); i++)
    // {
    //     for(int j = 0; j<result[i].size(); j++)
    //     {
    //         cout<< result[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
     vector<vector<int> > smallset = jointSearchSet(island);
    vector<vector<int> > bridge = findBridge(island);
    //      for(int i = 0 ; i < bridge.size(); i++)
    // {
    //     for(int j = 0; j<bridge[i].size(); j++)
    //     {
    //         cout<< bridge[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
     if(smallset.size() != 1)
     {
        cout<<"0"<<endl;
        cout<<"dasda"<<endl;
        return 0;

     }

    vector<vector<int> > c = preSolve(island);
    int c_row = c.size();
    int c_column = c[c_row - 1].size();
    if(c[c_row-1][c_column - 1] == 1)
    {
        cout<<"1"<<endl;
        return 1;
    } 
    
  
    if(bridge.size() == 0)
    {
        cout<<"2"<<endl;
        return 0;
    }
    for(int i = 0 ;i < bridge.size(); i++)
    {
        //砸桥 将1置位 0

      island[bridge[i][0]][bridge[i][1]] = 0;
     vector<vector<int> > smallset_temp = jointSearchSet(island);
     if(smallset_temp.size() != 1)
     {
       cout<<"1"<<endl;
       return 0;
     }
     else {
      island[bridge[i][0]][bridge[i][1]] = 1;
     }
    }
    cout<<"2"<<endl;
    return 0;
}

