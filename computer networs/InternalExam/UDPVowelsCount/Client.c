#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main(){
    int csd;
    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,clieaddr;

    csd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    printf("Client : ");
    fgets(sendmsg,30,stdin);

    sendto(csd,sendmsg,strlen(sendmsg),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
    int len=sizeof(servaddr);
    int n=recvfrom(csd,(char *)recvmsg,30,0,(struct sockaddr*)&servaddr,&len);
    recvmsg[n]='\0';
    printf("count : %s",recvmsg);
}

    