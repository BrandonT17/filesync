// main.c simple TCP client
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(){
  // create a socket IPv4 addressing and TCP
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(8080); // set port and convert to network byte order
  // convert local host string IP -> binary
  // then store in server.sin_addr
  inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
  connect(sock, (struct sockaddr*)&server, sizeof(server));
  
  // create and send message
  char *message = "Hello from client!";
  send(sock, message, strlen(message), 0);

  // prepare buffer for receiving message
  FILE *myFile;
  // myFile = fopen("testfile.txt", "r");
  // char myData[100];
  // fgets(myData, 100, myFile);
  // char *myDataPtr = myData;

  // send(sock, myDataPtr, strlen(myDataPtr), 0);


  
  close(sock);
  return 0;

}
