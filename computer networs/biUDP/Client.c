#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>

void main(){
    int csd;
    char send[30],recv[30];
    struct sockaddr_in servaddr,cliaddr;

    csd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    connect(csd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    int len=sizeof(servaddr);
    do{
        printf("\nClient : ");
        fgets(send,30,stdin);
        sendto(csd,send,strlen(send),0,(struct sockaddr*)&servaddr,sizeof(servaddr));

        int n=recvfrom(csd,recv,sizeof(recv),0,(struct sockaddr*)&servaddr,&len);
        recv[n]='\0';
        printf("\nServer says : %s",recv);
    }while((strncmp(send,"bye",3))==0 && (strncmp(recv,"bye",3))==0);
}