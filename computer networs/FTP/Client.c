#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char filename[100];
    char buffer[300];

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set server address structure fields
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(33345);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change to server IP if needed

    // Connect to the server
    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    // Get the filename from the user
    printf("Enter the file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove newline character

    // Send the filename to the server
    write(sockfd, filename, strlen(filename));

    // Read the file contents from the server
    bzero(buffer, 300);
    read(sockfd, buffer, 300);
    
    // Print the file contents
    printf("File contents:\n%s\n", buffer);

    close(sockfd);
    return 0;
}
