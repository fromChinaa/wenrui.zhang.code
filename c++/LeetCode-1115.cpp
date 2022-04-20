#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>
#include <condition_variable>

using namespace std; 
condition_variable cv;
mutex mtx;
bool key = true;
void printFoo()
{
   
    cout<<"foo";
    
};
void printBar()
{
  
    cout<<"bar";
    
};
class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo() {
        if(key){
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
           
			 std::unique_lock<std::mutex> lock(mtx);
            key = false;
            printFoo();
            cv.notify_one(lock);
            cv.wait(lock);
           
       
        	
        
        
        }
        }
    
        }
    };

    void bar() {
       if(!key){
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
         
            mtx.lock();
            printBar();
            cv.notify_one(mtx);
            cv.wait(mtx);
            mtx.unlock();
       
        }
       }
        
        }
    }
};

int main()
{
    
    FooBar f1(5);
    thread t1(&FooBar::foo,f1);
    thread t2(&FooBar::bar,f1);
    t1.join();
    t2.join();
    return 0;
}