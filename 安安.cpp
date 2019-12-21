#include<iostream>
#include<cmath>
using namespace std;

template <typename E, typename comp>
void mergesort(E A[],E temp[], int left, int right) {
	if left == right return;
	int mid = (left + right) / 2;
	mergesort<E, comp>(A, temp, left, mid);
	mergesort<A, temp, mid + 1, right>;
	for (int i = left, i <= right; i++)
		temp[i] = A[i];
	int i1 = left; int i2 = mid + 1;
	for (int curr = left; curr <= right; curr++) {
		if (i1 == mid + 1)
			A[curr] = temp[i2++];
		else if(i>right)
			A[curr] = temp[i1++];
		else if (comp::prior(temp[i1],temp[i2]))
			A[curr] = temp[i1++];
		else 	A[curr] = temp[i2++];

	}
}


int main()
{

	int shuzu[10] = { 1, 5, 3, 5, 4, 7, 8, 4, 2, 3 };
	int temp[10];
	mergesort<int,int>(shuzu[10],temp[10],0,9);

    return 0;
}
