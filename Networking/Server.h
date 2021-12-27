/*
 The Server struct is used as the basis for nodes that need to operate as servers.
 Generically, the server connects to the network and listens on a given port.
 */

#ifndef Server_h
#define Server_h

#include "../../DataStructures/Dictionary/Dictionary.h"

#include <sys/socket.h>
#include <netinet/in.h>

// MARK: DATA TYPES

struct Server
{
    /* PUBLIC MEMBER VARIABLES */
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;

    int socket;
    
    void (*launch)(struct Server *server);
    
};

// MARK: CONSTRUCTORS
struct Server server_constructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(struct Server *server));

#endif /* Server_h */
