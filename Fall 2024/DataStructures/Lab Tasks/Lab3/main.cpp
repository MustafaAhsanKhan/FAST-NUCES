#include <iostream>
using namespace std;
#include "header.h"

int main()
{
	int players[12][10];
	int totalRuns[12] = {};
	int avgRuns[12] = {};
	int playerIndices[12] = {};

	srand(time(0));

	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			players[i][j] = rand() % 21;
		}
	}

	computeStatistics(players, 12, totalRuns, avgRuns);

	sortPlayersByTotalRuns(totalRuns, playerIndices, 12);

	printTop10Players(totalRuns, playerIndices, 12);

	cout << endl;


	double gpaArray[3][3] = { {3.5, 3.7, 3.9},
								{3.2, 3.3, 3.1},
								{3.8, 3.6, 3.9} };

	computeCGPAsAndFindLowest(gpaArray, 3);
}