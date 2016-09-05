#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <tuple>
using namespace std;


/*
int main () {
  string line;
  string accumulate = "";
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      accumulate = line + accumulate + "\n";
    }
    cout << accumulate;
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}*/

tuple<int,char> getInfo(string s)
{
	int num = stoi(s);
	string value = s.substr(s.find(" ") + 1);
	
	char result = value.at(1);
	
	return make_tuple(num,result);
}


int main (int argc, const char * argv[]) {
	
    int minutes = 0;
    int hours = 0;
    int days = 0;
    
    
	string line;
	ifstream myfile (argv[1]);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			if(line.at(0) != '#')
			{
				stringstream ss(line);
				string current;
				
				while(std::getline(ss, current, ' ')) {
					std::cout << current << '\n';
				}

			}
		}
		myfile.close();
	}
    
    cout << "Minutes: " << minutes << endl;
    cout << "Hours: " << hours << endl;
    cout << "Days: " << days << endl;
}
