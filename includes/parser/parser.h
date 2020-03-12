#ifndef PARSER
#define PARSER

#include<string>
#include<exception>
#include<vector>

using namespace std;

class Data{
	private:
		string handle;
		string value;
	public:
		// constructors to create an object
		Data(string, string);

		// function to return data
		Data get();	

		// function to display data
		static void display(Data);
};

class Parser{
	private:
		// store all parameters in vector instead 
		vector<string> data;
		vector<Data> processedData;
		
		// store the number of arguments
		int argc;

		// store the name of the file
		string fileName;

		// function to check if valid arguments syntax passed
		bool checkFormatAndLoad();


    public:
		Parser(int, char*[]);

		// function for debugging purposes
		void dump();
		void dumpProcessed();
};

#endif
