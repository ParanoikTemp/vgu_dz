#include <iostream>
#include <limits>

using namespace std;

int main()
{
	int n = 3, m = 3;
	float arr[3][3] = {{1.0, 2.0, 4.0},
                            	 {5.0, 2.0, 8.0},
                            	 {6.0, 7.0, 8.0}};
	for (int i = 0; i < n; ++i) {
	    float min = numeric_limits<float>::max();
	    for (int j = 0; j < m; ++j) {
	        if (min > arr[i][j]) min = arr[i][j];
	    }
	    cout << min << " ";
	}
}