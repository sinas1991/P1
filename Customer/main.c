
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

#include <../Utils/io_utils.h>

int main()
{
//	string input, command;
//	getline(cin, input);
//	stringstream ss(input);
//	ss >> command;
	char command[] = "connect";

	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	char sending_message[256]; // previously 'buffer'

	if (command == "disconnect")
	{
//		if (connected == 0)
		{
//			throw InvalidCommand("You are not connected");
		}
//		connected = 0;
		close(sockfd);
		return 0;
	}
//	else if (command == "connect")
	{
		printf("suck!\n");
		char host[] = "localhost";
		char port[] = "8070";

		portno = atoi(port);
		sockfd = socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0)
		{
//			throw ConnectionError("Can't open socket");
		}
		server = gethostbyname(host);
		if (server == NULL)
		{
//			throw ConnectionError("host not found");
		}

		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *)server->h_addr, 
			  (char *)&serv_addr.sin_addr.s_addr,
			  server->h_length);
		serv_addr.sin_port = htons(portno);
		if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
		{
//			throw ConnectionError("Error in connecting");
		}

		while (command != "disconnect" && command != "exit")
		{
			bzero(sending_message,256); // clearing string
//			for (int i = 0; i < input.size(); i++)
//				sending_message[i] = input[i];

			scanf("%s", sending_message);
			n = write(sockfd,sending_message,strlen(sending_message));
			printf("after write\n");
			if (n < 0)
			{
//				throw ConnectionError("Error in writing message");
			}
			bzero(sending_message,256);
//			n = read(sockfd, sending_message, 255);
			if (n < 0)
			{
//				throw ConnectionError("Error in reading server message");
			}

//			printf("message:%s\n",sending_message);

//			ss >> command;
			printf("end of while\n");
		}
		close(sockfd);
//		cerr << "command :( :" << command << endl;;
		if (command == "exit")
			return 0;
	}
	if (command == "exit")
//	else if (command == "exit")
		return 0;
//	else if (!connected)
	{
//		throw InvalidCommand("You must connect to server to continue");
	}

}

