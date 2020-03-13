#include<iostream>
#include"parser.h"

using namespace std;


/**
 * @param: none
 * @desc: to store data in form of handle and value
 */
Data::Data(){
	this->handle = "";
	this->value = "";
}

/**
 * @param: string handle, string value
 * @desc: to store data in form of handle and value
 */
Data::Data(string handle, string value){
	this->handle = handle;
	this->value = value;
}

/**
 * @param: another object refernece
 * @desc: to store data in form of handle and value
 */
Data::Data(const Data &ref){
	this->handle = ref.handle;
	this->value = ref.value;
}

/**
 * @param: none
 * @desc: getter for handle and value data
 */
string Data::getHandle(){
	return this->handle;
}

string Data::getValue(){
	return this->value;
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

	if(!this->checkFormatAndLoad()){
		cout << "Invalid Parameter Syntax" << endl;
		
		exit(1);
	}
}

/**
 * @param: none
 * @desc: function to check if valid syntax called
 */
bool Parser::checkFormatAndLoad(){
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

		// to handle --user= as invalid
		if(equalToLocation == this->data[i].length()-1){
			return false;
		}

		// if equal to does not exist in 
		if(equalToLocation == -1){
			return false;
		}

		// create an object to store data into defined class
		Data temp(
			this->data[i].substr(2, equalToLocation-2),
			this->data[i].substr(equalToLocation+1, this->data[i].length())
		);

		// add data to processed data vector
		this->processedData.push_back(temp);
	}
	return true;
}

/**
 * @param: none
 * @desc: function to dump all parameters stored
 * @debug: true
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
 * @debug: true
 */
void Parser::dumpProcessed(){
	for(int i=0; i< this->processedData.size(); i++){
		Data::display( this->processedData[i] );
	}

}

/**
 * @param: name of handle(string)
 * @desc: function to check if given handle data was in the array
 */
bool Parser::has(string handle){
	Data temp;
	for(int i=0; i<this->processedData.size(); i++){
		temp = this->processedData[i];
		if(temp.getHandle() == handle){
			return true;
		}
	}
	return false;
} 

/**
 * @param: name of handle(string)
 * @desc: this function returns the value of particular handle and empty string if value not exists
 */
string Parser::val(string handle){
	Data temp;
	for(int i=0; i<this->processedData.size(); i++){
		temp = this->processedData[i];

		// if handle found, return actual data
		if(temp.getHandle() == handle){
			return temp.getValue();
		// else return a blank string
		}
	}
	return string("");
}