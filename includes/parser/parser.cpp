#include<iostream>
#include"parser.h"

using namespace std;

/**
 * @param: string handle, string value
 * @desc: to store data in form of handle and value
 */
Data::Data(string handle, string value){
	this->handle = handle;
	this->value = value;
}

// Data::Data(Data &ref){
// 	this->handle = ref.handle;
// 	this->value = ref.value;
// }

/**
 * @param: none
 * @desc: function to return values
 */
Data Data::get(){
	return Data(this->handle, this->value);
}

/**
 * @param: none
 * @desc: function to display the data items
 */
void Data::display(Data obj){
	cout << obj.handle << ":" << obj.value << endl;
}

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

	if(!this->validParamType()){
		cout << "Invalid Parameter Syntax" << endl;
		exit(1);
	}
}

/**
 * @param: none
 * @desc: function to check if valid syntax called
 */
bool Parser::validParamType(){
	// 0th index is insignificant

	// start checking from 1th index
	if(this->argc == 1){
		return true;
	}

	// check if all parameters start with double dash
	for(int i=1; i< this->argc; i++){
		if((this->data[i][0] != '-') || (this->data[i][1] != '-') ){
			return false;
		}
	}

	// now split the data from =
	for(int i=1; i < this->argc; i++){
		int equalToLocation = -1;
		for(int j=0; j< (this->data[i].length()); j++ ){
			if(this->data[i][j] == '='){
				equalToLocation = j;
				break;
			}
		}

		// if equal to does not exist in 
		if(equalToLocation == -1){
			return false;
		}

		Data temp(
			this->data[i].substr(2, equalToLocation-2),
			this->data[i].substr(equalToLocation+1, this->data[i].length())
		);

		this->processedData.push_back(temp);
	}
	return true;
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

/**
 * @param: none
 * @desc: function to dump all processed parameters stored
 */
void Parser::dumpProcessed(){
	for(int i=0; i< this->processedData.size(); i++){
		Data::display( this->processedData[i] );
	}

}

/**
 * @param: none
 * @desc: function to load data from string to array
 */
bool Parser::loadData(){
	return true;
}