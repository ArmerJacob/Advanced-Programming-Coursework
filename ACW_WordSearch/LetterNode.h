#pragma once
using namespace std;

class LetterNode
{
private:
	LetterNode* right = nullptr;
	LetterNode* topRight = nullptr;
	LetterNode* top = nullptr;
	LetterNode* topLeft = nullptr;
	LetterNode* left = nullptr;
	LetterNode* bottomLeft = nullptr;
	LetterNode* bottom = nullptr;
	LetterNode* bottomRight = nullptr;
	int cellPossitionY = 0;
	int cellPossitionX = 0;
	char cellLetter = ' ';
public:
	LetterNode();	
	~LetterNode();
	const char getCellLetter() const;
	void setCellLetter(char pCellLetter);
	const int getCellPossitionY() const;
	const int getCellPossitionX() const;
	void setCellPossitionY(int pCellPossition);
	void setCellPossitionX(int pCellPossition);
	LetterNode* getRight() const;
	LetterNode* getTopRight() const;
	LetterNode* getTop() const;
    LetterNode* getTopLeft() const;
	LetterNode* getLeft() const;
	LetterNode* getBottomLeft() const;
	LetterNode* getBottom() const;
	LetterNode* getBottomRight() const;
    void setRight(LetterNode* &pRight);
	void setTopRight(LetterNode* &pTopRight);
	void setTop(LetterNode* &pTop);
	void setTopLeft(LetterNode* &pTopLeft);
	void setLeft(LetterNode* &pLeft);
	void setBottomLeft(LetterNode* &pBottomLeft);
	void setBottom(LetterNode* &pBottom);
	void setBottomRight(LetterNode* &pBottomRight);
};

inline const char LetterNode::getCellLetter() const
{
	return cellLetter;
}
inline void LetterNode::setCellLetter(const char pCellLetter)
{
	cellLetter = pCellLetter;
}
inline const int LetterNode::getCellPossitionY() const
{
	return cellPossitionY;
}
inline const int LetterNode::getCellPossitionX()  const
{
	return cellPossitionX;
}
inline void LetterNode::setCellPossitionY(const int pCellPossition)
{
	cellPossitionY = pCellPossition;
}
inline void LetterNode::setCellPossitionX(const int pCellPossition)
{
	cellPossitionX = pCellPossition;
}
inline LetterNode* LetterNode::getRight() const
{
	return right;
}
inline LetterNode* LetterNode::getTopRight() const
{
	return topRight;
}
inline LetterNode* LetterNode::getTop() const
{
	return top;
}
inline LetterNode* LetterNode::getTopLeft() const
{
	return topLeft;
}
inline LetterNode* LetterNode::getLeft() const
{
	return left;
}
inline LetterNode* LetterNode::getBottomLeft() const
{
	return bottomLeft;
}
inline LetterNode* LetterNode::getBottom() const
{
	return bottom;
}
inline LetterNode* LetterNode::getBottomRight() const
{
	return bottomRight;
}

inline void LetterNode::setRight(LetterNode* &pRight)
{
	right = pRight;
}
inline void LetterNode::setTopRight(LetterNode* &pTopRight)
{
	topRight = pTopRight;
}
inline void LetterNode::setTop(LetterNode* &pTop)
{
	top = pTop;
}
inline void LetterNode::setTopLeft(LetterNode* &pTopLeft)
{
	topLeft = pTopLeft;
}
inline void LetterNode::setLeft(LetterNode* &pLeft)
{
	left = pLeft;
}
inline void LetterNode::setBottomLeft(LetterNode* &pBottomLeft)
{
	bottomLeft = pBottomLeft;
}
inline void LetterNode::setBottom(LetterNode* &pBottom)
{
	bottom = pBottom;
}
inline void LetterNode::setBottomRight(LetterNode* &pBottomRight)
{
	bottomRight = pBottomRight;
}

