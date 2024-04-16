#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
void main(){
    int ssd,len;

    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,cliaddr;

    ssd=socket(AF_INET,SOCK_STREAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    bind(ssd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    listen(ssd,5);
    len=sizeof(cliaddr);
    int sd=accept(ssd,(struct sockaddr*)&cliaddr,&len);
    recv(sd,recvmsg,20,0);
    int j=0;
    for(int i=(strlen(recvmsg))-1;i>=0;i--){
        sendmsg[j]=recvmsg[i];
        j++;
    }
    printf("%s",sendmsg);
    send(sd,sendmsg,20,0);
}