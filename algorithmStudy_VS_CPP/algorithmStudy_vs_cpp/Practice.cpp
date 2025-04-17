#include <iostream>
#include <list>
using namespace std;

typedef int(*func_ptr)(int);

class Counter {
private:
    static int a;
public:
    static int count; // 선언
    Counter() { count++; }
};

// 클래스 외부에서 정의
int Counter::count = 0;
int Counter::a = 0;

int main() {
    Counter c1;
    Counter c2;
    cout << "Number of objects: " << Counter::count << endl;

    return 0;
}
