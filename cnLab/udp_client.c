#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"  // Replace with the server's IP address
#define PORT 12345
#define BUFFER_SIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int main() {
    int clientSocket;
    struct sockaddr_in serverAddress;
    socklen_t serverLength;
    char buffer[BUFFER_SIZE];

    // Create socket
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == -1) {
        error("Error creating socket");
    }

    // Set up server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(PORT);

    if (inet_pton(AF_INET, SERVER_IP, &(serverAddress.sin_addr)) <= 0) {
        error("Invalid server address");
    }

    // Send message to server
    printf("Enter a message to send: ");
    fgets(buffer, sizeof(buffer), stdin);
    serverLength = sizeof(serverAddress);
    if (sendto(clientSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&serverAddress, serverLength) < 0) {
        error("Error sending message");
    }

    // Receive message from server
    memset(buffer, 0, sizeof(buffer));
    if (recvfrom(clientSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&serverAddress, &serverLength) < 0) {
        error("Error receiving message");
    }
    printf("Received message from server: %s\n", buffer);

    // Close socket
    close(clientSocket);

    return 0;
}
