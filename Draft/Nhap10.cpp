#include <iostream>
#include <math.h>
void nhapdulieu(int *a, int n)
{
	for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void indayso(int *a, int n)
{
	for (int i = 0; i < n; i++)
        printf("%d ", a[i]);    
}
int tong_u_v(int *a, int n, int u, int v)
{
	int tong = 0;
    for (int i = 0; i < n; i++)
        if (a[i] >= u && a[i] <= v)
            tong += a[i];
    return tong;
}
int cmax;
bool max_chan(int *a, int n)
{
	bool check = false;
    for(int i = 0 ; i < n ; i++) {
    	if (!check && a[i] % 2 == 0) {
			cmax = a[i];
			check = true;
		}
    	else if (check && a[i]%2 == 0 && a[i] > cmax) cmax = a[i];
	}
	if (!check) return false;
	return true;
}
int main()
{
    int n;
    printf("nhap so phan tu: ");
    scanf("%d", &n);
    int arr[n];
    nhapdulieu(arr, n);
    printf("day so ban nhap la:");
    indayso(arr, n);  
    printf("\ntong cac phan tu thuoc day tu 6 den 19 la:%d", tong_u_v(arr, n, 6, 19));
    printf("\ntong cac phan tu thuoc day tu 3 den 100 la:%d", tong_u_v(arr, n, 3, 100));
    printf("\nso chan lon nhat la: ");
	if (max_chan(arr,n)) printf("%d",cmax);
	else printf("Khong ton tai");
}