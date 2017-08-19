#ifndef __NETINET_IN_H
#define __NETINET_IN_H

#define IPPORT_USERRESERVED 5000

#define IPPROTO_UDP 17

struct sockaddr_in {
    int sin_family;
    union {
        int s_addr;
    } sin_addr;
    int sin_port;
};

#endif
