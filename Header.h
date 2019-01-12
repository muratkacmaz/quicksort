#include <iostream>
#include <stdlib.h>
#include <string>
#include <algorithm>  
#include <stdio.h>

using namespace std;


class USP {
	int population;
	int minAge;
	int maxAge;
	string gender;
	int zipCode;
	string geoID;
	public:
		friend class USPManager;
		USP() {};
		USP(int, int, int, string, int, string);
		 
};

USP::USP(int pop, int min, int max, string gen, int zip, string geo) {
	population = pop;
	minAge = min;
	maxAge = max;
	gender = gen;
	zipCode = zip;
	geoID = geo; 
}


class USPManager {
	public:
		void WriteToFile(vector<USP>&);
		void quickSort(vector<USP>&, int, int);
		int partition(vector<USP>&, int, int);
		USPManager() {};
		~USPManager() { };
};

void USPManager :: WriteToFile (vector<USP>& fileWrite)
{	
	int size = fileWrite.size();
	ofstream writing;
	writing.open("sorted_output.csv");
	for (int i = 0; i < size; i++)
	{
		writing << fileWrite[i].population << "," << fileWrite[i].minAge << "," << fileWrite[i].maxAge << "," << fileWrite[i].gender << "," << fileWrite[i].zipCode << "," << fileWrite[i].geoID << endl;
	}

}


void USPManager::quickSort(vector<USP>& popArray, int l, int h)
{
	if (l < h)
	{
		int q = partition(popArray, l, h);

		quickSort(popArray, l, q - 1);
		quickSort(popArray, q + 1, h);
	}
}

int  USPManager::partition(vector<USP>& popArray, int l, int h)
{
	USP pivot;
	pivot = popArray[h];
	int i = (l - 1);

	for (int j = l; j <= h; j++)
	{
		if (popArray[j].population < pivot.population)
		{
			i++;
			swap(popArray[i], popArray[j]);
		}
		else if (popArray[j].population == pivot.population)
		{
			if (strcmp(popArray[j].geoID.c_str(), pivot.geoID.c_str()) < 0)
			{
				i++;
				swap(popArray[i], popArray[j]);
			}
		}
	}
	swap(popArray[i + 1], popArray[h]);
	return(i + 1);
}