#include<stdio.h>

int main() {

//	int b[4][4] = {
//		{1, 2, 3, 4},
//		{5, 6, 7, 8},
//		{9, 10, 11, 12},
//		{13, 14, 15, 16}
//	};
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			printf("%d ",b[i][j]);
//		}
//		printf("\n");
//	}
//	int a[2][2];
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2; j ++) {
//			scanf("%d",&a[i][j]);
//		}
//	}
//	Tim phan tu lon nhat cua ma tran
//	int cmax = a[0][0];
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < 2; j++) {
//			if (a[i][j] > cmax) cmax = a[i][j];
//		}
//	}
//	printf("Gia lon nhat cua ma tran: %d\n",cmax);
//	Tim phan tu nho nhat cua ma tran (tuong tu)
	
//	Ma trận vuông: Số hàng n x Số cột n
//	Đường chéo chính
//		Đặc điểm:	i == j
//	Đường chéo phụ
//		Đặc điểm: i, j = n-1 - i; 
//	Duyệt đường chéo chính
//	printf("Duong cheo chinh: ");
//	for (int i = 0; i < 2; i++) {
//		printf("%d ", a[i][i]);
//	}
//	printf("\n");
//	Duyệt đường chéo phụ
//	printf("Duong cheo phu: ");
//	for (int i = 0; i < 2; i++) {
//		printf("%d ", a[i][2-1-i]);
//	}
//	printf("\n");
//	Kich thuoc hang va cot nhap tu ban phim
	int n, m;
	printf("Nhap so luong hang va so luong cot: ");
	scanf("%d %d",&n,&m);
	int matrix[n][m];
//	Nhap gia cua ma tran
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("Nhap gia tri o a[%d][%d] = ",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
//	Hien thi gia tri
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}