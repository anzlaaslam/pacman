#include "mygraphics.h"
#include <iostream>
using namespace std;
class GameData
{
public:
	GameData();
	~GameData();
	int PlayerScore;
	int PlayerLives;
};
GameData::GameData()
{
	PlayerScore = 0;
	PlayerLives = 0;
}
GameData::~GameData()
{

}
class Object
{
protected:
	int axis1;
	int Yaxis1;
	int Yaxis2;
	int axis2;
public:
	Object();
	virtual ~Object();
	virtual void set_dimensions(int, int, int, int) = 0;
	virtual void drawObject() = 0;
	virtual void EraseObject() = 0;
};
Object::Object()
{
	axis1 = 0;
	Yaxis1 = 0;
	Yaxis2 = 0;
	axis2 = 0;
}
Object::~Object()
{

}

class Packman :public Object //Inheritance
{

public:
	Packman();
	~Packman();
	void set_dimensions(int, int, int, int);
	void drawObject();
	void EraseObject();
	GameData PR; //Composition
};
Packman::Packman()
{

}
Packman::~Packman()
{

}
void Packman::drawObject()
{
	drawCircle(axis1, Yaxis1, axis2, Yaxis2, 255, 211, 0, 255, 211, 0);
}
void Packman::set_dimensions(int axis1, int Yaxis1, int axis2, int Yaxis2)
{
	this->axis1 = axis1;
	this->Yaxis1 = Yaxis1;
	this->axis2 = axis2;
	this->Yaxis2 = Yaxis2;
}
void Packman::EraseObject()
{
	drawCircle(axis1, Yaxis1, axis2, Yaxis2, 255, 211, 0, 0, 0, 0);
}
class Pakman_ghost :public Object //Inheritance
{
public:
	Pakman_ghost();
	~Pakman_ghost();
	void set_dimensions(int, int, int, int);
	void drawObject();
	void EraseObject();
};
Pakman_ghost::Pakman_ghost()
{

}
Pakman_ghost::~Pakman_ghost()
{

}
void Pakman_ghost::drawObject()
{
	drawRectangle(axis1, Yaxis1, axis2, Yaxis2, 255, 20, 147, 255, 20, 147);
}
void Pakman_ghost::set_dimensions(int axis1, int Yaxis1, int axis2, int Yaxis2)
{
	this->axis1 = axis1;
	this->Yaxis1 = Yaxis1;
	this->axis2 = axis2;
	this->Yaxis2 = Yaxis2;
}
void Pakman_ghost::EraseObject()
{
	drawRectangle(axis1, Yaxis1, axis2, Yaxis2, 0, 0, 0, 0, 0, 0);
}
class Pakman_energizer
{
public:
	Pakman_energizer();
	~Pakman_energizer();
	void draw_Pakman_energizer(int axis1, int Yaxis1, int axis2, int Yaxis2);
};
Pakman_energizer::Pakman_energizer()
{

}
Pakman_energizer::~Pakman_energizer()
{

}
void Pakman_energizer::draw_Pakman_energizer(int axis1, int Yaxis1, int axis2, int Yaxis2)
{
	drawCircle(axis1, Yaxis1, axis2, Yaxis2, 255, 20, 147, 255, 20, 147);
}
class Board
{
public:
	Board();
	~Board();
	void showBoard(int w, int h);
	int DrawDots(int arr[][2], int w, int h);
	void REDrawDots(int arr[][2], int size);
	Pakman_energizer* E; //Association
};
Board::Board()
{

}
Board::~Board()
{

}
void Board::showBoard(int w, int h)
{
	drawLine(10, 10, 10, 150, 0, 0, 255);
	drawLine(10, 150, 120, 150, 0, 0, 255);
	drawLine(120, 150, 120, 200, 0, 0, 255);
	drawLine(10, 200, 120, 200, 0, 0, 255);
	drawLine(10, 250, 120, 250, 0, 0, 255);
	drawLine(120, 250, 120, 300, 0, 0, 255);
	drawLine(10, 300, 120, 300, 0, 0, 255);
	drawLine(10, 300, 10, 450, 0, 0, 255);
	drawLine(10, 10, w - 10, 10, 0, 0, 255);
	drawLine(w - 10, 10, w - 10, 150, 0, 0, 255);
	drawLine(w - 120, 150, w - 10, 150, 0, 0, 255);
	drawLine(w - 120, 150, w - 120, 200, 0, 0, 255);
	drawLine(w - 120, 200, w - 10, 200, 0, 0, 255);
	drawLine(w - 120, 250, w - 10, 250, 0, 0, 255);
	drawLine(w - 120, 250, w - 120, 300, 0, 0, 255);
	drawLine(w - 120, 300, w - 10, 300, 0, 0, 255);
	drawLine(w - 10, 300, w - 10, 450, 0, 0, 255);
	drawLine(10, 450, w - 10, 450, 0, 0, 255);

	drawRectangle(w / 2 - 25, 10, w / 2 + 25, 100, 0, 0, 255);
	drawRectangle(50, 50, 200, 100, 0, 0, 255);
	drawRectangle(250, 50, 400, 100, 0, 0, 255);

	drawRectangle(w / 2 + 75, 50, w / 2 + 225, 100, 0, 0, 255);
	drawRectangle(w / 2 + 275, 50, w / 2 + 425, 100, 0, 0, 255);
	drawRectangle(200, 150, 250, 300, 0, 0, 255);
	drawRectangle(w - 250, 150, w - 200, 300, 0, 0, 255);
	drawRectangle(w / 2 - 150, 155, w / 2 + 150, 290, 0, 0, 255);
	drawRectangle(w / 2 - 150, 155, w / 2 + 150, 290, 0, 0, 255);
	drawRectangle(w - 250, 355, w - 80, 405, 0, 0, 255);
	drawRectangle(w / 2 - 20, 355, w / 2 + 130, 405, 0, 0, 255);
	drawRectangle(200, 355, 370, 405, 0, 0, 255);
}
int Board::DrawDots(int arr[][2], int w, int h)
{
	int row = 0;
	for (int i = 130; i < h -50; i = i + 20)
	{
		drawLine(160, i, 160, i, 255, 211, 0);
		arr[row][1] = i;
		arr[row][0] = 160;
		row++;
	}
	for (int i = 50; i < w / 2 +270; i = i + 20)
	{
		drawLine(i, 130, i, 130, 255, 211, 0);
		arr[row][1] = 130;
		arr[row][0] = i;
		row++;
	}
	for (int i = 130; i < h - 50; i = i + 20)
	{
		drawLine(w / 2 + 180, i, w / 2 + 180, i, 255, 211, 0);
		arr[row][1] = i;
		arr[row][0] = w / 2 + 180;
		row++;
	}
	

	for (int i = 50; i < w / 2 + 270; i = i + 20)
	{
		drawLine(i, h - 150, i, h - 150, 255, 211, 0);
		arr[row][1] = h - 150;
		arr[row][0] = i;
		row++;
	}
	for (int i = 150; i < w / 2 + 390; i = i + 20)
	{
		drawLine(i, h -50, i, h-50, 255, 211, 0);
		arr[row][1] = h - 150;
		arr[row][0] = i;
		row++;
	}
	for (int i = 150; i < h - 160; i = i + 20)
	{
		drawLine(280, i, 280, i, 255, 211, 0);
		arr[row][1] = i;
		arr[row][0] = 280;
		row++;
	}

	return row;
}
void Board::REDrawDots(int arr[][2], int row)
{
	for (int i = 0; i < row; i++)
	{
		drawLine(arr[i][0], arr[i][1], arr[i][0], arr[i][1], 255, 211, 0);
	}
}
int main() {

	bool check = true;
	bool check2 = true;
	bool check3 = false;
	bool check4 = false;
	bool check5 = false;
	bool checkEng = false;
	bool winCheck = false;
	int dpos[200][2] = {};
	int size = 0;
	int w = 0, h = 0;
	getWindowDimensions(w, h);
	cls();
	showConsoleCursor(false);
	Board G;
	Packman P;
	int axis1 = 200, axis2 = 240, Yaxis1 = 60, Yaxis2 = 90;
	int e1axis1 = 130, e1axis2 = 180, e1Yaxis1 = 350, e1Yaxis2 = 390;
	int e2axis1 = 640, e2axis2 = 690, e2Yaxis1 = 310, e2Yaxis2 = 350;
	int engaxis1 = 30, engaxis2 = 40, engYaxis1 = 360, engYaxis2 = 370;
	Object* C1, * C2, * C3; //Polymorphism
	C1 = new Packman;
	C2 = new Pakman_ghost;
	C3 = new Pakman_ghost;
	C1->set_dimensions(axis1, Yaxis1, axis2, Yaxis2);
	C2->set_dimensions(e1axis1, e1Yaxis1, e1axis2, e1Yaxis2);
	C3->set_dimensions(e2axis1, e2Yaxis1, e2axis2, e2Yaxis2);
	P.PR.PlayerLives = 3;
	int i = 4, j = 2;
	size = G.DrawDots(dpos, w, h);

	while (1)
	{
		gotoxy(4, 29);//col,row
		cout << "PlayerScore: " << P.PR.PlayerScore << "	    PlayerLives: " << P.PR.PlayerLives;
		G.REDrawDots(dpos, size);
		G.showBoard(w, h);
		G.E->draw_Pakman_energizer(engaxis1, engYaxis1, engaxis2, engYaxis2);
		C1->drawObject();
		for (int k = 0; k < size; k++)
		{
			if ((dpos[k][1] >= Yaxis1 && dpos[k][1] <= Yaxis2) && (dpos[k][0] >= axis1 && dpos[k][0] <= axis2))
			{
				P.PR.PlayerScore++;
				dpos[k][1] = -1;
				dpos[k][0] = -1;
			}
		}
		if ((engYaxis1 >= Yaxis1 && engYaxis1 <= Yaxis2) && (engaxis1 >= axis1 && engaxis1 <= axis2))
		{
			engaxis1 = -1;
			engaxis2 = -1;
			engYaxis1 = -1;
			engYaxis2 = -1;
			checkEng = true;

		}
		if (check == true)
		{
			G.showBoard(w, h);
			C2->set_dimensions(e1axis1, e1Yaxis1, e1axis2, e1Yaxis2);
			C2->drawObject();
			delay(10);
			C2->EraseObject();
			e1Yaxis1 -= j;
			e1Yaxis2 -= j;
			if (e1Yaxis1 <= 104)
			{
				check = false;
			}
			if ((Yaxis2 == e1Yaxis1 || Yaxis1 == e1Yaxis2) && (axis1 >= e1axis1 && axis1 <= e1axis2) && (checkEng == false))
			{
				P.PR.PlayerLives--;
				cls();
				axis1 = 210, axis2 = 240, Yaxis1 = 60, Yaxis2 = 90;
				if (P.PR.PlayerLives == 0)
				{
					break;
				}
			}
			else if ((Yaxis2 == e1Yaxis1 || Yaxis1 == e1Yaxis2) && (axis1 >= e1axis1 && axis1 <= e1axis2) && (checkEng == true))
			{
				C2->EraseObject();
				e1axis1 = -1;
				e1axis2 = -1;
				e1Yaxis1 = -1;
				e1Yaxis2 = -1;
				checkEng = false;
				check = NULL;
				P.PR.PlayerScore += 10;
			}
		}
		else if (check == false)
		{

			G.showBoard(w, h);
			C2->set_dimensions(e1axis1, e1Yaxis1, e1axis2, e1Yaxis2);
			C2->drawObject();
			delay(10);
			C2->EraseObject();
			e1Yaxis1 += j;
			e1Yaxis2 += j;
			if (e1Yaxis2 >= h - 70)
			{
				check = true;
			}
			if ((Yaxis2 == e1Yaxis1 || Yaxis1 == e1Yaxis2) && (axis1 >= e1axis1 && axis1 <= e1axis2) && (checkEng == false))
			{
				P.PR.PlayerLives--;
				cls();
				axis1 = 210, axis2 = 240, Yaxis1 = 60, Yaxis2 = 90;
				if (P.PR.PlayerLives == 0)
				{
					break;
				}
			}
			else if ((Yaxis2 == e1Yaxis1 || Yaxis1 == e1Yaxis2) && (axis1 >= e1axis1 && axis1 <= e1axis2) && (checkEng == true))
			{
				C2->EraseObject();
				check = NULL;
				checkEng = false;
				e1axis1 = -1;
				e1axis2 = -1;
				e1Yaxis1 = -1;
				e1Yaxis2 = -1;
				P.PR.PlayerScore += 10;
			}
		}

		if (check2 == true)
		{
			G.showBoard(w, h);
			C3->set_dimensions(e2axis1, e2Yaxis1, e2axis2, e2Yaxis2);
			C3->drawObject();
			delay(10);
			C3->EraseObject();
			e2axis1 -= j;
			e2axis2 -= j;
			if (e2axis1 <= 275)
			{
				check2 = false;
				check3 = true;
			}
			if ((Yaxis1 >= e2Yaxis1 && Yaxis2 <= e2Yaxis2) && (axis1 == e2axis2 || axis2 == e2axis1) && (checkEng == false))
			{
				P.PR.PlayerLives--;
				cls();
				axis1 = 210, axis2 = 240, Yaxis1 = 60, Yaxis2 = 90;
				if (P.PR.PlayerLives == 0)
				{
					break;
				}
			}
			else if ((Yaxis1 >= e2Yaxis1 && Yaxis2 <= e2Yaxis2) && (axis1 == e2axis2 || axis2 == e2axis1) && (checkEng == true))
			{
				C3->EraseObject();
				check2 = false;
				checkEng = false;
				P.PR.PlayerScore += 10;
			}
		}
		else if (check3 == true)
		{
			G.showBoard(w, h);
			C3->set_dimensions(e2axis1, e2Yaxis1, e2axis2, e2Yaxis2);
			C3->drawObject();
			delay(10);
			C3->EraseObject();
			e2Yaxis1 -= j;
			e2Yaxis2 -= j;
			if (e2Yaxis1 <= 104)
			{
				check3 = false;
				check4 = true;
			}
			if ((Yaxis2 == e2Yaxis1 || Yaxis1 == e2Yaxis2) && (axis1 >= e2axis1 && axis1 <= e2axis2) && (checkEng == false))
			{
				P.PR.PlayerLives--;
				cls();
				axis1 = 210, axis2 = 240, Yaxis1 = 60, Yaxis2 = 90;
				if (P.PR.PlayerLives == 0)
				{
					break;
				}
			}
			else if ((Yaxis1 >= e2Yaxis1 && Yaxis2 <= e2Yaxis2) && (axis1 == e2axis2 || axis2 == e2axis1) && (checkEng == true))
			{
				C3->EraseObject();
				check3 = false;
				checkEng = false;
				P.PR.PlayerScore += 10;
			}
		}
		else if (check4 == true)
		{

			G.showBoard(w, h);
			C3->set_dimensions(e2axis1, e2Yaxis1, e2axis2, e2Yaxis2);
			C3->drawObject();
			delay(10);
			C3->EraseObject();
			e2axis1 += j;
			e2axis2 += j;
			if (e2axis2 >= 690)
			{
				check5 = true;
				check4 = false;
			}
			if ((Yaxis1 >= e2Yaxis1 && Yaxis2 <= e2Yaxis2) && (axis1 == e2axis2 || axis2 == e2axis1) && (checkEng == false))
			{
				P.PR.PlayerLives--;
				cls();
				axis1 = 210, axis2 = 240, Yaxis1 = 60, Yaxis2 = 90;
				if (P.PR.PlayerLives == 0)
				{
					break;
				}
			}
			else if ((Yaxis1 >= e2Yaxis1 && Yaxis2 <= e2Yaxis2) && (axis1 == e2axis2 || axis2 == e2axis1) && (checkEng == true))
			{
				C3->EraseObject();
				check4 = false;
				checkEng = false;
				P.PR.PlayerScore += 10;
			}

		}
		else if (check5 == true)
		{
			G.showBoard(w, h);
			C3->set_dimensions(e2axis1, e2Yaxis1, e2axis2, e2Yaxis2);
			C3->drawObject();
			delay(10);
			C3->EraseObject();
			e2Yaxis1 += j;
			e2Yaxis2 += j;
			if (e2Yaxis2 >= 350)
			{
				check2 = true;
				check5 = false;
			}
			if ((Yaxis2 == e2Yaxis1 || Yaxis1 == e2Yaxis2) && (axis1 >= e2axis1 && axis1 <= e2axis2) && (checkEng == false))
			{
				P.PR.PlayerLives--;
				cls();
				axis1 = 210, axis2 = 240, Yaxis1 = 60, Yaxis2 = 90;
				if (P.PR.PlayerLives == 0)
				{
					break;
				}
			}
			else if ((Yaxis1 >= e2Yaxis1 && Yaxis2 <= e2Yaxis2) && (axis1 == e2axis2 || axis2 == e2axis1) && (checkEng == true))
			{
				C3->EraseObject();
				check5 = false;
				checkEng = false;
				P.PR.PlayerScore += 10;
			}
		}
		if (GetAsyncKeyState(0x49))
		{
			cls();
			if (Yaxis1 >= 12)
			{
				Yaxis1 -= i;
				Yaxis2 -= i;
			}
			C1->set_dimensions(axis1, Yaxis1, axis2, Yaxis2);
			C1->drawObject();

		}
		if (GetAsyncKeyState(0x4B))
		{
			cls();
			if (Yaxis2 <= h - 36)
			{
				Yaxis1 += i;
				Yaxis2 += i;
			}
			C1->set_dimensions(axis1, Yaxis1, axis2, Yaxis2);
			C1->drawObject();
		}
		if (GetAsyncKeyState(0x4A))
		{
			cls();
			if (axis1 > 10 && (Yaxis2 < 230 || Yaxis2 > 250))
			{
				axis1 -= i;
				axis2 -= i;
			}
			else if (Yaxis2 >= 230 && Yaxis2 <= 250)
			{
				axis1 -= i;
				axis2 -= i;
			}
			if ((Yaxis2 >= 230 && Yaxis2 <= 250) && axis2 == 0)
			{
				axis1 = w - 30;
				axis2 = w;
			}
			C1->set_dimensions(axis1, Yaxis1, axis2, Yaxis2);
			C1->drawObject();
		}
		if (GetAsyncKeyState(0x4C))
		{
			cls();
			if (axis2 < w - 12 && (Yaxis2 < 230 || Yaxis2 > 250))
			{
				axis1 += i;
				axis2 += i;
			}
			else if (Yaxis2 >= 230 && Yaxis2 <= 250)
			{
				axis1 += i;
				axis2 += i;
			}
			if ((Yaxis2 >= 230 && Yaxis2 <= 250) && axis1 == w - 10)
			{
				axis1 = 0 - 30;
				axis2 = 0;
			}
			C1->set_dimensions(axis1, Yaxis1, axis2, Yaxis2);
			C1->drawObject();
		}
		for (int k = 0; k < size; k++)
		{
			if (dpos[k][1] == -1 && dpos[k][0] == -1)
			{
				winCheck = true;
			}
			else
			{
				winCheck = false;
				break;
			}
		}
		if (winCheck == true)
		{
			break;
		}
	}
	showConsoleCursor(true);
	cls();
	gotoxy(0, 0);
	cout << "PlayerScore is: " << P.PR.PlayerScore << endl;
	cout << "Game Over!" << endl;
	//system("pause");
	return 0;
}

