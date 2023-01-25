#include <stdio.h>
#include <stdlib.h>

#define MAX 20

float k_i(float k, int n);
int fact(int n);

int main() {
	int i, j, n;
	float k, x, x0, h, X[MAX], y[MAX][MAX];
	printf("  Degisken sayisini giriniz: ");
	scanf("%d", &n);
	printf("  Fonksiyonun baslangic degerini giriniz (x0): ");
	scanf("%f", &x0);
	printf("  x degerlerinin artim miktarini (farkini) giriniz: ");
	scanf("%f", &h);
	
	for(i=0; i<n; i++){
		X[i] = x0+i*h;
	}
	
	printf("\n  Fonksiyonun y [f(x)] degerlerini giriniz: \n");
	for(i=0; i<n; i++){
		printf("\tf(%.f): ", X[i]);
		scanf("%f", &y[i][0]);
	}
	
	for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }
	
	printf("\n");
	for(i=0; i<n; i++){
		printf("%10.f", X[i]);
		for(j=0; j<n-i; j++){
			printf("%10.2f", y[i][j]);
		}
		printf("\n");
	}
	
	printf("\n  Bulmak istediginiz x degerini giriniz: ");
	scanf("%f", &x);
	
	float sum = y[0][0];
    k = (x - X[0]) / h;
    for (i = 1; i < n; i++) {
        sum = sum + (k_i(k, i) * y[0][i]) / fact(i);
    }
	
	printf("\n\tF(%.2f) = %.4f", x, sum);
	
	return 0;
}

float k_i(float k, int n){
    float temp = k;
    int i;
    for (i = 1; i < n; i++)
        temp = temp * (k - i);
    return temp;
}

int fact(int n){
    int i, f=1;
    for (i = 1; i <= n; i++)
        f *= i;
    return f;
}
