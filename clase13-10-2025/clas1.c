// Network y sockets en C
// Una conexión de punto final de comunicación entre dos procesos.
// Los sockets son interfaces de bajo nivel para manejar la comunicación de red usando el modelo
// cliente-servidor (TCP)

// Stream Socket (TCP) - SOCK_STREAM
// Conexión orientada, confiable y con control de flujo

/* Servidor
1) socket()    - Crea el socket
2) bind()      - Asocia el socket a una dirección IP y puerto
3) listen()    - Escucha las peticiones
4) accept()    - Acepta las conexiones entrantes
5) recv()/send() - Comunica con el cliente
6) close()     - Cierra el socket
*/

/* Cliente
1) socket()    - Crea el socket
2) connect()   - Se conecta al servidor
3) send()/recv() - Envía y recibe datos
4) close()     - Cierra la conexión
*/

/*
Socket)int domain, int type, int protocol);
    bind(int sockfd, struct sockaddr *addr, socklen_t addrlen);
    listen(int sockfd, int backlog);
    accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    send(int sockfd, const void *buf, size_t len, int flags);
    recv(int sockfd, void *buf, size_t len, int flags);
    close(int sockfd);
*/

//IP 127.0.0.1 PUERTO 8080

// EJEMPLO DEL SERVIDOR tcp

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int server_fd, cliente_fd;
    struct sockaddr_in server, cliente;
    char buffer[1024] = {0};
    int cliente_len = sizeof(cliente);

    // Crear el socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET = IPv4, SOCK_STREAM = TCP
    if (server_fd == -1) {
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }

    // Configurar dirección del servidor
    server.sin_family = AF_INET; // IPv4
    server.sin_addr.s_addr = INADDR_ANY; // Aceptar conexiones en cualquier IP
    server.sin_port = htons(8080); // Puerto 8080
    
    // Enlazar (bind) el socket con la IP y puerto
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error al asociar la IP y puerto con el socket");
        close(server_fd);
        exit(EXIT_FAILURE);
    }
    {
        /* code */
    }
    
    // Poner el socket en modo escucha
    if (listen(server_fd, 3) < 0) {
        perror("Error al poner el socket en modo escucha");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Esperando conexiones en el puerto 8080...\n");


    // Aceptar una conexión entrante
    //Mostrar la IP y puerto del cliente
    //Leer el mensaje del cliente
    //Enviar un mensaje de respuesta al cliente
}