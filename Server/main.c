
#include <unistd.h>
#include <sys/socket.h>

#include <string.h>

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF_SIZE 256
#define MAX_USERS 5

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		return -1;
	}

	int portno = atoi(argv[0]);
	char data_dir[30];
	strcpy(data_dir, argv[1]);

	int sockfd;
	socklen_t clilen;
	struct sockaddr_in serv_addr, cli_addr;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		return -1;
	}
	listen(sockfd, MAX_USERS);
	clilen = sizeof(cli_addr);

	int n;
	char buffer[BUFF_SIZE];
	int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0)
		return;
//	cerr << "accepted " << endl;
	while(1)
	{
		bzero(buffer,BUFF_SIZE);
		n = read(newsockfd,buffer,BUFF_SIZE - 1);
		if (n < 0)
		{
			//error in reding;
		}
//		string request = (string) buffer;
//		cerr << "readed : |" << request << "|" << endl;
		if (buffer == "")
		{
			close(newsockfd);
			break;
		}
//		string result = manager->run(request, i);
		char result[50];
		int result_size;

		if(result == "")
		{
//			result = "[Done]";
		}
		n = write(newsockfd,result, result_size);
	}

	close(sockfd);
}
