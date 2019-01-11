// IslandsQuestion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "conio.h"
#include <vector>


#define WIDTH 55
#define HEIGHT 14

int islandMap[HEIGHT][WIDTH] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

//int islandMap[HEIGHT][WIDTH] = {
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
//	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

int countIslandsSimple()
{
	int islandCount = 0;

	// For simplicity I am not dealing with first row and first column.
	// This algorithm only works for islands that have no ponds.
	for (int y = 1; y < HEIGHT; y++)
	{
		for (int x = 1; x < WIDTH; x++)
		{
			int TopLeft = islandMap[y - 1][x - 1];
			int Left    = islandMap[y][x - 1];    
			int Top     = islandMap[y - 1][x];
			int Current = islandMap[y][x];

			if (Left == 0 && Current == 1 && Top == 0)
			{
				//printf("Adding island at (%d,%d)\n", x, y);
				islandCount++;
			}
			if (Current == 1 && TopLeft == 0 && Top == 1 && Left == 1)
			{
				//printf("\t\t\t\t\tRemoving island at (%d,%d)\n", x, y);
				islandCount--;
			}
		}
	}
	return islandCount;
}

int countIslandsComplex()
{
	int islandCount = 0;
	int sourceCounter = 1;
	std::vector<int> sourceBank(WIDTH,0);

	// For simplicity I am not dealing with first row and first column.
	// This algorithm only works for islands that have no ponds.
	for (int y = 1; y < HEIGHT; y++)
	{
		for (int x = 1; x < WIDTH; x++)
		{
			int TopLeft = islandMap[y - 1][x - 1];
			int Left = islandMap[y][x - 1];
			int Top = islandMap[y - 1][x];
			int Current = islandMap[y][x];

			if (Left == 0 && Current == 1 && Top == 0)
			{
				//printf("Adding island at (%d,%d)\n", x, y);
				islandCount++;
			}
			if (Current == 1 && TopLeft == 0 && Top == 1 && Left == 1 && (sourceBank[x-1] != sourceBank[x]))
			{
				//printf("\t\t\t\t\tRemoving island at (%d,%d)\n", x, y);
				islandCount--;
			}

			// Update Source data
			if (Left == 1 && Current == 1 && Top == 0) // Copy from Left
			{
				sourceBank[x] = sourceBank[x - 1];
			}
			else if (Left == 0 && Current == 1 && Top == 1)
			{
				// Keep Existing source from previous row
			}
			else if (Left == 0 && Current == 0 && Top == 0)
			{
				sourceBank[x] = 0; // Clear source
			}
			else if (Left == 0 && Current == 1 && Top == 0) // New Source
			{
				sourceBank[x] = sourceCounter++;
			}
			else if (Current == 1 && TopLeft == 0 && Top == 1 && Left == 1 && (sourceBank[x - 1] != sourceBank[x]))
			{
				// Merge sources - Update source info 
				int oldSource = sourceBank[x];
				int newSource = sourceBank[x-1];
				//int xx = x;
				//while (sourceBank[xx] == oldSource) sourceBank[xx++] = newSource;
				for (int xx = 0; xx < WIDTH; xx++)
				{
					if (sourceBank[xx] == oldSource) sourceBank[xx] = newSource;
				}
			}
		}
	}
	return islandCount;
}

void printMap()
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			int Current = islandMap[y][x];
			printf("%d", Current);
		}
		printf("\n"); 
	}
}

int main()
{
	printf("**************************************************************************\n");
	printf("*                           Starting                                     *\n");
	printf("**************************************************************************\n");
	int simpleCount = countIslandsSimple();
	printf("There are %d islands(Simple)\n", simpleCount);
	int complexCount = countIslandsComplex();
	printf("There are %d islands(Complex)\n", complexCount);
	printMap();
	_getch();
    return 0;
}

