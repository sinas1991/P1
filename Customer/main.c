
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#include <../Utils/io_utils.h>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		return -1;
	}

	int main_budget = atoi(argv[2]);
	char customer_name[30];
	strcpy(customer_name, argv[1]);

	char command[30];
	char line[100];

	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char sending_message[256]; // previously 'buffer'

	while (1)
	{
		read_line(line);
		printf("line:%s\n", line);
		get_word_from_line(line, command, 0);
		printf("command:%s\n", command);
		if (strcmp(command, "Connect") == 0)
		{
			char host[20];
			char port[10];
			get_word_from_line(line, host, 1);
			get_word_from_line(line, port, 2);

			printf("host:%s, port:%s\n", host, port);
			portno = atoi(port);
			sockfd = socket(AF_INET, SOCK_STREAM, 0);
			if (sockfd < 0)
			{
//				throw ConnectionError("Can't open socket");
			}
			server = gethostbyname(host);
			if (server == NULL)
			{
//				throw ConnectionError("host not found");
			}

			bzero((char *) &serv_addr, sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			bcopy((char *)server->h_addr, 
				  (char *)&serv_addr.sin_addr.s_addr,
				  server->h_length);
			serv_addr.sin_port = htons(portno);
			if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
			{
//				throw ConnectionError("Error in connecting");
			}

			printf("connected\n");
			while (1)
			{
				bzero(sending_message,256); // clearing string

				read_line(sending_message);
				printf("2line:%s\n", sending_message);
				if (strcmp(command, "DC") == 0)
				{
					close(sockfd);
					break;
				}
				if (!validate_command(sending_message, customer_name))
				{
					printf("Invalid Command");
					continue;
				}

				n = write(sockfd,sending_message,strlen(sending_message));
				if (n < 0)
				{
//					throw ConnectionError("Error in writing message");
				}
				bzero(sending_message,256);
				n = read(sockfd, sending_message, 255);
				if (n < 0)
				{
//					throw ConnectionError("Error in reading server message");
				}

				printf("respone:%s\n",sending_message);
			}
		}
		else
		{
			//MUST connect to execute commands
		}
	}
}

