/*
 * Phillip Ryan
 * CS 472
 * Homework 2 - FTP Client
 *
 * main.cpp
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

#include "FTPclient.h"
#include "log.h"

using namespace std;

//Helper functions which tokenize a string and return as a vector
std::vector<string> tokenize(string line){
	istringstream buf(line);
	istream_iterator<string> beg(buf),end;

	return vector<string>(beg,end);
}

int main(int argc, char** argv ){
	int retVal = 0;
	string logFile, hostname, port, line, tmp;

	//Parse commandline options
	if( argc < 3 ){
		//If ipaddress and log file name are not present
		cout << "Error, program requires at least 3 inputs" << endl;
		return 0;
	}
	else{
		//Store hostname
		hostname = argv[1];

		//Store log file name
		logFile = argv[2];

		//Store port if it exists, else port is 21
		if( argc > 3 ){
			port = argv[3];
		}
		else
			port = "21";
	}

	//Setup log file for output
	Log* log = Log::getInstance(); //Get Singelton
	log->setLog(logFile); //See Log class for details
	string outPut = "input: " + hostname + " " + logFile + " " + port;
	log->output(outPut, 3);

	//Attempt to connect to the FTP server
	FTPclient client;
	retVal = client.control.openConnect(hostname, port);
	if( retVal != 0 ){
		tmp = "Error when connecting to FTP server: ";
		tmp += strerror(retVal);
		log->output(tmp, 3);
		return retVal;
	}
	else{
		string data = client.control.Recv(2046);
		if( data.empty() ){
			tmp = "Error when receiving reply: ";
			tmp += strerror(errno);
			log->output(tmp, 3);
		}
		else{
			tmp = "Received reply: ";
			tmp += data;
			log->output(tmp, 3);
			log->output("Connected to FTP server", 3);
		}
	}

	//Ask for username and password from user
	string username, password;

	cout << "Please enter your username: ";
	getline(cin,username);
	cout << "Please enter your password: ";
	getline(cin,password);

	client.USER(username);
	client.PASS(password);

	//Run while loop which asks the user for commands, until QUIT
	while((cout << "ftp>") && (getline(cin, line))){
		//tokenize the string by spaces
		vector<string> input = tokenize(line);

		//Store first value of entered command as command name
		string command = input.front();

		//Store rest of command if neccesary
		string a1, a2, a3;
		try{
			a1 = input.at(1);
			a2 = input.at(2);
			a3 = input.at(3);
		}
		catch(std::out_of_range& err){}

		//Take the command value and make it upper case
		for(int i=0; i<command.length(); i++){
			command[i] = toupper(command[i]);
		}

		//Determine what command was entered and call appropriate function
		if(command.compare("QUIT") == 0){
			log->output("Quitting ftp client", 3);
			break;
		}
		else if(command.compare("CWD") == 0){
			log->output("CWD command", 3);
			retVal = client.CWD(a1);
		}
		else if(command.compare("CDUP") == 0){
			log->output("CDUP command", 3);
			retVal = client.CDUP();
		}
		else if(command.compare("QUIT") == 0){
			log->output("QUIT command", 3);
			retVal = client.QUIT();
		}
		else if(command.compare("PASV") == 0){
			log->output("PASV command", 3);
			retVal = client.PASV();
		}
		else if(command.compare("EPSV") == 0){
			log->output("EPSV command", 3);
			retVal = client.EPSV(a1);
		}
		else if(command.compare("PORT") == 0){
			log->output("PORT command", 3);
			retVal = client.PORT(a1, a2);
		}
		else if(command.compare("EPRT") == 0){
			log->output("EPRT command", 3);
			retVal = client.EPRT(a1, a2, a3);
		}
		else if(command.compare("RETR") == 0){
			log->output("RETR command", 3);
			retVal = client.RETR(a1);
		}
		else if(command.compare("PWD") == 0){
			log->output("PWD command", 3);
			retVal = client.PWD();
		}
		else if(command.compare("LIST") == 0){
			log->output("LIST command", 3);
			retVal = client.LIST(a1);
		}
		else if(command.compare("HELP") == 0){
			log->output("HELP command", 3);
			retVal = client.HELP(a1);
		}
		else{
			//If command is not recognized then report error and ask
			log->output("Error command not recognized", 3);
		}
	}

	//cleanup
	client.control.closeSocket();

	return retVal;
}
