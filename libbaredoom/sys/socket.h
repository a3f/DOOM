#ifndef __SYS_SOCKET_H_
#define __SYS_SOCKET_H_

int recvfrom();
void *gethostbyname();
int gethostname();
unsigned inet_addr();
int bind();
int sendto();
int socket();

#define AF_INET 2
#define PF_INET AF_INET

#define INADDR_ANY 0

#define SOCK_DGRAM 1

#endif
