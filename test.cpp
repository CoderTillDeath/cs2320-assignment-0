#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string s = "  ";
	stringstream ss (s);
	
	string current;
	getline(ss, current, ' ');
	getline(ss, current, ' ');
	getline(ss, current, ' ');
	getline(ss, current, ' ');
}
