#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
void main(){
    int csd,n;
    int fibonacci[30];
    struct sockaddr_in servaddr,cliaddr;

    csd=socket(AF_INET,SOCK_STREAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(33345);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    connect(csd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    printf("Enter the no of terms : ");
    scanf("%d",&n);

    send(csd,&n,sizeof(n),0);

    recv(csd,fibonacci,n * sizeof(int),0);

    for(int i=0;i<n;i++){
        printf("%d\t",fibonacci[i]);
    }
}