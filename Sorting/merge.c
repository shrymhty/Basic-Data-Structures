#include<stdio.h>

#define max 10
int a[max] = { 2,1,6,7,3,8,4,10,9,5 };
int b[max];

void merge(int low,int mid,int high)
{
    int l1,l2,i;
	l1=low;
	l2=mid+1;
	for(l1=low,l2=mid+1,i=low;l1<=mid&&l2<=high;i++)
	{
		if(a[l1]<a[l2])
		{
			b[i]=a[l1++];
		}
		else
		{
			b[i]=a[l2++];
		}
	}
	
	//copying the remaining elements
	while(l1<=mid)
	{
		b[i++]=a[l1++];
	}
	while(l2<=high)
	{
		b[i++]=a[l2++];
	}

	//copying the elements to the original array
	for(int j=low;j<=high;j++)
	{
		a[j]=b[j];
	}
}

void mergesort(int p, int r)
{
    int q=(p+r)/2;
    if(q<r)
    {
        mergesort(p,q);
        mergesort(q+1,r);
        merge(p,q,r);
    }
	else 
	{
		return;
	}
}

int main()
{
	printf("List before sorting: \n");
	for(int i=0;i<max;i++)
	{
		printf("%d\t",a[i]);
	}

	int l,h;
	l=0;
	h=max-1;
	mergesort(l,h);
	printf("\nList after sorting: \n");
	for(int i=0;i<max;i++)
	{
		printf("%d\t",a[i]);
	}
}

