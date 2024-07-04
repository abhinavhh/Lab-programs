#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<time.h>
void main(){
    int sd,len,n;
    char buffer[1024];
    struct sockaddr_in servaddr,cliaddr;

    sd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    len=sizeof(cliaddr);

    n=recvfrom(sd,buffer,1024,0,(struct sockaddr*)&cliaddr,&len);
    buffer[n]='\0';
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,1024,"%Y-%m-%d %H:%M;%S",timeinfo)

    sendto(sd,buffer,1024,0,(struct sockaddr*)&cliaddr,sizeof(servaddr));
    
}