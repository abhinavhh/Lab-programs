#include<stdio.h>

void main(){
    int i,k,j,x,n;

    printf("\nEnter the no of nodes : ");
    scanf("%d",&n);

    int rt[n][n];
    printf("\nEnter the distances: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("\n[%d][%d]",i,j);
            scanf("%d",&rt[i][j]);
        }
    }

    for(x=0;x<n;x++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    if(rt[i][j] > rt[i][k] + rt[k][j]){
                        rt[i][j] = rt[i][k] + rt[k][j];
                    }
                }
            }
        }
    }
    printf("\nDVT : \n");
    for(i=0;i<n;i++){
        printf("node%d\t",i+1);
    }
    printf("\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",rt[i][j]);
        }
        printf("\n");
    }
}