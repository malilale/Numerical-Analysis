#include <stdio.h>
#include <stdlib.h>
#include <math.h>
			
#define MAX 10
#define f(x) fonk(deg, pol, x)
											
float fonk(int deg, float pol[], float x);

int main() {
	int i, deg;
	float pol[MAX];
	float a, b, c, c1, error;
	
	printf("    ONDALIK SAYILARI 'VIRGUL' YERINE NOKTA KULLANARAK GIRINIZ!!\n\n");
	printf("Fonksiyonun derecesini girin: ");
	scanf("%d", &deg);

	printf("Polinomun katsayilarini girin:\n");
	for(i=deg; i>=0; i--){
		printf("x^%d'nin katsayisi: ", i);
		scanf("%f", &pol[i]);
	}

	printf("Kok aranacak araligi (a,b) sirasiyla giriniz: ");
	scanf("%f,%f", &a,&b);
	printf("Hata miktarini giriniz: ");
	scanf("%f", &error);
	
	if(f(a)==0) 
		printf("\n  Kok = %6.4f", a);
	if(f(b)==0) 
		printf("\n  Kok = %6.4f", b);
	else if(f(a)!=0 && f(b)!=0){
		int flag=0;
		c=(a+b)/2;
	
	    while (flag==0){
	    	if(f(c)==0) {printf("\n Kok = %6.4f", c); flag=1;}
	    	else{
		        if (f(a)*f(c) < 0){
		            b=c;
				}
		        else{
		        	a=c;
				}
		        c1=(a+b)/2;
		        if (fabs(f(c1)-f(c)) < error)
		        {
		            printf("  Kok = %6.4f\n", c1);
		            flag = 1;
		        }
		        c=c1;
		    }
	    }
	}
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
