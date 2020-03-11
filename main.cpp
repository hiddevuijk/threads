#include <iostream>
#include <thread>
#include <vector>


using namespace std;

void dowork()
{
    
    

}


int main()
{

    thread worker(dowork);
    worker.join();


    return 0;
}
