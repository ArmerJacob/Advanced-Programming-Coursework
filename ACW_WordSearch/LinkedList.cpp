#include "LinkedList.h"

using namespace std;



LinkedList::LinkedList()
{
}

LinkedList::LinkedList(LinkedList &pList)
{
	letterNodes = pList.letterNodes;
	headNode = pList.headNode;
	currentNode = pList.currentNode;
	size = pList.size;
	gridSize = pList.gridSize;
}

LinkedList::~LinkedList()
{
}

void LinkedList::linkList()
{	
	setHeadNode(&letterNodes[0]);
	setCurrentNode(&letterNodes[0]);
	setSize(letterNodes.size());
	for (int i = 0; i < letterNodes.size(); i++)
	{
		if (i + 1 < letterNodes.size())
		{
			if (letterNodes[i].getCellPossitionY() == letterNodes[i + 1].getCellPossitionY() && letterNodes[i].getCellPossitionX() + 1 == letterNodes[i + 1].getCellPossitionX())
			{
				tempAddress = &letterNodes[i + 1];
				letterNodes[i].setRight(tempAddress);
			}
		}
		if ( i - gridSize + 1 > 0)
		{
			if (letterNodes[i].getCellPossitionY() - 1 == letterNodes[i - gridSize + 1].getCellPossitionY() && letterNodes[i].getCellPossitionX() + 1 == letterNodes[i - gridSize + 1].getCellPossitionX())
			{
				tempAddress = &letterNodes[i - gridSize + 1];
				letterNodes[i].setTopRight(tempAddress);
			}
		}
		if (i - gridSize > 0 || i - gridSize == 0)
		{
			if (letterNodes[i].getCellPossitionY() - 1 == letterNodes[i - gridSize].getCellPossitionY() && letterNodes[i].getCellPossitionX() == letterNodes[i - gridSize].getCellPossitionX())
			{
				tempAddress = &letterNodes[i - gridSize];
				letterNodes[i].setTop(tempAddress);
			}
		}
		if (i - gridSize - 1 > 0)
		{
			if (letterNodes[i].getCellPossitionY() - 1 == letterNodes[i - gridSize - 1].getCellPossitionY() && letterNodes[i].getCellPossitionX() - 1 == letterNodes[i - gridSize - 1].getCellPossitionX())
			{
				tempAddress = &letterNodes[i - gridSize - 1];
				letterNodes[i].setTopLeft(tempAddress);
			}
		}
		if (i - 1 != -1)
		{
			if (letterNodes[i].getCellPossitionY() == letterNodes[i - 1].getCellPossitionY() && letterNodes[i].getCellPossitionX() - 1 == letterNodes[i - 1].getCellPossitionX())
			{
				tempAddress = &letterNodes[i - 1];
				letterNodes[i].setLeft(tempAddress);
			}
		}
		if (i + gridSize < letterNodes.size())
		{
			if (letterNodes[i].getCellPossitionY() + 1 == letterNodes[i + gridSize - 1].getCellPossitionY() && letterNodes[i].getCellPossitionX() - 1 == letterNodes[i + gridSize - 1].getCellPossitionX())
			{
				tempAddress = &letterNodes[i + gridSize - 1];
				letterNodes[i].setBottomLeft(tempAddress);
			}
		}
		if (i + gridSize < letterNodes.size())
		{
			if (letterNodes[i].getCellPossitionY() + 1 == letterNodes[i + gridSize].getCellPossitionY() && letterNodes[i].getCellPossitionX() == letterNodes[i + gridSize].getCellPossitionX())
			{
				tempAddress = &letterNodes[i + gridSize];
				letterNodes[i].setBottom(tempAddress);
			}
		}
		if (i + gridSize + 1 < letterNodes.size())
		{
			if (letterNodes[i].getCellPossitionY() + 1 == letterNodes[i + gridSize + 1].getCellPossitionY() && letterNodes[i].getCellPossitionX() + 1 == letterNodes[i + gridSize + 1].getCellPossitionX())
			{
				tempAddress = &letterNodes[i + gridSize + 1];
				letterNodes[i].setBottomRight(tempAddress);
			}
		}
	}
}
void LinkedList::addToList(const char pC,const int pPosX,const int pPosY)
{
	LetterNode tempNode;
	tempNode.setCellLetter(pC);
	tempNode.setCellPossitionY(pPosX);
	tempNode.setCellPossitionX(pPosY);
	letterNodes.push_back(tempNode);
}