#include <iostream>
#include <time.h>
#define  LENGTH		40000
#define  threshold	50
/*
I'm so surprised while quick-sort-threshold only cost 17 vs quick sort 28 !
there must be a best threshold can let algorithm be faster than 17.
*/
using namespace std;
int Partition(int *array, int p, int r);
void Quick_Sort_Threshold(int *array, int p, int r);
void	Insert(int *array, int p, int r);
void Quick_Sort(int* arrray, int p, int r)
{
	int q;
	if (p < r)
	{
		q = Partition(arrray, p, r);
		Quick_Sort(arrray, p, q - 1);
		Quick_Sort(arrray, q+1, r);
	}

}

int Partition(int *array, int p, int r)
{
	int i = p-1;
	int x = array[r];
	for (int j=p;j<r;++j)
	{
		if (array[j] <= x)
		{
			++i;
			int tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
		}
	}
	int tmp = array[r];
	array[r] = array[i+1];
	array[i+1] = tmp;
	return i + 1;
}

void Quick_Sort_Threshold(int *array, int p, int r)
{
	int q;
	if (r - p > threshold)
	{
		q = Partition(array,p,r);
		Quick_Sort(array, p, q - 1);
		Quick_Sort(array, q+1, r);
	}
	else
		Insert(array, p, r);
}

void Insert(int *array, int p, int r)
{
	int i;
	for (int j = p+1;j<=r;++j)
	{
		int key = array[j];
		i = j - 1;
		while (i >=0  && array[i] > key)
		{
			array[i + 1] = array[i];
			--i;
		}
		array[i + 1] = key;
	}
}
int main()
{
	int a[LENGTH] ,b[LENGTH],c[LENGTH];
	for (int i=0;i<LENGTH;++i)
	{
		a[i] = b[i] = c[i] = rand() % (LENGTH * 3);
	//	cout << a[i]<<" ";
	}//cout << endl << endl;
	
	clock_t start1 = clock();
	Quick_Sort(a, 0, LENGTH-1);
	clock_t end1 = clock();
	cout << " quick-sort :" << end1 - start1 << endl;

	start1 = clock();
	Insert(b, 0, LENGTH - 1);
	end1 = clock();
	cout << " insert-sort :" << end1 - start1 << endl;

	start1 = clock();
	Quick_Sort_Threshold(c, 0, LENGTH - 1);
	end1 = clock();
	cout << "quick-sort-threshold " << end1 - start1 << endl;

	for (int i=0;i<LENGTH;++i)
	{
		cout << c[i] << " ";
	}
}