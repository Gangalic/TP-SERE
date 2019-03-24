#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define PASS_SIZE 8
typedef enum { false, true } bool;

int		main(int ac, char **av)
{
	int	sockfd;
	int	connfd;
	int	word_count;
	char 	user[] = "admin";
	char 	password[] = "lI#54";
	char	buffer[PASS_SIZE];
	bool 	logged = false;
	socklen_t addr_size;
	struct sockaddr_in server;

	if (ac != 2)
	{
		printf("usage: ./server [PORT]\n");
		return (0);
	}

	// Socket descriptor
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		printf("error in socket\n");
		return (0);
	}

	// Clean structure
	memset(&server, '0', sizeof(server));

	// Set parameters for connection (protocol IPv4, any machine IP, port)
	server.sin_family = PF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	printf("%d\n", server.sin_addr.s_addr);
	server.sin_port = htons(atoi(av[1])); 

	// Connect the socket with struct parameters (IP, port..)
	if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0)
	{
		printf("error in bind\n");
		return (0);
	}

	// Listen with max of 5 connections
	listen(sockfd, 5);

	// Connect to client
	addr_size = sizeof(server);
	connfd = accept(sockfd, (struct sockaddr*)&server, &addr_size);
	if (connfd < 0)
	{
		write(1, "connection error\n", 17);
		return (0);
	}

	while (!logged)
	{
		// here to add the overflow
		word_count = read(connfd, buffer, 255);
		buffer[word_count] = '\0'; 
		if (!strcmp(buffer, password)){
			write(connfd, "Welcome back admin!\n", 20);
			logged = true;
		} else
			write(connfd, "Wrong password\n",15);
		//printf("New pass: %s  ---- Buffer: %s\n",password, buffer); //-> for checking
		// Close the connections
	}
	close(connfd);
	return (0);
}
