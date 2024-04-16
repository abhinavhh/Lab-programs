#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main(){
    int csd;

    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,clieaddr;

    csd=socket(AF_INET,SOCK_STREAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    connect(csd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    printf("\nClient : ");
    fgets(sendmsg,30,stdin);
    
    int len=strlen(sendmsg);
    sendmsg[len-1]='\0';
    send(csd,sendmsg,20,0);

    recv(csd,recvmsg,20,0);
    printf("\nCount : %s",recvmsg);
}