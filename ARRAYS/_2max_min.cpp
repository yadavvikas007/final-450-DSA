//find max and min elements in min no. of comparisons
#include <iostream>
using namespace std;

struct Pair
{
	int min;
	int max;
};

Pair minmax1(int a[], int n)		//O(N) linear search
{
	Pair b;
	if (n == 1) {b.min =  b.max = a[0];}
	if (a[0] > a[1]) {b.min = a[1]; b.max = a[0];}
	else {b.min = a[0]; b.max = a[1];}
	for (int i = 2; i < n; i++)
	{
		if (a[i] > b.max)b.max = a[i];
		else if (a[i] < b.min)b.min = a[i];
	}
	return b;				//1+2(n-2) worst case(reverse sorted) comparisons
}							//1+(n-2) best case(sorted ) comparisons

Pair minmax2(int a[], int l, int h)		//O(N) divide an conquer
{
	Pair s;								//T(N)=T(floor(n/2))+T(ceil(n/2))
	if (l == h)							//T(2)=1
	{	s.min = s.max = a[l];			//T(1)=0
		return s;						//for N is a power of 2: T(N)=2T(n/2)+2
	}									//3n/2-2 comparisons for n is a power of 2
	else if (h == l + 1)				//for non power of 2 greater than 3n/2-2
	{
		if (a[l] > a[h])
		{
			s.min = a[h];
			s.max = a[l];
		}
		else {
			s.min = a[l];
			s.max = a[h];
		}
		return s;
	}
	else
	{
		int mid = (l + h) / 2;
		Pair m1 = minmax2(a, l, mid);
		Pair m2 = minmax2(a, mid + 1, h);

		if (m1.min < m2.min) s.min = m1.min;
		else s.min = m2.min;

		if (m1.max > m2.max) s.max = m1.max;
		else s.max = m2.max;
		return s;
	}
}

Pair minmax3(int a[], int n)		//O(N)----pick in pairs
{
	Pair s;
	int i;
	if (n % 2 == 0)		//n even
	{
		if (a[0] > a[1]) {s.max = a[0]; s.min = a[1];}
		else {s.min = a[0]; s.max = a[1];}
		i = 2;
	}
	else 			//n odd
	{
		s.min = s.max = a[0];
		i = 1;
	}
	while (i < n - 1)	//pick in pairs
	{
		if (a[i] > a[i + 1])
		{
			if (a[i] > s.max) s.max = a[i];
			if (a[i + 1] < s.min) s.min = a[i + 1];
		}
		else
		{
			if (a[i + 1] > s.max) s.max = a[i + 1];
			if (a[i] < s.min) s.min = a[i];
		}
		i += 2;			//next pair
	}
	return s;
}	/*If n is odd:    [3*(n-1)/2]
      If n is even:   1 Initial comparison for initializing min and max,
      and 3(n-2)/2 comparisons for rest of the elements
      =  1 + 3*(n-2)/2 = [3n/2 -2]     */
void printarray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	printarray(a, 10);
	Pair b = minmax3(a, 10);
	cout << "minimum is " << b.min << "\n";
	cout << "maximum is " << b.max;
}