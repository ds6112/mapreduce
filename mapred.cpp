#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
void printError()
{
	std::cout<<"Format : mapred -a [wordcount, sort] -i [procs, threads]" 
	" -m num_maps -r num_reduces infile outfile"<<std::endl;
	exit(0);
}
bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
std::vector<std::string> parseArgs(int argc,char **argv)
{
	// Check total args
	if(argc!=11)
	{
		printError();
	}
	// Check flag format
	static const std::string flags[] = {"-a","-i","-m","-r"};
	std::vector<std::string> format(flags,flags+sizeof(flags)/sizeof(flags[0]));
	for(int i=1,j=0;i<9;i+=2,j++)
	{
		if(argv[i]!=format[j])
		{
			printError();
		}
	}
	// Check individual args
	std::string a = argv[2];
	std::string i= argv[4];
	std::string m = argv[6];
	std::string r= argv[8];
	std::string input = argv[9];
	std::string output = argv[10];
	if(a!="wordcount" && a!="sort")
	{
		printError();
	}
	else if(i!="procs" && i!="threads")
	{
		printError();
	}
	else if(!isNumber(m) || !isNumber(r))
	{
		printError();
	}
	std::vector<std::string> args;
	args.push_back(a);
	args.push_back(i);
	args.push_back(m);
	args.push_back(r);
	args.push_back(input);
	args.push_back(output);
	return args;
};
int main(int argc,char **argv)
{	
	std::vector<std::string> args = parseArgs(argc,argv);
	for( std::vector<std::string>::const_iterator i = args.begin(); i != args.end(); ++i)
		std::cout << *i << std::endl;
	return 0;
}
