//1. reverse an array--------------------------------------------------------------------------------------------

void reversearray(int a[], int l, int h)		//O(N)
{
	for (int i = l, j = h; i < j; i++, j--)
	{
		swap(a[i], a[j]);
	}
}

void reverse(int arr[], int l, int r)		//recursive
{
	if (l < r) {
		swap(arr[l], arr[r]);
		reverse(arr, ++l, --r);
	}
}


//2.find min and max in an array ---------------------------------------------------------------------------------

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


//3. kth smallest and largest element in an array-------------------------------------------------------------

Pair kth_smallest_and_largest(int a[], int n, int k)  //1.using sorting and returning kth smallest and largest
{
	Pair s;
	heapsort(a, n);			//sorting O(NlogN)
	s.ksmall = a[k - 1];
	s.klarge = a[n - k];
	return s;
}

int kth_smallest_1(int a[], int l, int r, int k)	//2. using quick select
{
	if (k > 0 && k <= r - l + 1)
	{
		int pos = randomPartition(a, l, r);
		if (pos - l == k - 1)
			return a[pos];
		if (pos - l > k - 1)
			return kth_smallest_1(a, l, pos - 1, k);
		return kth_smallest_1(a, pos + 1, r, k - pos + l - 1);
	}
	else return INT_MAX;
}
int kth_largest_1(int a[], int l, int r, int n, int k)
{
	if (k > 0 && k <= r - l + 1)
	{
		int pos = randomPartition(a, l, r);
		if (pos - l == n - k)
			return a[pos];
		if (pos - l > k - 1)
			return kth_largest_1(a, l, pos - 1, n, k);
		return kth_largest_1(a, pos + 1, r, n, k - pos + l - 1);
	}
	else return INT_MAX;
}

int kthSmallest(int arr[], int n, int k) 			//3.using max heap to find kth smallest
{
	// Build a max heap of first k elements: O(k) time
	MaxHeap mh(arr, k);

	// Process remaining n-k elements.  If current element is
	// smaller than root, replace root with current element
	for (int i = k; i < n; i++)
		if (arr[i] < mh.getMax())
			mh.replaceMax(arr[i]);

	// Return root
	return mh.getMax(); 		//Time complexity of this solution is O(k + (n-k)*Logk)
} 					//4. same as with min heap we can get kth largest in O(k + (n-k)*logk)

//4. sorting an array of 0,1,2 ---------------------------------------------------------------------------------

void countsort(int a[], int n)      //1. O(N) time complexity ,O(1) space complexity
{
	int i, j;
	int c[3] = {0};				//constant space
	for (i = 0; i < n; i++)
	{
		c[a[i]]++;
	}
	i = j = 0;
	while (j)
	{
		if (c[j] > 0)
		{
			a[i++] = j;
			c[j]--;
		}
		else j++;
	}
}
void sort012(int a[], int n)        //2. Dutch National Flag Algorithm OR 3-way Partitioning
{
	int l = 0;
	int h = n - 1;
	int mid = 0;
	while (mid <= h)
	{
		if (a[mid] == 0) swap(a[l++], a[mid++]);
		if (a[mid] == 1) mid++;
		if (a[mid] == 2) swap(a[mid], a[h--]);
	}
}						//O(N) time complexity , O(1) space complexity

//5. negative elements on the left ------------------------------------------------------------------------------

void rearrange(int a[], int n)		//2 pointer approach
{
	int i, j;
	i = 0; j = n - 1;
	while (i < j)
	{
		while (a[i] < 0)i++;
		while (a[j] > 0)j--;
		if (i < j) swap(a[i], a[j]);	//order not maintained
	}
}
void reverse(int arr[], int l, int r)
{
	if (l < r) {
		swap(arr[l], arr[r]);
		reverse(arr, ++l, --r);
	}
}
void merge(int a[], int l, int m, int r)
{
	int i = l;
	int j = m + 1;
	while (i <= m && a[i] < 0) i++;
	while (j <= r && a[j] < 0) j++;
	reverse(a, i, m);
	reverse(a, m + 1, j - 1);
	reverse(a, i, j - 1);
}
void rearrange3(int a[], int l, int r)	// optimised merge sort
{
	if (l < r)
	{
		int m = l + (r - l) / 2;	//to avoid overflows
		rearrange3(a, l, m);
		rearrange3(a, m + 1, r);
		merge(a, l, m, r);			//order maintained
	}
}

//6. union and intersection of two unsorted arrays-----------------------------------------

int Union(int arr1[], int arr2[], int n, int m)		//sorting(smaller) and searching(in smaller
{
	int c[n + m];									//for all elements of larger )
	int i = 0, j = 0, k = 0;				//O(mlogm + nlogm) , O(mlogn + nlogn)
	if (n > m) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = n;
		n = m;
		m = temp;
	}
	heapsort(arr1, n);
	heapsort(arr1, m);
	while (i < n) c[k++] = arr1[i++];
	while (j < m)
		if (binarySearch(arr1, 0, n - 1, arr2[j]) == -1)
			c[k++] = arr2[j];
	printarray(c, k);
}
int intersection(int arr1[], int arr2[], int n, int m)
{
	int c[n + m];
	int i = 0, j = 0, k = 0;
	if (n > m) {
		int* tempp = arr1;
		arr1 = arr2;
		arr2 = tempp;

		int temp = n;
		n = m;
		m = temp;
	}
	heapsort(arr1, n);
	heapsort(arr1, m);
	while (i < n) c[k++] = arr1[i++];
	while (j < m)
		if (binarySearch(arr1, 0, n - 1, arr2[j]) != -1)
			c[k++] = arr2[j];
	printarray(c, k);
}

//7.