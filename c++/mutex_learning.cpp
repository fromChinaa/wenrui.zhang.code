#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;

void work1(int& sum,mutex &lock) {
	for (int i = 1; i < 50000; i++) {
      lock_guard<mutex> mylock(lock);
		sum += i;
       
	}
}

void work2(int& sum,mutex &lock) {
	for (int i = 50000; i <= 100000; i++) {
       lock_guard<mutex> mylock(lock);
		sum += i;
       
	}
}

int fun() {
	int sum = 0;
	for (int i = 1; i <= 100000; i++) {
		sum += i;
	}
	return sum;
}

int main()
{
	int ans = 0;
    mutex mtx;
	std::thread t1(work1, std::ref(ans),ref(mtx));
	std::thread t2(work2, std::ref(ans),ref(mtx));
	t1.join();
	t2.join();
	std::cout << "sum1 : " << ans << std::endl;
	std::cout << "sum2 : " << fun() << std::endl;
	return 0;
}