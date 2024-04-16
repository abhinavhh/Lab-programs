#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
void main(){
    int sd,n,count=0;
    char sendmsg[30],recvmsg[30];
    struct sockaddr_in servaddr,cliaddr;

    sd=socket(AF_INET,SOCK_DGRAM,0);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(33345);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    bind(sd,(const struct sockaddr*)&servaddr,sizeof(servaddr));
    int len1=sizeof(cliaddr);
    n=recvfrom(sd,(char *)recvmsg,30,0,(struct sockaddr*)&cliaddr,&len1);
    recvmsg[n]='\0';

    for(int i;i<strlen(recvmsg);i++){
        if(recvmsg[i]=='A'||recvmsg[i]=='E'||recvmsg[i]=='I'||recvmsg[i]=='O'||recvmsg[i]=='U'||recvmsg[i]=='a'||recvmsg[i]=='e'
        ||recvmsg[i]=='i'||recvmsg[i]=='o'||recvmsg[i]=='u'){
                count++;
        }
    }
    printf("%s",recvmsg);
    sprintf(sendmsg,"%d",count);
    printf("Count : %d",count);
    sendto(sd,sendmsg,strlen(sendmsg),0,(struct sockaddr *)&cliaddr,sizeof(cliaddr));
}
