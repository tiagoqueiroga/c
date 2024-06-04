#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <poll.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool is_command(char *buffer)
{
    return buffer[0] == '!';
}

char * str_normalize(char *string)
{
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }

    return string;
}

void handle_command(char *buffer){

    char *command = str_normalize(buffer);

    if(strcmp(buffer,"!help\n") == 0){
        printf("print help\n");
    }

    else{
        printf("invalid command\n");
    }

}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address = {
        AF_INET,
        htons(9999),
        0
    };

    bind(sockfd, &address, sizeof(address));

    listen(sockfd, 10);

    int clientfd = accept(sockfd, 0, 0);

    // stdin - 0
    struct pollfd fds[2] = {
        {
            0,
            POLLIN,
            0
        },
        {
            clientfd,
            POLLIN,
            0
        }
    };

    for (;;) {
        char buffer[256] = { 0 };

        poll(fds, 2, 50000);

        if (fds[0].revents & POLLIN) {
            read(0, buffer, 255);
            send(clientfd, buffer, 255, 0);
        } else if (fds[1].revents & POLLIN) {
            if (recv(clientfd, buffer, 255, 0) == 0) {
                return 0;
            }
            
            if(is_command(buffer))
            {
                handle_command(buffer);
            }else{
                printf("%s\n", buffer);
            }

        }
    }

    return 0;
}