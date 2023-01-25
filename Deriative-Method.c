#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10
#define f(x) fonk(deg, pol, x)
#define df(x) turev(deg, pol, x)

float fonk(int deg, float pol[], float x);
float turev(int deg, float pol[], float x);

int main() {
	int i, deg;
	float pol[MAX];
	float h, x, geri_fark, ileri_fark, merkezi_fark;
	printf("    ONDALIK SAYILARI 'VIRGUL' YERINE NOKTA KULLANARAK GIRINIZ!!\n\n");
	printf("  Fonksiyonun derecesini girin: ");
	scanf("%d", &deg);
	
	printf("  Polinomun katsayilarini girin:\n");
	for(i=deg; i>=0; i--){
		printf("   x^%d'nin katsayisi: ", i);
		scanf("%f", &pol[i]);
	}

	printf("\n  Turevini bulmak istediginiz noktayi giriniz:\n\tx:  ");
	scanf("%f", &x);
	
	printf("\n  Degisim miktarini giriniz:\n\th:  ");
	scanf("%f", &h);
	
	geri_fark = (f(x)-f(x-h))/h;

	printf("\n   Geri farklar ile turev: %.4f", geri_fark);
	
	ileri_fark = (f(x+h)-f(x))/h;
	printf("\n   Ileri farklar ile turev: %.4f", ileri_fark);
	
	merkezi_fark = (f(x+h)-f(x-h))/(2*h);
	printf("\n   Merkezi farklar ile turev: %.4f", merkezi_fark);
	
	printf("\n   ***Analitik turev: %.4f", df(x));

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

float turev(int deg, float pol[], float x){
	int i;
	float sonuc=0;
	for(i=deg; i>=0; i--){
		sonuc+=pol[i]*i*pow(x,i-1);
	}
	return sonuc;
}
