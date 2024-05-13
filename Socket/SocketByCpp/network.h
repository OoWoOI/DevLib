/*************************************************************************
	> File Name: network.h
	> Author: 
	> Mail: 
	> Created Time: Mon 13 May 2024 07:08:10 PM CST
 ************************************************************************/

#ifndef _NETWORK_H
#define _NETWORK_H


class Socket {
    public :
        

    private :
        char *ip;
        int port;
        struct sockaddr_in svr_addr;
        struct sockaddr_in cln_addr;
};

#endif
