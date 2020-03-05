#include<iostream>
#include"parser.h"

using namespace std;

/**
 *@param: int argc, char *argv
 */
Parser::Parser(int argc, char* argv[]){

	// store the number of params into class
	this->argc = argc;

	// populate storage vector with all parameters
	for(int i=0; i<argc; i++){
		this->data.push_back(argv[i]);
	}

	// save the file for future referene
	this->fileName = data[0];
}

/**
 * @param: none
 * @desc: function to dump all parameters stored
 */
void Parser::dump(){
	cout << "Total Parameters : " << this->argc << endl;
	
	for(int i=0; i<this->argc; i++){
		cout << this->data[i] << endl;
	}
}
