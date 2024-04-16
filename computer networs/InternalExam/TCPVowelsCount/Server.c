#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main(){
    int sd,len1;

    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,clieaddr;

    sd=socket(AF_INET,SOCK_STREAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    servaddr.sin_port=htons(33345);

    bind(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    listen(sd,5);

    int ssd;
    len1=sizeof(clieaddr);
    ssd=accept(sd,(struct sockaddr*)&clieaddr,&len1);

    printf("client says..");

    recv(ssd,recvmsg,20,0);
    printf(" %s",recvmsg);
    int count=0;
    for(int i;i<strlen(recvmsg);i++){
        if(recvmsg[i]=='A'||recvmsg[i]=='E'||recvmsg[i]=='I'||recvmsg[i]=='O'||recvmsg[i]=='U'||recvmsg[i]=='a'||recvmsg[i]=='e'
        ||recvmsg[i]=='i'||recvmsg[i]=='o'||recvmsg[i]=='u'){
                count++;
        }
    }
    sprintf(sendmsg,"%d",count);
    send(ssd,sendmsg,20,0);
}