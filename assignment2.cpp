#include <iostream>
#include <fstream>
#include <string>
#include <list>


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

list<string> eClosure(string node, string arr[][3])
{
    list<string> connections;
    
}

int main () 
{
    ifstream inputFile; 
    inputFile.open("input.txt");
    string line;   
	int lineCount=0;
    list<string> lineList;

    if(inputFile.is_open()) 
	{
		while(inputFile.peek()!=EOF)
		{
			getline(inputFile, line);
			lineCount++;
            lineList.push_back(line);
		}
	}

    string arr[lineCount][3];

    int listSize = lineList.size();
    for(int i = 0; i < listSize;i++)
    {
        addLink(lineList.front(),i,arr);
        lineList.pop_front();
    }

    for(int i=0;i<lineCount;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"\t"<<arr[i][j];
		}
		cout<<endl;
	}

    return 0;
}