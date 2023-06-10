#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 12345
#define BUFFER_SIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int main() {
    int serverSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t clientLength;
    char buffer[BUFFER_SIZE];

    // Create socket
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket == -1) {
        error("Error creating socket");
    }

    // Set up server address
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(PORT);

    // Bind socket to address
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0) {
        error("Error binding socket");
    }

    printf("Server started. Waiting for incoming messages...\n");

    // Receive and send messages
    while (1) {
        // Receive message from client
        memset(buffer, 0, sizeof(buffer));
        clientLength = sizeof(clientAddress);
        if (recvfrom(serverSocket, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientAddress, &clientLength) < 0) {
            error("Error receiving message");
        }
        printf("Received message from client: %s\n", buffer);

        // Send message back to client
        if (sendto(serverSocket, buffer, strlen(buffer), 0, (struct sockaddr *)&clientAddress, clientLength) < 0) {
            error("Error sending message");
        }
        printf("Sent message back to client\n");
    }

    // Close socket
    close(serverSocket);

    return 0;
}
