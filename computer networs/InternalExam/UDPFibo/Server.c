#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main(){
    int sd,n,len;
    int sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,cliaddr;

    sd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(33345);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    listen(sd,5);
    len=sizeof(cliaddr);

    recvfrom(sd,&n,sizeof(n),0,(struct sockaddr*)&cliaddr,&len);

    sendmsg[0]=0;
    sendmsg[1]=1;
    for(int i=2;i<n;i++){
        sendmsg[i]=sendmsg[i-1]+sendmsg[i-2];
    }
    sendto(sd,sendmsg,n * sizeof(int),0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
}