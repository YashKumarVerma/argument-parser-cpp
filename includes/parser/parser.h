#ifndef PARSER
#define PARSER

#include<string>
#include<vector>

using namespace std;

class Parser{
	private:
		// store all parameters in vector instead 
		vector<string> data;
		
		// store the number of arguments
		int argc;

		// store the name of the file
		string fileName;

    public:
		Parser(int, char*[]);

		// function for debug
		void dump();
};

#endif
