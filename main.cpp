#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

using namespace std;


double median(vector<int> scores);



//TODO: test the the library
int main(){
	int array[] = {32,71,12,45,26,80,53,33};
	std::vector<int> myvector (array, array+8);

	std::sort (myvector.begin(), myvector.end());

	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << endl;

	double medianArray = median(myvector);
	cout << "Median of the array: " << medianArray << endl;

	return 0;
}
