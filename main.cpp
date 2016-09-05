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

bool compare(string s, string m)
{
	return s.compare(m) == 0 || s.compare(m + "s") == 0;
}

int which(string s)
{
	if(compare(s,"minute"))
	{
		return 0;
	}
	
	if(compare(s,"hour"))
	{
		return 1;
	}
	
	if(compare(s,"day"))
	{
		return 2;
	}
	
	return -1;
}

bool isInt(string s)
{
	for(int i = 0; i < s.length(); i++)
	{
		char c = s.at(i);
		if(c <  48 || c > 57)
		{
			return false;
		}
	}
	
	return true;
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
				
				while(std::getline(ss, current, ' ')) 
				{
					if(isInt(current))
					{
						int num = stoi(current);
						std::getline(ss, current, ' ');
						
						switch(which(current))
						{
							case 0:	minutes += num;
									break;
							case 1:	hours += num;
									break;
							case 2:	days += num;
									break;
						}
						
						cout << current << endl;
					}
				}

			}
		}
		myfile.close();
	}
    
    cout << "Minutes: " << minutes << endl;
    cout << "Hours: " << hours << endl;
    cout << "Days: " << days << endl;
}
