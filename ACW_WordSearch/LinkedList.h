#pragma once
#include <vector>
#include "LetterNode.h"

using namespace std;

class LinkedList
{
private:
	vector<LetterNode> letterNodes;
	LetterNode temp;
	LetterNode* headNode = nullptr;
	LetterNode* currentNode = nullptr;
	LetterNode* checkNode = nullptr;	
	LetterNode* tempAddress = nullptr;
	int size = 0;
	int gridSize = 0;
public:
	LinkedList();
	LinkedList(LinkedList &pList);
	~LinkedList();
	void setSize(int pSize);
	const int getSize() const;
	void setGridSize(int pSize);
	const int getGridSize() const;
	void setCurrentNode(LetterNode* pCurrentNode);
	LetterNode* getCurrentNode() const;
	void setCheckNode(LetterNode* pHeadNode);
	LetterNode* getCheckNode() const;
	void setHeadNode(LetterNode* pHeadNode);
	LetterNode* getHeadNode() const;
	void setUpList(char c);
	void linkList();
	void addToList(char pC, int pPosX, int pPosY);
};

inline void LinkedList::setSize(const int pSize)
{
	size = pSize;
}

inline const int LinkedList::getSize() const
{
	return size;
}

inline void LinkedList::setGridSize(const int pSize)
{
	gridSize = pSize;
}

inline const int LinkedList::getGridSize() const
{
	return gridSize;
}

inline void LinkedList::setHeadNode(LetterNode* pHeadNode)
{
	headNode = pHeadNode;
}
inline LetterNode* LinkedList::getHeadNode() const
{
	return headNode;
}
inline void LinkedList::setCheckNode(LetterNode* pCheckNode)
{
	checkNode = pCheckNode;
}
inline LetterNode* LinkedList::getCheckNode() const
{
	return checkNode;
}
inline void LinkedList::setCurrentNode(LetterNode* pCurrentNode)
{
	currentNode = pCurrentNode;
}
inline LetterNode* LinkedList::getCurrentNode() const
{
	return currentNode;
}
inline void LinkedList::setUpList(const char c)
{
	temp.setCellLetter(c);
	temp.setCellPossitionY(0);
	temp.setCellPossitionX(0);
	letterNodes.push_back(temp);
	tempAddress = &letterNodes[0];
}


