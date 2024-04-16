#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
void main(){
    int csd,len;

    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,cliaddr;

    csd=socket(AF_INET,SOCK_STREAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    connect(csd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    printf("Client Says : ");
    fgets(sendmsg,30,stdin);
    sendmsg[strlen(sendmsg)-1]='\0';

    send(csd,sendmsg,20,0);

    recv(csd,recvmsg,20,0);

    printf("Palindrome is : %s",recvmsg);
}