#include <stdio.h>
#include <iostream>
#include <string>
#include<algorithm>
#include<regex>
#include<stack>
using namespace std;
std::stack <int> cmd_history;
string s1, s2, temp;
void string_add()
{
	printf("input the first string\n");
	getline(cin, s1);
	printf("input the second string to add\n");
	getline(cin, s2);
	cout << s1 + s2 << endl;
}

void pattern()
{

	printf("input the string\n");
	getline(cin, s1);
	printf("input the pattern\n");
	getline(cin, s2);
	char find = s1.find(s2);
	if (find != std::string::npos)
	{
		cout << "\npattern found";
	}
	else
	{
		cout << "\nPattern Not Found";
	}
}

void reverse()
{

	printf("input the string to reverse\n");
	getline(cin, s1);
	temp = s1;
	std::reverse(s1.begin(), s1.end());
	cout << s1;
}
void rmv_blank()
{

	printf("input the string to remove blank spaces\n");
	getline(cin, s1);
	temp = s1;
	s1.erase(remove_if(s1.begin(), s1.end(), isspace), s1.end());
	cout << s1;
}

void vowels_replace()
{
	int i, j = 0;
	char k;
	printf("\ninput the string \n");
	getline(cin, s1);
	temp = s1;
	string s2 = ("aeiouAEIOU");
	for (i = 0; i < s1.size(); i++)
	{
		
		k = s2.find(s1[i]);
		
		if (k != std::string::npos)
		{
			
			s1.erase(remove(s1.begin(), s1.end(), s1[i]), s1.end());
			i = -1;
		}	
		
	}
	cout << "\nstring without vowels is " << s1;
}

void num_count()
{
	int i, j = 0;
	char k;
	printf("\ninput the string to count the number of digits\n");
	getline(cin, s1);
	string s2 = ("0123456789");
	for (i = 0; i < s1.size(); i++)
	{
		k = s2.find(s1[i]);
		if (k != std::string::npos)
		{
			j = j + 1;
		}
	}
	cout << "\nnumber of digits in a string is " << j;
}




int main()
{
	int usr_cmd,redo_cmd;
	printf("\nList of operations \n\n 1 add string \n 2 find pattern in string\n 3 reverse string\n 4 remove blank from string\n 5 find number of digits in string\n 6 remove vowels from string\n 7 undo - should undo the last command\n 8 redo - should repeat the last command\n 9 number - find number of commands\n 10 last - what was last command used\n 11 nlast - what was nth last command used\n");
	while(true)
	{
		printf("\nEnter your choice(1-11) OR press 0 to exit \n");
		cin >> usr_cmd;
		cin.ignore();
		cmd_history.push(usr_cmd);
		
	redo:switch (usr_cmd)
		{
		
		case 1:  string_add();
			     continue; 
		case 2: pattern();
			     continue;
		case 3: reverse();
				continue;
		case 4: rmv_blank();
				continue;
		case 5: num_count();
				continue;
		case 6: vowels_replace();
				continue;
		case 7: 	cout << "\nUndo sucessfull" << endl;
				if (count % 2 == 0)
				{
					cout << "\nundo string is " << temp << endl;
				}
				else
				{
					cout << "\nundo string is " << s1 << endl;
				}
				count = count + 1;
				continue;
		case 8: cmd_history.pop();
				redo_cmd = usr_cmd;
				usr_cmd = cmd_history.top();
				cmd_history.push(redo_cmd);
				
				goto redo;
				continue;
		case 9: cout << "\ntotal number of commands is " << cmd_history.size()<< endl;
				continue;
		case 10:	cmd_history.pop();
					cout << "last command used is " << cmd_history.top();
					cmd_history.push(usr_cmd);
					continue;
		case 11 : cout << "\n nth last command used is " << cmd_history.top();
				continue;
		case 0: exit(0);
		}
	}
	getchar();
	return 0;
}
