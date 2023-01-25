#include<stdio.h>
#include<math.h>

int main(){
	float a[10][11], x[10], oran, sum;
	int i, j, k, n;
	//nxn boyutundaki kare matris
	printf("Degisken sayisini giriniz: ");
	scanf("%d", &n);
	//Matrisi okuma
	printf("Matrisin katsayilarini giriniz:\n");
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n+1;j++)
	  {
	   scanf("%f", &a[i][j]);
	  }
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i!=j)
			{
			    oran = a[j][i]/a[i][i];
			    for(k=1;k<=n+1;k++)
			    {
			     	a[j][k] -= oran*a[i][k];
				}
			}
		}
	}
    x[n]=a[n][n+1]/a[n][n];
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum += a[i][j]*x[j];
        }
        x[i]=(a[i][n+1]-sum)/a[i][i];
    }
    printf("\nCozum: \n");
    for(i=1; i<=n; i++)
    {
        printf("\n\tx%d = %.3f\t",i,x[i]); // x, y, z yerine x1, x2, x3 
    }
		return 0;
}
