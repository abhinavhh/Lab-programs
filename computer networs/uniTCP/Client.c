#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main(){
    int csd,len;
    char sendmsg[30],recvmsg[30];
    struct sockaddr_in cliaddr,servaddr;
    csd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);
    connect(csd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    printf("\nEnter the message to send :");
    fgets(sendmsg,20,stdin);
    len=strlen(sendmsg);
    sendmsg[len-1]='\0';
    send(csd,sendmsg,20,0);
}