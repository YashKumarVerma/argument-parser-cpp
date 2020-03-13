/**
 *@author: YashKumarVerma
 *@desc: Enter point of application
 **/

#include<iostream>
#include"./../includes/parser/parser.h"
#include"./../includes/rainbow/rainbow.h"

using namespace std;

int main(int argc, char* argv[]){
	Parser parser(argc, argv);

	if(parser.has("username")){
		cout << "Welcome user : " << parser.val("username") << endl;
	}

	if(parser.has("password")){
		cout << "Your password is : " << parser.val("password") << endl;
	}

	// dump all data
	// parser.dump();
	// parser.dumpProcessed();
	
	return 0;
}