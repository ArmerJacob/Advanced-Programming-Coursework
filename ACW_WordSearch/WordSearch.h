#pragma once
#include <vector>
#include <string>
#include "LinkedList.h"
#include "LetterNode.h"
using namespace std;
using std::vector;

class WordSearch {
private:
	LinkedList linkedList;
	vector<string> dictionary;
	vector<string> foundWords;
	vector<int> startingXCoord;
	vector<int> startingYCoord;	
	char puzzleArraySimple[9][9];
	const char* puzzleName = "wordsearch_grid.txt";
	const char* dictionaryName = "dictionary.txt";
	const char*  outputFileName;
	int size = 0;
	int cellsVisited = 0;
	int dictioanaryEntriesVisited = 0;
	// Add your code here

public:
	explicit WordSearch(const char * const filename);
	~WordSearch();
	void ReadSimplePuzzle();
	void ReadSimpleDictionary();
    void ReadAdvancedPuzzle();
	void ReadAdvancedDictionary();
	void SolvePuzzleSimple();
    void SolvePuzzleAdvanced();
	void WriteResults(const	double loadTime, const double solveTime) const;

	// Add your code here
};

