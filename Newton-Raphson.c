#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
#define f(x) fonk(deg, pol, x)
#define df(x) turev(deg, pol, x)


float fonk(int deg, float pol[], float x);
float turev(int deg, float pol[], float x);

int main() {
	int flag, i, deg, itr=1, maxitr;
	float pol[MAX];
	float x0, x1, error;
	printf("    ONDALIK SAYILARI 'VIRGUL' YERINE NOKTA KULLANARAK GIRINIZ!!\n\n");
	printf("Fonksiyonun derecesini girin: ");
	scanf("%d", &deg);
	
	printf("Polinomun katsayilarini girin:\n", deg);
	for(i=deg; i>=0; i--){
		printf("x^%d'nin katsayisi: ", i);
		scanf("%f", &pol[i]);
	}

	printf("Baslangic degerini (x0) giriniz: ");
	scanf("%f", &x0);
	printf("Hata miktarini giriniz: ");
	scanf("%f", &error);
	printf("Maksimum iterasyon sayisini giriniz: ");
	scanf("%d",&maxitr);
	
    while (flag==0 && itr<maxitr){
		x1 = x0 - (f(x0)/df(x0));
        if (fabs(f(x1)-f(x0)) < error)
        {
            printf("%d. iterasyonda bulunan kok = %6.4f\n", itr, x1);
            flag = 1;
        }
        x0=x1;
        itr++;
    }
    if(flag==0)
    	printf("Fonksiyon iraksiyor.");
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

