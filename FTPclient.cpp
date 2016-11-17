/*
 * Phillip Ryan
 *
 * FTPclient.cpp
 *
 */

#include "FTPclient.h"

//Helper functions which tokenize a string and return as a vector
std::vector<string> tokener(string line, char token){
	replace(line.begin(), line.end(), token, ' ');
	istringstream buf(line);
	istream_iterator<string> beg(buf),end;

	return vector<string>(beg,end);
}

int FTPclient::USER(string username){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "USER ";
	command += username;
	command += "\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending USER command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving USER reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from USER reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::PASS(string password){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "PASS ";
	command += password;
	command += "\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending PASS command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//received response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving PASS reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from PASS reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::CWD(string pathname){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "CWD ";
	command += pathname;
	command += "\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending CWD command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving CWD reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from CWD reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::CDUP(){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "CDUP\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending CDUP command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving CDUP reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from CDUP reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::QUIT(){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "QUIT\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending QUIT command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving QUIT reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from QUIT reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::PWD(){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "PWD\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending PWD command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving PWD reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from PWD reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::LIST(string pathname){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "LIST ";
	command += pathname;
	command += "\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending LIST command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving LIST reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from LIST reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::HELP(string help){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "HELP ";
	command += help;
	command += "\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending HELP command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving HELP reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from HELP reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	return retVal;
}


int FTPclient::PASV(){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "PASV\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending PASV command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving PASV reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from PASV reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	//Check if positive reply
	vector<string> reply = tokener(data, ' ');
	if( reply.at(0).compare("227") == 0){
		//Read response from server and parse the response for ip and port
		int i = data.find("(");
		int j = data.find(")");
		string dataInfo = data.substr(i+1, ((j-1)-i)); //returns every inside ()
		vector<string> hostPort = tokener(dataInfo, ',');
		string host;
		host = hostPort.at(0);
		host += ".";
		host += hostPort.at(1);
		host += ".";
		host += hostPort.at(2);
		host += ".";
		host += hostPort.at(3);
		string p1 = hostPort.at(4);
		string p2 = hostPort.at(5);
		int port = (stoi(p1)*256) + stoi(p2);

		//Attempt to connect to the FTP server
		retVal = dataSock.openConnect(host, to_string(port));
		if( retVal != 0 ){
			tmp = "Error when connecting to FTP data port: ";
			tmp += strerror(retVal);
			log->output(tmp, 3);
			return retVal;
		}
		else{
			log->output("Data port connected to FTP server", 3);
		}
	}
	else{
		retVal = errno;
		tmp = "Error when sending PASV: ";
		tmp += strerror(retVal);
		log->output(tmp, 3);
	}

	return retVal;
}

//Used for retreiving files
int FTPclient::EPSV(string ipType){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "EPSV ";
	command += ipType;
	command += "\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending EPSV command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//Retrieve response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving EPSV reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from EPSV reply: ";
		tmp += data;
		log->output(tmp, 3);
	}

	//Check if positive reply
	vector<string> reply = tokener(data, ' ');
	if( reply.at(0).compare("229") == 0){
		//Read response from server and parse the response for ip and port
		int i = data.find("(");
		int j = data.find(")");
		string dataInfo = data.substr(i+1, ((j-1)-i)); //returns every inside ()
		vector<string> hostPort = tokener(dataInfo, '|');
		string port = hostPort.at(0);
		cout << "PORT " << port << endl;
		string host = control.ipAddress;

		//Attempt to connect to the FTP server
		retVal = dataSock.openConnect(host, port);
		if( retVal != 0 ){
			tmp = "Error when connecting to FTP data port: ";
			tmp += strerror(retVal);
			log->output(tmp, 3);
			return retVal;
		}
		else{
			log->output("Data port connected to FTP server", 3);
		}
	}
	else{
		retVal = errno;
		tmp = "Error when sending PASV: ";
		tmp += strerror(retVal);
		log->output(tmp, 3);
	}

	return retVal;
}

int FTPclient::EPRT(string ipType, string host, string port){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//open listen data socket
	retVal = dataSock.openListen(port);
	if( retVal != 0 ){
		tmp = "Error when opening port: ";
		tmp += strerror(retVal);
		log->output(tmp, 3);
		return retVal;
	}

	//build command
	string command = "EPRT |";
	command += ipType;
	command += "|";
	command += host;
	command += "|";
	command += port;
	command += "|\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending EPRT command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving EPRT reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from EPRT reply: ";
		tmp += data;
		log->output(tmp, 3);
		//Check if positive reply
		vector<string> reply = tokener(data, ' ');
		if( reply.at(0).compare("200") == 0){
			tmp = "Connected to data port";
			log->output(tmp, 3);
		}
	}

	return retVal;
}

int FTPclient::PORT(string host, string port){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//open listen data socket
	retVal = dataSock.openListen(port);
	if( retVal != 0 ){
		tmp = "Error when opening port: ";
		tmp += strerror(retVal);
		log->output(tmp, 3);
		return retVal;
	}
	else{
		//Your server is listening for FTP clients
		tmp = "Your client is listening for FTP on ";
		tmp += port;
		log->output(tmp, 3);
	}

	//build command
	string command = "PORT ";
	replace( host.begin(), host.end(), '.', ',');
	command += "(";
	command += host;
	command += ",";
	int p16 = stoi(port);
	int p1 = p16 / 256;
	int p2 = p16 % 256;
	command += to_string(p1);
	command += ",";
	command += to_string(p2);
	command += ")\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending PORT command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	int clientSock = dataSock.acceptListen();

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving PORT reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from PORT reply: ";
		tmp += data;
		log->output(tmp, 3);
		//Check if positive reply
		vector<string> reply = tokener(data, ' ');
		if( reply.at(0).compare("200") == 0){
			tmp = "Connected to data port";
			log->output(tmp, 3);
		}
	}

	return retVal;
}

int FTPclient::RETR(string pathname){
	int retVal = 0;
	string tmp;

	log = Log::getInstance(); //Get Singelton

	//build command
	string command = "RETR ";
	command += pathname;
	command += "\r\n";

	//send command
	retVal = control.Send(command);
	if( retVal != 0 ){
		tmp = "Error when sending RETR command: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}

	//receive response
	string data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving RETR reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from RETR reply: ";
		tmp += data;
		log->output(tmp, 3);
		//Check if positive reply
		vector<string> reply = tokener(data, ' ');
		if( reply.at(0).compare("150") == 0){
			tmp = "Transfer will begin now";
			log->output(tmp, 3);
		}
		else{
			retVal = -1;
			return -1;
		}
	}

	//receive file on data sock
	string file = dataSock.Recv(5000);
	if( file.empty() ){
		tmp = "Error when receiving file reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from file reply: ";
		tmp += file;
		log->output(tmp, 3);
	}

	//get message of full receive sent
	data = control.Recv(1048);
	if( data.empty() ){
		tmp = "Error when receiving RETR reply: ";
		tmp += strerror(errno);
		log->output(tmp, 3);
	}
	else{
		tmp = "Received from RETR reply: ";
		tmp += data;
		log->output(tmp, 3);
		//Check if positive reply
		vector<string> reply = tokener(data, ' ');
		if( reply.at(0).compare("226") == 0){
			tmp = "File transfer complete ";
			tmp += data;
			log->output(tmp, 3);

			retVal = this->createFile(pathname, file);
			if( retVal == 0){
				tmp = "File created ";
				log->output(tmp, 3);
			}
			else if( retVal == -1){
				tmp = "File was not created because it already exists";
				log->output(tmp, 3);
			}
			else{
				tmp = "Failed to create file ";
				tmp += strerror(retVal);
				log->output(tmp, 3);
			}
		}
		else
			retVal = errno;
	}

	return retVal;
}

int FTPclient::createFile(string filename, string data){
	int retVal = 0;
	string response  = "Y";

	if(ifstream(filename)){
		cout << "File already exists, would you like to overwrite?(Y or N)" << endl;
		getline(cin, response);

		//Take the response value and make it upper case
		for(int i=0; i<response.length(); i++){
			response[i] = toupper(response[i]);
		}
	}

	if( response.compare("Y") == 0 ){
		ofstream outputFile;
		outputFile.open(filename);

		outputFile << data << endl;
	}
	else
		retVal = -1;

	return retVal;
}
