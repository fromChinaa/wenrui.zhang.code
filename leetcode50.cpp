#include<iostream>
#include <vector>
using namespace std;
double myPow(double x ,int n )
{
    double res = 0;
    int temp = n;
    if(n < 0)
        n = - n;
    if(n == 3)
    {
        res = x*x*x;
        if(temp < 0)
        {
            return 1.0/res;
        }
        return res;
    }
    if(n == 2)
    {
        res = x*x;
        
        if(temp < 0)
        {
            return 1.0/res;
        }
        return res;
    }
    if(n == 1)
    {
        if(temp < 0)
        {
            return 1.0/x;
        }
        return x;
    }
    if(n == 0)
    {
        return 1;
    }
    if(temp < 0)
        {
            return 1.0/myPow(x, n/2)*myPow(x, n-n/2);
        }
    return myPow(x, n/2)*myPow(x, n-n/2);
}
int maxYueShu(int n )
{
    
}
int main()
{
    double res = myPow(2, -2);
    cout<<res<<endl;
    return 0;
}