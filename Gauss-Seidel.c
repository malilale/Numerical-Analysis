#include<stdio.h>
#include<math.h>

#define MAX 10

int main(){
    float x[MAX][MAX+1],a[MAX], error, tmp, sum, e;
    int i,j,itr,N;
    printf("    ONDALIK SAYILARI 'VIRGUL' YERINE NOKTA KULLANARAK GIRINIZ!!\n\n");
	printf("  Degisken sayisini giriniz: ");
	scanf("%d", &N);

    printf("\n  Matrisin katsayilarini giriniz:\n");
	    for(i=0;i<N;i++){
		    for(j=0;j<N+1;j++){
		    scanf("%f",&x[i][j]);
		    }
	    }
	for(i=0; i<N; i++){
		printf("  x%d icin baslangic degerini giriniz: ", i+1);
		scanf("%f", &a[i]);
	}
    printf("\n  Hata miktarini giriniz: ");
    scanf("%f",&error);
    printf("\n  Iterasyon\t");
	for(i=0; i<N; i++){
		printf("x%d\t\t", i+1);
	} 
	printf("\n");
    itr=1;
    int flag=0;
    while(flag==0)
    {
        for(i=0;i<N;i++)
        {
            sum=0;
            for(j=0;j<N;j++)
            if(j!=i) sum+=x[i][j]*a[j];
            tmp=(x[i][N]-sum)/x[i][i];
            e=fabs(a[i]-tmp);
            a[i]=tmp;
        }
        printf(" %5d\t",itr);
        for(i=0;i<N;i++)
        printf(" %12.4f\t",a[i]);
        printf("\n");
        if(e<error)
        {
            printf("\n %2d. iterasyonda bulunan kok:\n", itr);
            for(i=0;i<N;i++)
            printf("  x%d = %7.4f\n", i+1,a[i]);
            flag=1;
        }
 		itr++;
        }
    return 0;
}
