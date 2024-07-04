#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>

int main(){
    int ssd, nsd, clilen, n, f;
    char line[100], fline[300];
    struct sockaddr_in cliaddr, servaddr;

    // Create a TCP socket
    ssd = socket(AF_INET, SOCK_STREAM, 0);

    

    // Set address structure fields
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(33345);

    // Bind the socket to the address and port
    bind(ssd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    

    // Listen for incoming connections
    listen(ssd, 5);

    while (1) {
        // Accept a new connection
        clilen = sizeof(cliaddr);
        nsd = accept(ssd, (struct sockaddr *)&cliaddr, &clilen);
        // Read the file name from the client
        bzero(line, 100);
        read(nsd, line, 100);

        printf("The requested file is %s\n", line);

        // Open the requested file
        f = open(line, O_RDONLY);

        // Read the contents of the file
        bzero(fline, 300);
        n = read(f, fline, 300);

        printf("The contents are: %s\n", fline);

        // Send the contents of the file to the client
        write(nsd, fline,strlen(fline));
        close(f); // Close the file
        close(nsd); // Close the connection
    }

    close(ssd); // Close the server socket
    return 0;
}
