#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h>  
int main() 
{ 
    struct sockaddr_in address; 
    int socket = 0;  
    char buffer[1024] = {0}; 
    if ((socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Error \n"); 
        return -1; 
    }  
    memset(&serv_addr, '0', sizeof(serv_addr)); 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(8080); // 8080 is port number
       
    if (connect(socket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(socket , strlen(h) , 0 ); 
    printf("Connected\n");  
    return 0; 
}
