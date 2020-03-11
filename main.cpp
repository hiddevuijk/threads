#include <iostream>
#include <thread>
#include <vector>


using namespace std;

static bool s_Finished = false;

const int I = 10000;
const int J = 10000;
vector<vector<double> > m(I,vector<double>(J,0));
vector<vector<double> > n(I,vector<double>(J,0));

void dowork()
{
	using namespace literals::chrono_literals; 
	while( !s_Finished )
	{
		cout << "Working ... \n";
		this_thread::sleep_for(1s);
	}

}

void add_even()
{
	for(int i=0;i<I;++i)
	{
		for(int j=0;j<J;++j)
			m[i][j] += 1;
	}
}

void add_odd()
{
	for(int i=0;i<I;++i)
	{
		for(int j=0;j<J;++j)
			n[i][j] += 1;
	}
}

int main()
{
	int N = 50;

	for(int i=0;i<N; ++i )
	{
		thread even(add_even);
		thread odd(add_odd);
		
		even.join();
		odd.join();
	}

	//for(int i=0;i<N; ++i)
	//{
	//	add_even();
	//	add_odd();
	//}
	

	
    //thread worker(dowork);

	//cin.get();
	//s_Finished = true;


    //worker.join();
	//cout << "Done \n";


    return 0;
}
