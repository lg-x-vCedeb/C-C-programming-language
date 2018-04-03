void InsertionSort(int*A,int n);
/*
	A is an array of integers and n is the size of A
	Sort A using insertion sort
*/

void MergeSort(int*A,int left,int right);
/*
	Sort sub-array A[left..right] using merge sort
*/

//int main(void);
/*
	Generate an array, A1, consisting of 10^5 random integers whose
		value are within [0,10^6)
	Generate another array A2 which is identical to A1
	Sort A1 using InsertionSort() and A2 using MergeSort()
	Print the elapsed time in milliseconds during which both search
		functions run, respectively
*/
