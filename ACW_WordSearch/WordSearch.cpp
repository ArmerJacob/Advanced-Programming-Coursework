#include "WordSearch.h"
#include <fstream>
#include <iostream>
using namespace std;


WordSearch::WordSearch(const char * const filename) : puzzleArraySimple(), outputFileName(filename) {
		
}

WordSearch::~WordSearch() {
	
}

void WordSearch::ReadSimplePuzzle() {
	// Add your code here
	char c;
	ifstream fin(puzzleName);
	fin.get(c);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fin >> puzzleArraySimple[i][j];
		}
	}
}

void WordSearch::ReadSimpleDictionary() {
	// Add your code here
	string temp = "";
	ifstream fin(dictionaryName);
	if (fin.is_open())
	{
		while (fin >> temp)
		{
			dictionary.push_back(temp);
		}
	}
}

 void WordSearch::ReadAdvancedPuzzle() {
	
	char s;
	string sSize;
	bool read = true;
	ifstream fin(puzzleName);
	while(read)
	{
		fin.get(s);
		if (isdigit(s))
		{
			sSize += s;
		}
		else 
		{
			read = false;
		}
	}
	size = stoi(sSize);
	linkedList.setGridSize(size);
	char c;
	fin.get(c);
	linkedList.setUpList(c);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i == 0 && j == 0)
			{
				j++;
			}
			char tempC;			
			fin >> tempC;
			if(tempC == ' ')
			{

			}
			else
			{
				linkedList.addToList(tempC, i, j);
			}
		}
	}
	linkedList.linkList();
}

void WordSearch::ReadAdvancedDictionary() {
	cout << "Method not implimented.";
	ReadSimpleDictionary();
}

void WordSearch::SolvePuzzleSimple() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			const int length = dictionary.size();
			for (int l = 0; l < length; l++)
			{
				dictioanaryEntriesVisited++;
				cellsVisited++;
				if (puzzleArraySimple[i][j] == dictionary[l][0])
				{
					if (i + 1 < 9 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i + 1][j])
						{
							string temp = "";
							const int length = dictionary[l].length();
							for (int k = 0; k < length; k++)
							{
								if (i + k > 9)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i + k][j];
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}
					if (i + 1 < 50 && j + 1 < 50 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i + 1][j + 1])
						{
							string temp = "";
							const int length = dictionary[l].length();
							for (int k = 0; k < length; k++)
							{
								if (i + k > 50 || j + k > 50)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i + k][j + k];
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}
					if (j + 1 < 9 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i][j + 1])
						{
							string temp = "";
							const int length = dictionary[l].length();
							for (int k = 0; k < length; k++)
							{
								if (j + k > 9)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i][j + k];
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}
					if (i - 1 > -1 && j + 1 < 9 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i - 1][j + 1])
						{
							string temp = "";
							const int length = dictionary[l].length();
							for (int k = 0; k < length; k++)
							{
								if (i - k < 0 || j + k > 9)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i - k][j + k];
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}
					if (i - 1 > -1 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i - 1][j])
						{
							string temp = "";
							const int length = dictionary[l].length();
							for (int k = 0; k < length; k++)
							{
								if (i - k < 0)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i - k][j];
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}
					if (i - 1 > -1 && j - 1 > -1 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i - 1][j - 1])
						{
							string temp = "";
							const int length = dictionary[l].length();
							for (int k = 0; k < length; k++)
							{
								if (i - k < 0 || j - k < 0)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i - k][j - k];
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}
					if (j - 1 > -1 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i][j - 1])
						{
							string temp = "";
							const int length = dictionary[l].length();
							for (int k = 0; k < length; k++)
							{
								if (j - k < 0)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i][j - k];
								}
							}
							dictioanaryEntriesVisited++;
						    if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}
					if (i + 1 < 9 && j - 1 > -1 && dictionary[l] != "")
					{
						dictioanaryEntriesVisited++;
						cellsVisited++;
						if (dictionary[l][1] == puzzleArraySimple[i + 1][j - 1])
						{
							string temp = "";
							const int length = dictionary[j].length();
							for (int k = 0; k < length; k++)
							{
								if (i + k > 9 || j - k < 0)
								{

								}
								else
								{
									cellsVisited++;
									temp += puzzleArraySimple[i + k][j - k];
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[l])
							{
								foundWords.push_back(dictionary[l]);
								startingXCoord.push_back(i);
								startingYCoord.push_back(j);
								dictionary[l].clear();
							}
						}
					}

				}
			}
		}
	}
}

void WordSearch::SolvePuzzleAdvanced() {
	// Add your code here
	for (int j = 0; j < dictionary.size(); j++)
	{
		LetterNode* lineHead = linkedList.getHeadNode();
		for (int i = 0; i < linkedList.getSize(); i++)
		{
			dictioanaryEntriesVisited++;
			cellsVisited++;
				if (linkedList.getCurrentNode()->getCellLetter() == dictionary[j][0])
				{
					if (linkedList.getCurrentNode()->getRight() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getRight());
						dictioanaryEntriesVisited++;
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1] && dictionary[j] != "")
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for(int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getRight() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getRight());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
					dictioanaryEntriesVisited++;
					if (linkedList.getCurrentNode()->getTopRight() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						dictioanaryEntriesVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getTopRight());
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1] && dictionary[j] != "")
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for (int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getTopRight() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getTopRight());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
					dictioanaryEntriesVisited++;
					if (linkedList.getCurrentNode()->getTop() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getTop());
						dictioanaryEntriesVisited++;
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1])
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for (int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getTop() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getTop());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
					dictioanaryEntriesVisited++;
					if (linkedList.getCurrentNode()->getTopLeft() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getTopLeft());
						dictioanaryEntriesVisited++;
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1] && dictionary[j] != "")
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for (int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getTopLeft() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getTopLeft());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
					dictioanaryEntriesVisited++;
					if (linkedList.getCurrentNode()->getLeft() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getLeft());
						dictioanaryEntriesVisited++;
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1] && dictionary[j] != "")
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for (int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getLeft() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getLeft());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
					dictioanaryEntriesVisited++;
					if (linkedList.getCurrentNode()->getBottomLeft() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getBottomLeft());
						dictioanaryEntriesVisited++;
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1] && dictionary[j] != "")
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for (int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getBottomLeft() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getBottomLeft());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
					dictioanaryEntriesVisited++;
					if (linkedList.getCurrentNode()->getBottom() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getBottom());
						dictioanaryEntriesVisited++;
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1] && dictionary[j] != "")
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for (int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getBottom() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getBottom());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
					dictioanaryEntriesVisited++;
					if (linkedList.getCurrentNode()->getBottomRight() != nullptr && dictionary[j] != "")
					{
						cellsVisited++;
						linkedList.setCheckNode(linkedList.getCurrentNode()->getBottomRight());
						dictioanaryEntriesVisited++;
						if (linkedList.getCheckNode()->getCellLetter() == dictionary[j][1] && dictionary[j] != "")
						{
							string temp = "";
							linkedList.setCheckNode(linkedList.getCurrentNode());
							for (int k = 0; k < dictionary[j].length(); k++)
							{
								cellsVisited++;
								temp += linkedList.getCheckNode()->getCellLetter();
								if (linkedList.getCheckNode()->getBottomRight() != nullptr)
								{
									linkedList.setCheckNode(linkedList.getCheckNode()->getBottomRight());
								}
							}
							dictioanaryEntriesVisited++;
							if (temp == dictionary[j])
							{
								foundWords.push_back(dictionary[j]);
								startingXCoord.push_back(linkedList.getCurrentNode()->getCellPossitionY());
								startingYCoord.push_back(linkedList.getCurrentNode()->getCellPossitionX());
								dictionary[j].clear();
							}
						}
					}
				}
				if (linkedList.getCurrentNode()->getCellPossitionX() == size - 1 && linkedList.getCurrentNode()->getBottom() != nullptr)
				{
					linkedList.setCurrentNode(lineHead->getBottom());
					lineHead = linkedList.getCurrentNode();
				}
				else
				{
					linkedList.setCurrentNode(linkedList.getCurrentNode()->getRight());
				}
			
		}
		linkedList.setCurrentNode(linkedList.getHeadNode());
	}
}

void WordSearch::WriteResults(const double loadTime, const double solveTime) const {
	// Add your code here
	ofstream fout(outputFileName);
	fout << "NUMBER_OF_WORDS_MATCHED " << foundWords.size() << endl << endl;
	fout << "WORDS_MATCHED_IN_GRID" << endl;
	for (int i = 0; i < foundWords.size(); i++)
	{
		fout << startingXCoord[i] << " " << startingYCoord[i] << " " << foundWords[i] << endl;
	}
	fout << endl;
	fout << "WORDS_UNMATCHED_IN_GRID" << endl;
	for (int j = 0; j < dictionary.size(); j++)
	{
		if (dictionary[j] != "")
		{
			fout << dictionary[j] << endl;
		}
	}
	fout << endl;
	fout << "NUMBER_OF_GRID_CELLS_VISITED " << cellsVisited << endl << endl;
	fout << "NUMBER_OF_DICTIONARY_ENTRIES_VISITED " << dictioanaryEntriesVisited << endl << endl;
	fout << "TIME_TO_POPULTE_GRID_STRUCTURE " << loadTime << endl << endl;
	fout << "TIME_TO_SOLVE_PUZZLE " << solveTime << endl;
}