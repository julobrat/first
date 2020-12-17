#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr

// funkcja do rozmowy
void func(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 
	while(1) { 
		bzero(buff, sizeof(buff)); 
		printf("\e[0m$ \e[36mDo serwera: \e[0m"); 
		n = 0; 
		while ((buff[n++] = getchar()) != '\n') 
			; 
		write(sockfd, buff, sizeof(buff)); 
		// wyjscie po polsku i po angielsku 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Client Exit...\n"); 
			break; 
		}
		if ((strncmp(buff, "koniec", 4)) == 0) { 
			printf("Zamykamy klienta...\n"); 
			break; 
		}
		bzero(buff, sizeof(buff));
		read(sockfd, buff, sizeof(buff)); 
		printf("\e[31mZ serwera: \e[0m%s", buff);

		// wyjscie po polsku i po angielsku 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Client Exit...\n"); 
			break; 
		}
		if ((strncmp(buff, "koniec", 4)) == 0) { 
			printf("Zamykamy klienta...\n"); 
			break; 
		}
	} 
} 

int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 

	// tworzenie socketa i sprawdzanie czy sie zrobil
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("Nie udalo sie stworzyc socketa.\n"); 
		exit(0); 
	} 
	else
		printf("Udalo sie stworzyc socketa.\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// przypisujemy IP i PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// podlaczamy clienta do serwera
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("Nie udalo sie polaczyc z serwerem.\n"); 
		exit(0); 
	} 
	else
		printf("Polaczono z serwerem.\n"); 

	// funkcja do rozmowy
	func(sockfd); 

	// zamykamy socketa i konczymy
	close(sockfd); 
} 
