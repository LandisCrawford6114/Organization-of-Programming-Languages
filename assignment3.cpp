#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

void addLink(string line, int lineNumber, string arr[][3])
{
    int first = line.find(',');
    int second = line.find(',',first+1);
    string from = line.substr(0,first);
    string to = line.substr(first+1,second-(first+1));
    string link = line.substr(second+1,line.size()-second);

    arr[lineNumber][0] = from;
    arr[lineNumber][1] = to;
    arr[lineNumber][2] = link;
}

void addTableLink(string line, int lineNumber, char arr[][7])
{
    arr[lineNumber][0] = line.at(0);
    arr[lineNumber][1] = line.at(2);
    arr[lineNumber][2] = line.at(4);
    arr[lineNumber][3] = line.at(6);
    arr[lineNumber][4] = line.at(8);
    arr[lineNumber][5] = line.at(10);
    arr[lineNumber][6] = line.at(12);
}

void parse(string input, string rules[][3], char table[][7], int tableLineCount, int rulesLineCount)
{
    list<char> inputs;
    for(int i = 0; i < input.size(); i++)
    {
        if(input.at(i) != ' ')
        {
            inputs.push_back(input.at(i));
        }
    }
    inputs.push_back('$');

    char c = inputs.front();
    inputs.pop_front();

    list<char> stack;
    stack.push_back('p');
    stack.push_back('$');
    char x;
    while(stack.size() != 0)
    {
        x = stack.front();
        list<char> print = stack;
        for(int i = 0; i < stack.size(); i++)
        {
            char printing = print.front();
            cout << printing;
            print.pop_front();
        }
        cout << "\n";
        print = inputs;
        cout << c;
        for(int i = 0; i <inputs.size(); i++)
        {
            char printing = print.front();
            cout << printing;
            print.pop_front();
        }
        cout << "\n";
        if(x == c)
        {
            stack.pop_front();
            if(inputs.size() != 0)
            {
                c = inputs.front();
                inputs.pop_front();
            }
            else
            {
                cout << "match $ \n";
                return;
            }
            cout << "match " << x;
            cout << "\n";
        }
        else
        {
            int column = 0;
            int row = 0;
            for(int i = 0; i < tableLineCount; i++)
            {
                if(x == table[i][0])
                {
                    row = i;
                }
                for(int j = 0; j < 7; j++)
                {
                    if(table[0][j] == c)
                    {
                        column = j;
                    }
                }
            }
            if(column != 0 && row != 0)
            {
                stack.pop_front();
                char ruleNumber = table[row][column];
                string str1(1, ruleNumber);
                for(int i = 0; i < rulesLineCount; i++)
                {
                    if(rules[i][0] == str1)
                    {
                        for(int j = rules[i][2].size()-1; j >= 0 ; j--)
                        {
                            if(rules[i][2] != "ε")
                            {
                                char adding = rules[i][2].at(j);
                                stack.push_front(adding);
                            }
                            
                        }
                    }
                }
                cout << "run rule " << ruleNumber;
                cout << "\n";
            }
        }
        cout << "\n";
    }
}

int main()
{
    ifstream inputFile; 
    inputFile.open("input2.txt");
    string line;   
	int rulesLineCount=0;
    list<string> lineList;

    if(inputFile.is_open()) 
	{
		while(inputFile.peek()!=EOF)
		{
			getline(inputFile, line);
			rulesLineCount++;
            lineList.push_back(line);
		}
	}

    string rules[rulesLineCount][3];

    int listSize = lineList.size();
    for(int i = 0; i < listSize;i++)
    {
        addLink(lineList.front(),i,rules);
        lineList.pop_front();
    }

    inputFile.close();
    inputFile.open("input3.txt");
    line = "";   
	int tableLineCount=0;

    if(inputFile.is_open()) 
	{
		while(inputFile.peek()!=EOF)
		{
			getline(inputFile, line);
			tableLineCount++;
            lineList.push_back(line);
		}
	}

    char table[tableLineCount][7];

    listSize = lineList.size();
    for(int i = 0; i < listSize;i++)
    {
        addTableLink(lineList.front(),i,table);
        lineList.pop_front();
    }

    cout << "Rules:\n";
    for(int i=0;i<rulesLineCount;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"\t"<<rules[i][j];
		}
		cout<<endl;
	}

    cout << "Table:\n";
    for(int i=0;i<tableLineCount;i++)
	{
		for(int j=0;j<7;j++)
		{
			cout<<"\t"<<table[i][j];
		}
		cout<<endl;
	}

    parse("i * i", rules, table, tableLineCount, rulesLineCount);
}