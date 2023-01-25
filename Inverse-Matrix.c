#include<stdio.h>
#include<math.h>

int main()
{
	float a[10][20], oran;
	int i, j, k, n;
	//nxn boyutundaki kare matris
	printf("Kare matrisin (nxn) boyutunu giriniz: ");
	scanf("%d", &n);
	//Matrisi okuma
	printf("Matrisin katsayilarini giriniz:\n");
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	  {
	   scanf("%f", &a[i][j]);
	  }
	}
	// birim matrisi tanýmlama
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	  {
		   if(i==j)
		   {
		    	a[i][j+n] = 1;
		   }
		   else
		   {
		    	a[i][j+n] = 0;
		   }
	  }
	}
	// Yöntemi uygulama
	for(i=1;i<=n;i++)
	{
	  if(a[i][i] == 0.0)
	  {
		   printf("HATA!");
		   return 0;
	  }
	  for(j=1;j<=n;j++)
	  {
		   if(i!=j)
		   {
			    oran = a[j][i]/a[i][i];
			    for(k=1;k<=2*n;k++)
			    {
			     	a[j][k] -= oran*a[i][k];
			    }
		   }
	  }
	}
	// Köþegenleri 1 yapma
	for(i=1;i<=n;i++)
	{
	  for(j=n+1;j<=2*n;j++)
	  {
	   	a[i][j] /= a[i][i];
	  }
	}
	// Ters matrisi yazdýrma
	printf("\nMatrisin Tersi:\n");
	for(i=1;i<=n;i++)
	{
	  for(j=n+1;j<=2*n;j++)
	  {
	   	printf("%.2f\t",a[i][j]);
	  }
	  printf("\n");
	}
	
	return 0;
}
