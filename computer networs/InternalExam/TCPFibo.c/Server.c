#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
    int sd,n,len;
    int fibonacci[30];
    struct sockaddr_in servaddr,cliaddr;

    sd=socket(AF_INET,SOCK_STREAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(33345);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(sd,5);
    len=sizeof(cliaddr);
    int ssd=accept(sd,(struct sockaddr*)&cliaddr,&len);

    read(ssd,&n,sizeof(n));

    fibonacci[0]=0;
    fibonacci[1]=1;
    for(int i=2;i<n;i++){
        fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
    }
    send(ssd,fibonacci,n * sizeof(int),0);
}