#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main(){
    int csd,n;
    int recvmsg[30];
    struct sockaddr_in servaddr,cliaddr;

    csd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(33345);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    printf("Enter the no of terms: ");
    scanf("%d",&n);
    int len=sizeof(servaddr);
    sendto(csd,&n,sizeof(n),0,(struct sockaddr*)&servaddr,sizeof(servaddr));

    recvfrom(csd,recvmsg,n * sizeof(int),0,(struct sockaddr*)&servaddr,&len);

    for(int i=0;i<n;i++){
        printf("%d\t",recvmsg[i]);
    }
}