//Network y sockets en C
//una conexion de punto final de comunicacion entre dos procesos.
//Los sockets son interfaces de bajo nivel para manejar la comunicacion de red usando el modelo cliente-servidor (TCP)

//Stream Socket (TCP) - SOCK_STREAM  Conexion orientada, confiable y con control de flujo

/*Servidor
socket() - crea el socket
bind() - asocia el socket a una direccion ip y puerto
listen() - Escucha las peticiones
accept() - acepta las conexiones entrantes
recv()/send() - comunica con el clilente
close() - Cierra el socket
*/

/*Cliente
socket() - Crea el socket
connect() - se conecta al servidor
send()/recv() - envia y recibe datos
close() - cierre la conexion
*/

/*
socket(int domain, int type, int protocol)
bind(int sockfd, struct sockaddr *addr, socklen_t addrlen)
listen(int sockfd, int backlog)
accept(int sockfd, struct sockaddr *addr, socklen_t addrlen)
connect(int sockfd, struct sockaddr *addr, socklen_t addrlen)
send(int sockfd, const void *buf, size_t len, int flags)
recv(int sockfd, void *buf, size_t len, int flags)
close(int sockfd)
*/

//IP 127.0.0.1 Puerto 8080

//Ejemplo del SERVIDOR TCP
#include <stdio.h>          //printf, perror
#include <string.h>         //memset, strlen
#include <stdlib.h>         //exit, EXIT_FAILURE
#include <unistd.h>         //close, read, write
#include <arpa/inet.h>      //inet_ntoa, htons, sockaddr_in

int main(){

    int server_fd, cliente_fd;
    struct sockaddr_in server, cliente;
    char buffer[1024] = {0};
    int cliente_len = sizeof(cliente);

    //Crear el socket
    server_fd = socket(AF_INET, SOCK_STREAM,0);  //AF_INET = IPv4, SOCK_STREAM = TCP
    if (server_fd == -1){
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }

    //Configurar direccion del servidor
    server.sin_family = AF_INET;            //IPv4
    server.sin_addr.s_addr = INADDR_ANY;    //Escuchar en todas las interfaces disponibles
    server.sin_port = htons(8080);          //El puerto (8080)

    //Enlazar (bind) el socket con la IP y puerto
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0){
        perror("Error al asociar la IP y el puerto con el socket");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    //Poner el socket en modo escucha
    if (listen(server_fd, 3) < 0){      //"3" indica la cantidad maxima de conexiones
        perror("Error al colocar el socket en escucha");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Servidor en espera en el puerto 8080...\n");

    //Aceptar una conexion entrante
    cliente_fd = accept(server_fd,(struct sockaddr *)&cliente, (socklen_t*)&cliente_len);
    if (cliente_fd < 0){
        perror("Error al aceptar una peticion de un cliente");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    //Mostrar la IP del cliente conectado (opcional)
    printf("Cliente conectado desde: %s:%d\n",inet_ntoa(cliente.sin_addr),ntohs(cliente.sin_port));
    
    //Leer datos del cliente
    read(cliente_fd, buffer, sizeof(buffer));
    printf("Mensaje recibido: %s\n",buffer);

    //Enviar una respuesta al cliente
    send(cliente_fd, "Hola desde el servidor", strlen("Hola desde el servidor"),0);

    //Cerrar socket
    close(cliente_fd);
    close(server_fd);

    printf("Conexion cerrada. \n");

    return 0;
}