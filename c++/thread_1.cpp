#include<thread>
#include<mutex>
#include<iostream>
using namespace std;
int increase(int *p,int times)
{
    cout<<"111"<<endl;
    for(int i=0;i<times;i++)
    {
        ++*p;
    }
    return 0;
}
int main()
{
    int num =0;
    thread thread1(increase,&num,1000000);
    thread thread2([&]()
    {  
        for(int i=0;i<10000;i++)
    {
        ++num;
    }
    });
    thread1.join();
    cout<<"3333"<<endl;
    thread2.join();
    cout<<num<<endl;
    return 0;  
    
    
}