//Ejemplo del CLIENTE TCP
#include <stdio.h>          //printf, perror
#include <string.h>         //memset, strlen
#include <stdlib.h>         //exit, EXIT_FAILURE
#include <unistd.h>         //close, read, write
#include <arpa/inet.h>      //inet_ntoa, htons, sockaddr_in

int main(){
    int sock = 0;       //Descriptor del socket del cliente
    struct sockaddr_in server;
    char buffer[1024] = {0};

    sock = socket(AF_INET, SOCK_STREAM,0);  //AF_INET = IPv4, SOCK_STREAM = TCP
    if (sock < 0){
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }

    //Configurar direccion del servidor
    server.sin_family = AF_INET;            //IPv4
    server.sin_port = htons(8080);          //El puerto (8080)

    //Convertir la IP del servidor a binario
    if(inet_pton(AF_INET, "127.0.0.1",&server.sin_addr) <= 0){
        perror("Direccion invalida o no soportada");
        exit(EXIT_FAILURE);
    }

    //Conectamos al servidor
    if(connect(sock, (struct sockaddr*) &server, sizeof(server)) < 0){
        perror("Error al conectar al servidor. \n");
        close(sock);
        exit(EXIT_FAILURE);
    }

    printf("Conectados al servidor. \n");

    send(sock, "Hola servidor", strlen("Hola servidor"),0);

    read(sock, buffer, sizeof(buffer));
    printf("Respuesta del servidor: %s\n",buffer);

    close(sock);
    printf("Conexion cerrada. \n");

    return 0;
}