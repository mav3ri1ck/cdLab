#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888
#define BUFFER_SIZE 1024

void *client_handler(void *arg) {
    int client_fd = *(int *)arg;
    char buffer[BUFFER_SIZE] = {0};
    int valread;

    // Receive and send messages
    while (1) {
        valread = read(client_fd, buffer, BUFFER_SIZE);
        if (valread <= 0)
            break;

        printf("Client: %s", buffer);

        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_fd, buffer, strlen(buffer), 0);

        memset(buffer, 0, BUFFER_SIZE);
    }

    printf("Client disconnected\n");
    close(client_fd);

    pthread_exit(NULL);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    pthread_t thread_id;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to localhost:8888
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Multi-threaded chat server started on port %d\n", PORT);

    // Accept incoming connections and create client threads
    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        printf("New connection, socket fd is %d, IP is: %s, port: %d\n",
               new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        if (pthread_create(&thread_id, NULL, client_handler, (void *)&new_socket) < 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }

        // Detach the thread, so its resources can be automatically released
        pthread_detach(thread_id);
    }

    close(server_fd);

    return 0;
}
