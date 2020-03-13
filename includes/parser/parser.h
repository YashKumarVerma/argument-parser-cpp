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
		Data();
		Data(string, string);
		Data(const Data &ref);

		string getHandle();
		string getValue();

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

		// function to check if given handle existed
		bool has(string);

		// function to return value of handle
		string val(string);

		// function for debugging purposes
		void dump();
		void dumpProcessed();
};

#endif
