#include<stdio.h>
#include<stdlib.h>

void printarray(int A[],int l ,int r)
{
	int i;
	for (i=l; i<=r; i++)
		printf("%3d ",A[i]);
	printf("\n");
}

int *merge(int A[],int m, int B[], int n)
{
	int i = 1,j = 1, k = 1;
	int *C = malloc((m+n+1)*sizeof(int));
	while(i<=m && j<=n)
		if(A[i]<B[j])
			C[k++] = A[i++];
		else
			C[k++] = B[j++];
	while(i<=m)
		C[k++] = A[i++];
	while(j<=n)
		C[k++] = B[j++];
	return C;
}

int *mergesort(int A[], int l, int r)
{	int m;
	if (l>=r)
		return A+l-1;
	m = (l+r)/2;
	return merge(mergesort(A,l,m),m-l+1,mergesort(A,m+1,r),r-m);
}

void main(int argc ,char* argv[])
{
	int r,A[argc];
	for (int i=0;i<argc;i++)
		A[i] = atoi(argv[i]);
	r = argc-1;
	printf("The sorted array is :");
  	printarray(mergesort(A,1,r),1,r);
}
