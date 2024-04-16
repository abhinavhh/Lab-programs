#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main(){
    int sd,len;

    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,cliaddr;

    sd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);
    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(sd,5);
    len=sizeof(cliaddr);
    int n=recvfrom(sd,(char *)recvmsg,30,0,(struct sockaddr*)&cliaddr,&len);
    int j=0;
    for(int i=(strlen(recvmsg)-1);i>=0;i--){
        sendmsg[j]=recvmsg[i];
        j++;
    }
    sendto(sd,(char *)sendmsg,strlen(sendmsg),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
}
