#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
void main(){
    int csd,len,n;
    char buffer[1024];
    struct sockaddr_in servaddr,cliaddr;

    csd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    len=sizeof(servaddr);

    sendto(csd,"Time request",strlen("Time request"),0,(struct sockaddr*)&servaddr,sizeof(servaddr));

    n=recvfrom(csd,buffer,1024,0,(struct sockaddr*)&servaddr,&len);
    buffer[n]='\0';
    printf("%s",buffer);
}