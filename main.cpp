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
	string line;
	string s = "";
	ifstream myfile (argv[1]);
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			s = s + line + "\n";
		}
		myfile.close();
	}
 
	std::regex no_comments("#.*?\n");
    auto lines_begin = 
        std::sregex_iterator(s.begin(), s.end(), no_comments);
    auto lines_end = std::sregex_iterator();
    
    string remove_comments = regex_replace(s, no_comments, "");
 
    std::regex word_regex("([0-9]*)\\ ([Mm]inute(s|\\ )|[Hh]our(s|\\ )|[Dd]ay(s|\\ ))");
    auto words_begin = 
        std::sregex_iterator(remove_comments.begin(), remove_comments.end(), word_regex);
    auto words_end = std::sregex_iterator();
    int minutes = 0;
    int hours = 0;
    int days = 0;
    
    int quantity;
    char value;
    
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();
        std::tie (quantity, value) = getInfo(match_str);
        
        switch(value)
        {
			case 'a': days += quantity;
						break;
			case 'i': minutes += quantity;
						break;
			case 'o': hours += quantity;
						break;
		}
    }
		
    
    cout << "Minutes: " << minutes << endl;
    cout << "Hours: " << hours << endl;
    cout << "Days: " << days << endl;
}
