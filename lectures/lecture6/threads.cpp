#include <thread>
#include <iostream>

// ./threads > output.txt && vim output.txt

void task() {
    for (size_t i = 0; i < 10000; ++i)
    {
        std::cout << "couting from " << std::this_thread::get_id() << std::endl;
        std::flush(std::cout);
    }
}


int main()
{

    std::thread t1(task);
    std::thread t2(task);
    t1.join();
    t2.join();

    return 0;
}

