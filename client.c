#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef enum { false, true } bool;

int		main(int ac, char **av)
{
	int sockfd;
	char buffer[256];
	bool logged = false;
	struct sockaddr_in server;

	if (ac != 3)
	{
		printf("usage: ./client [IP] [PORT]\n");
		return (0);
	}

	// Socket descriptor
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		printf("error in socket\n");
		return (0);
	}

	// Set parameters for connection
	server.sin_family = PF_INET;
	server.sin_port = htons(atoi(av[2]));
	server.sin_addr.s_addr = inet_addr(av[1]);

	// Attemp a connection
	if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		printf("error in connect\n");
		return (0);
	}

	while(!logged){
		// Ask for the message
		printf("Please enter admin's password: ");
		bzero(buffer, 256);
		fgets(buffer, 255, stdin);
		write(sockfd, buffer, strlen(buffer));
		
		// Save the received message
		bzero(buffer, 256);
		read(sockfd, buffer, 21);
		if (!strcmp(buffer, "Welcome back admin!\n"))
			logged = true;
		buffer[20] = '\0';
		printf("%s\n", buffer);
	}
	printf("Congrats!\nYou managed to finish the variable overflow challenge!\n\n");
	close(sockfd);
	return (0);
}
