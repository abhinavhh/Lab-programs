#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main(){
    int csd,len;

    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,cliaddr;

    csd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    printf("Client  : ");

    fgets(sendmsg,30,stdin);
    sendto(csd,(char *)sendmsg,strlen(sendmsg),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
    len=sizeof(servaddr);
    int n=recvfrom(csd,(char *)recvmsg,30,0,(struct sockaddr*)&servaddr,&len);
    recvmsg[n]='\0';
    printf("\n%s",recvmsg);
}
