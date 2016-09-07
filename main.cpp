#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

string removeNonAlpha(string s)
{
	string accumulate = "";
	
	for(int i = 0; i < s.length(); i++)
	{
		char c = s.at(i);
		
		if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		{
			accumulate += c;
		}
	}
	
	return accumulate;
}

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

string isInt(string s)
{
	int i = 0;
	
	while(s.at(i) <  48 || s.at(i) > 57)
	{
		i++;
		if(i >= s.length())
		{
			return "";
		}
	}
	
	string accumulate = "";
	
	for(; i < s.length(); i++)
	{
		char c = s.at(i);
		if(c <  48 || c > 57)
		{
			return "";
		}
		accumulate += c;
	}
	
	return accumulate;
}

int main (int argc, const char * argv[]) {
	
    int minutes = 0;
    int hours = 0;
    int days = 0;
    /*
    string input = argv[1];
    input = input.substr(6);
    */
    
    string input = "input.txt";
    
	string line;
	ifstream myfile (input);
	
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
					string numberextract = isInt(current);
					if(numberextract.compare("") != 0)
					{
						int num = stoi(numberextract);
						std::getline(ss, current, ' ');
						
						string removed = removeNonAlpha(current);
						
						// cout << num << " " << removed << endl;
						
						switch(which(removed))
						{
							case 0:	minutes += num;
									break;
							case 1:	hours += num;
									break;
							case 2:	days += num;
									break;
						}
					}
				}

			}
		}
		myfile.close();
	}
    
    cout << "Minutes:" << minutes << endl;
    cout << "Hours:" << hours << endl;
    cout << "Days:" << days << endl;
}
