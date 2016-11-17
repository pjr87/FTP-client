/*
 * Phillip Ryan
 *
 * log.cpp
 *
 */

#include "log.h"

Log* Log::instance = NULL;
bool Log::instanceFlag = false;
Log *Log::getInstance(){
	if( !instanceFlag ){
		instance = new Log();
		instanceFlag = true;
		return instance;
	}
	else
		return instance;
}

//Sets the file which will hold the output log
void Log::setLog(string file){
	logFile = file;

	outFile.open(logFile, ios_base::app);
}

//takes string and outputs
//option - determines where output is sent
//	1 - only logfile
//	2 - only screen
//	3 - both logfile and screen
void Log::output(string text, int option){
	char date[80];
	time_t t = time(0);
	struct tm tstruct = *localtime(&t);
	strftime(date, sizeof(date), "%Y-%m-%d.%X", &tstruct);

	switch(option){
	case 1:
		outFile << date << " " << text << endl;
		break;
	case 2:
		cout << text << endl;
		break;
	case 3:
		outFile << date << " " << text << endl;
		cout << text << endl;
		break;
	default:
		break;
	}
}

//close logging
int Log::close(){
	int retVal = 0;

	outFile.close();

	return retVal;
}
