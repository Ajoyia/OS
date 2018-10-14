#include <stdio.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <string.h> 

int main() 
{ 
    int server=0, newSocket=0, r=0; 
    struct sockaddr_in address; 
    int option = 1; 
    int size = sizeof(address); 
    char buffer[1024] = {0}; 
        
    if (setsockopt(server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,&option, sizeof(option))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(8080); // 8080 is port number
       
    if (bind(server, (struct sockaddr *)&address,sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((newSocket = accept(server, (struct sockaddr *)&address,(socklen_t*)&size))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
    r = read( newSocket , buffer, 1024); 
    printf("Connected\n"); 
    return 0; 
}
