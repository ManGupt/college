#include <iostream>
#include <thread>
#include <string>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono_literals;

void pid(string name) {
    cout << name << ": " << this_thread::get_id() << endl;
    //this_thread::sleep_for(2000ms);
    for (uint64_t i = 0 ; i == i ; ++i) ;
}

int main() {
    cout << this_thread::get_id() << endl;
    cout << thread::hardware_concurrency() << endl;

    thread t1(pid, "t1");
    //t1 = thread(pid, "t1");
    thread t2(pid, "t2");
    thread::id i1 = t1.get_id();
    thread::id i2 = t2.get_id();
    t1.detach();
    t2.detach();

    cout << "main:t1: " << i1 << endl;
    cout << "main:t2: " << i2 << endl;

    //t1.joinable() ? t1.join() : pid("main");
    //t2.joinable() ? t2.join() : pid("main");

    std::thread t;
    std::cout << "before starting, joinable: " << std::boolalpha << t.joinable()
              << '\n';
    t = std::thread(pid, "test");
    std::cout << "after starting, joinable: " << t.joinable() 
              << '\n';
    t.detach();
    //t.join();
    std::cout << "after joining, joinable: " << t.joinable() 
              << '\n';

    std::thread t3(pid, "test");
    std::cout << "t3 before starting, joinable: " << t3.joinable()
              << '\n';
    t3.join();

    vector<thread> vt;
    for (int i =0 ; i < 16; ++i) {
        ostringstream s;
        s << "i" << i;
        vt.push_back(thread(pid, s.str()));
    }
    for (auto& t : vt) {
        t.detach();
    }
    pid("main");
    return 0;
}
