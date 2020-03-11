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

	// dump all data
	parser.dump();
	parser.dumpProcessed();
	
	return 0;
}