#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string ctor(string str)
{
    string result = "%*";
    for(int i = 0;i<str.length();i++)
    {
        result += str[i];
        result += "*";
    }
    
    return result;
};
string maxHuiWenString(string str)
{
    string temp = ctor(str);
    string result = "";
    vector<int> p;
    int left = -1,right = -1,center = -1;
    for(int current = 0;current < temp.length(); current++)
    {
        //先看看在不在left right内
        //在用对称，不在用中心扩展
        if(right == temp.length() -1)
        {
            break;
        }
        if( current < right && current > center && ((center - (current -center)) + p[center - (current -center)] -1)
         < center && ( (center - (current -center)) - (p[center - (current -center)] -1) ) > left
         )
        {
            int mirror = center - (current -center);
            p.push_back(p[mirror]);
        }
        else {
            for(int start = current ;start < temp.length(); start ++)
            {
                if(current - (start - current) < 0)
                {
                    break;
                }
                if(temp[start] == temp[current - (start - current)])
                {
                    left = current - (start - current);
                    right = start;
                }
                else {
                break;
                }
            }
            center = current;
            p.push_back(right - center + 1);
        
        }
    }

    auto max_index = max_element(p.begin(),p.end());
    int max = *max_index ;
    int left_sub = max_index - p.begin() - (max -1);
    int right_sub = max_index - p.begin() + max - 1;
    string result_temp = temp.substr(left_sub , 2*max - 2);
    for(int i = 0;i < result_temp.length(); i++)
    {
        if(result_temp[i]!='%' && result_temp[i]!='*' && result_temp[i]!='^' )
        {
            result += result_temp[i];
        }
    }

    return result;

}

int main()
{
    string str = "ccc";
    cout<<maxHuiWenString(str)<<endl;
    return 0;
}
