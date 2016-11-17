/*
 * Phillip Ryan
 *
 * Socket.h
 *
 */

#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include "log.h"

using namespace std;

class Socket
{
public:
	/*
	 * openConnect - open connection to server at <hostname, port>
	 * and return a socket descriptor ready for reading and writing
	 */
	int openConnect(string hostname, string port);

	/*
	 * openListen - open and return a listening socket on port
	 */
	int openListen(string port);

	/*
	 * Send - sends data on the specified socket, edits buffer to remove extra space
	 */
	int Send(string data);

	int acceptListen();

	/*
	 * Recv - calls the socket recv fucntion which reads a message sent from the server
	 * and will return the string received, edits buffer to remove extra space
	 *
	 */
	string Recv(int maxSize);

	/*
	 * closeSocket - closes a socket file descriptor
	 */
	void closeSocket();

	string ipAddress;

private:
	struct hostent *hp;
	struct sockaddr_in addr;
	int sock;
	Log* log;
};

#endif
