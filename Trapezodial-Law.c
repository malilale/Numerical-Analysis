#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50
#define f(x) fonk(deg, pol, x)

float fonk(int deg, float pol[], float x);

int main() {
	int k, i, deg;
	float pol[MAX];
	float a, b, n, h, sum, sonuc;	
	printf("    ONDALIK SAYILARI 'VIRGUL' YERINE NOKTA KULLANARAK GIRINIZ!!\n\n");
	printf("  Fonksiyonun derecesini girin: ");
	scanf("%d", &deg);
	
	printf("  Polinomun katsayilarini girin:\n");
	for(i=deg; i>=0; i--){
		printf("   x^%d'nin katsayisi: ", i);
		scanf("%f", &pol[i]);
	}

	printf("\n  Integralini almak istediginiz araligi giriniz:\n\t(a,b):  ");
	scanf("%f,%f", &a,&b);
	
	printf("\n  Integrali kac parcaya ayirmak istediginizi giriniz:\n\tn:  ");
	scanf("%f", &n);
	
	h = (b-a)/n;
	sum=0;
	for(k=1; k<=n-1; k++){
		sum += f(a+k*h);
	}
	sonuc = h*(f(a)/2 + f(b)/2 + sum);
	
	printf("\n  Trapez yontemiyle bulunan integral sonucu: %.4f\n", sonuc);	

    return 0;
}
float fonk(int deg, float pol[], float x){
	int i;
	float sonuc=0;
	for(i=deg; i>=0; i--){
		sonuc+=pol[i]*pow(x,i);
	}
	return sonuc;
}
