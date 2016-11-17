/*
 * Phillip Ryan
 *
 * log.h
 *
 */

#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

class Log
{
public:
	//Singleton helpers
	static Log *getInstance();

	~Log(){
		instanceFlag = false;
	}

	//Sets the file which will hold the output log
	void setLog(string file);

	//takes string and outputs
	//option - determines where output is sent
	//	1 - only logfile
	//	2 - only screen
	//	3 - both logfile and screen
	void output(string text, int option);

	//close logging
	int close();

private:
	//Singleton helpers
	Log(){}; //Private constructor
	static Log *instance;
	static bool instanceFlag;

	string logFile;
	ofstream outFile;
};

#endif
