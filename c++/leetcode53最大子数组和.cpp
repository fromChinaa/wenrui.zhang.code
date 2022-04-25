class Solution {
public:
vector<int> preSolve(vector<int> nums)
{
    int current = 0;
    int sum = 0;
    int n = 0;
    while(true)
    {
        if(current >= nums.size())
        {
            break;
        }
        sum += nums[current];
        if(sum < nums[current])
        {
            
            sum = 0;
            n = current;
        }
        else
        {
            current ++;
        }

    }
         nums.assign(nums.begin()+n,nums.end());
         return nums;
    
}
 vector<vector<int> > justForPreSolve(vector<int>& nums) 
 {
    
     int current = 0;
     int sum = 0;
     int first_right = 0;
     int last_left = 0;
     vector<vector<int> >result;
     //第一步左边，
     //第二步右边
     //若有交集，直接把交集结果计算出来，存入result
     //若无交集，则把三个数组存入result
     vector<int> temp;
     for(int i = 0; i< nums.size();i++)
     {
         sum += nums[i];
         temp.push_back(sum);
     }
     auto first_max_position_temp = max_element(temp.begin() , temp.end());
     first_right = first_max_position_temp - temp.begin();
    
     temp.clear();
     sum = 0;
     for(int i = nums.size()-1; i >= 0;i--)
     {
         sum += nums[i];
         temp.push_back(sum);
     }
    auto last_max_position_temp = max_element(temp.begin() , temp.end());
     int  last_max_position = last_max_position_temp - temp.begin();
     last_left = nums.size() - last_max_position -1;
     sum = 0;
     //判断是否有交集
     if(last_left <= first_right)
     {
         //有交集
         for(int i = last_left; i <=first_right; i++)
         {
             sum += nums[i];
         }
         result.resize(1);
         result[0].push_back(sum);
         return result;
     }
     else {
     //无交集，就会产生三个数组
    
     if(first_right + 1 == last_left )
     {  result.resize(2);
         result[0].assign(nums.begin(), nums.begin() + first_right+1);
         result[1].assign(nums.begin() + last_left ,nums.end());
     }
     else {
        result.resize(3);
        result[0].assign(nums.begin(), nums.begin() + first_right+1);
        result[1].assign(nums.begin()+first_right+1 , nums.begin() + last_left);
        result[2].assign(nums.begin() + last_left ,nums.end());
     }
     
     return result;
     }
         return result;
     
 };
 int maxSubArray(vector<int>& nums) 
 {
     vector<vector<int> > temp;
     vector<vector<int> > temp_temp;
     vector<int> result;
    int count = 0;
    int max = nums[0];
    for(int i = 0 ;i < nums.size(); i++)
    {
        if(nums[i] < 0)
        {
            count ++;
        }
        if(max < nums[i])
        {
            max = nums[i];
        }
    }
    if(count == nums.size())
    {
        return max ;
    }
    temp_temp = justForPreSolve(nums);
    if(temp_temp.size() == 1)
    {
        cout<<temp_temp[0][0]<<endl;
        return temp_temp[0][0];
    }
    while(true)
    {
       if(temp_temp.size() == 2)
       {
        vector<vector<int> > temp1 = justForPreSolve(temp_temp[0]);
        vector<vector<int> > temp2 = justForPreSolve(temp_temp[1]);
    
        result.push_back(temp1[0][0]);
        result.push_back(temp2[0][0]);
        break;
       }
        vector<vector<int> > temp1 = justForPreSolve(temp_temp[0]);
        vector<vector<int> > temp2 = justForPreSolve(temp_temp[1]);
        vector<vector<int> > temp3 = justForPreSolve(temp_temp[2]);
        result.push_back(temp1[0][0]);
        result.push_back(temp3[0][0]);
        temp_temp.clear();
        if( temp2.size() == 1)
        {
            result.push_back(temp2[0][0]);
            break;
        }
        temp_temp = temp2;     
    }
    auto max_position = max_element(result.begin() , result.end());
    cout<< *max_position<<endl;
    return *max_position;
    return 0;

    

 }

};