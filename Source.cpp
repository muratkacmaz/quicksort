
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <ctime>
#include "Header.h"

using namespace std;

int main(int argc, char *argv[]) {
	vector<USP> usPop;
	USPManager uspm;
	int valueN = 0;  
	int N = atoi(argv[1]);
	string p, mi, ma, g, z, gID;
	int po, mini, maxi, zipp;
	
	ifstream fileRead;
	fileRead.open("population_by_zip_2010.csv");
	string lineRead;
	getline(fileRead, lineRead);	
	while (getline(fileRead, lineRead) && N>valueN)
	{
		istringstream iss(lineRead);
		getline(iss, p, ',');
		getline(iss, mi, ',');
		getline(iss, ma, ',');
		getline(iss, g, ',');
		getline(iss, z, ',');
		getline(iss, gID, '\n');
		
		po = atoi(p.c_str());
		mini = atoi(mi.c_str());
		maxi = atoi(ma.c_str());
		zipp = atoi(z.c_str());

		valueN++;

		USP  newData (po, mini, maxi, g, zipp, gID);
		usPop.push_back(newData); 

	}

	clock_t begin = clock();
	uspm.quickSort(usPop, 0, N - 1);
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time elapsed : " << elapsed_secs << endl;

	uspm.WriteToFile(usPop);
	
	return 0;
}



