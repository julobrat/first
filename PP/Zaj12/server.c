#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

// funkcja do rozmowy
void func(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 
	// petla do rozmowy
	while(1) { 
		bzero(buff, MAX); 

		// czytanie wiadomosc i przepisywanie do buffa
		read(sockfd, buff, sizeof(buff)); 
		// wyrzuc dane z buffa na ekran
		printf("\e[36mOd klienta: \e[0m%s\e[0m$ \e[31mDo klienta: \e[0m", buff); 
		// wyjscie po polsku i po angielsku
		if (strncmp("exit", buff, 4) == 0) { 
			printf("Server Exit...\n"); 
			break; 
		}
        if (strncmp("koniec", buff, 4) == 0) { 
			printf("Wychodzimy z serwera...\n"); 
			break; 
		}
		bzero(buff, MAX); 
		n = 0; 
		// wrzuc dane z ekranu do buffa
		while ((buff[n++] = getchar()) != '\n') 
			; 

		// wyslij zawartosc buffa do clienta
		write(sockfd, buff, sizeof(buff)); 

		// wyjscie po polsku i po angielsku
		if (strncmp("exit", buff, 4) == 0) { 
			printf("Server Exit...\n"); 
			break; 
		}
        if (strncmp("koniec", buff, 4) == 0) { 
			printf("Wychodzimy z serwera...\n"); 
			break; 
		}
	} 
} 

int main() 
{ 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 

	// tworzymy socketa i sprawdzamy czy sie udalo
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("Nie udalo sie stworzyc socketa.\n"); 
		exit(0); 
	} 
	else printf("Udalo sie stworzyc socketa.\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// przypisujemy IP i PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	// wiazemy naszego socketa z podanym IP i sprawdzamy czy sie udalo 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("Nie udalo sie zbindowac socketa.\n"); 
		exit(0); 
	} 
	else
		printf("Udalo sie zbindowac socketa.\n"); 

	// Sprawdzamy czy sluchanie dziala
	if ((listen(sockfd, 5)) != 0) { 
		printf("Sluchanie nie dziala.\n"); 
		exit(0); 
	} 
	else
		printf("Sluchamy.\n"); 
	len = sizeof(cli); 

	// Akceptujemy dane z serwera i sprawdzamy czy sie udalo
	connfd = accept(sockfd, (SA*)&cli, &len); 
	if (connfd < 0) { 
		printf("Klient nie zostal zaakceptowany.\n"); 
		exit(0); 
	} 
	else
		printf("Klient zostal zaakceptowany.\n"); 

	// wywolanie faktycznej funkcji do rozmowy
	func(connfd); 

	// zamykamy socketa i konczymy
	close(sockfd); 
} 
