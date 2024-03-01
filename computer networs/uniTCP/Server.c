#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

void main(){
    int sd,nsd;
    char sendmsg[30],recvmsg[30];
    struct sockaddr_in cliaddr,servaddr;
    sd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);
    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    int len=sizeof(cliaddr);
    listen(sd,5);
    nsd=accept(sd,(struct sockaddr*)&cliaddr,&len);
    printf("\nReceived String : ");
    recv(nsd,recvmsg,20,0);
    printf("%s\n",recvmsg);
}
