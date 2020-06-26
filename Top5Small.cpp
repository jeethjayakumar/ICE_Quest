/*
 * DriverCode.cpp
 *
 *  Created on: Jun 25, 2020
 *      Author: jeethjayakumar
 */

#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout<<"Expecting argument\n";
		cout<<"Format: ./Top5Small <float number>\n";
		return 0;
	}

	// Reading number from stdin
	double inp = atof(argv[1]);

	// Opening the Input file with Number List
	fstream inpfid;
	inpfid.open("InputNumList.txt", ios::in|ios::out|ios::app);

	// Updating the file
	inpfid << inp << endl;

	//Read all the data from the file and copy it into temporary datastructure
	double temp;
	multiset <double> temp_data;
	inpfid.seekg(0, ios::beg);
	while(inpfid >> temp)
		temp_data.insert(temp);

	int len = temp_data.size();
	cout<<"Structure Length: "<<len<<endl; // TESTING - TO BE REMOVED

	int top5len = len * 0.95;
	cout<<"top5len = "<<top5len<<endl; // TESTING - TO BE REMOVED

	temp = *next(temp_data.begin(), top5len - 1); // Indexing starts from 0
	cout<<"Smallest value which is 95% larger than numbers till now: "<<temp<<endl;
	
	//Closing the file after program execution
	temp_data.clear();
	inpfid.close();
}
