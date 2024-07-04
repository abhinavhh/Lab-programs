#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main(){
    int sockid;
    char buffer[30];
    struct sockaddr_in servaddr;

    sockid=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=INADDR_ANY;
    servaddr.sin_port=htons(33345);


    printf("Client : ");
    fgets(buffer,30,stdin);
    
    sendto(sockid,buffer,strlen(buffer),0,(struct sockaddr*)&servaddr,sizeof(servaddr));
    
}
