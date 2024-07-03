#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

void main(){
    int len,sd;
    char send[30],recv[30];
    struct sockaddr_in servaddr,cliaddr;

    sd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    len=sizeof(cliaddr);

    do{
        int n=recvfrom(sd,recv,sizeof(recv),0,(struct sockaddr*)&cliaddr,&len);
        recv[n]='\0';
        printf("\nClient Says : %s",recv);

        printf("\nServer : ");
        fgets(send,30,stdin);
        sendto(sd,send,strlen(send),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
    }while((strncmp(send,"bye",3))==0 && (strncmp(recv,"bye",3))==0);
}