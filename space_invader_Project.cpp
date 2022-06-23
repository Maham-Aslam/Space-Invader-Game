#include"mygraphics.h"
#include<iostream>
using namespace std;

void drawAlien(int x, int y, int show) {
	drawRectangle(x, y, x + 50, y + 50, 0, 0, 255 * show);

}

void initializeAliens(int x[], int y[], int totalAliens) {
	int x_i = 101 - 50;
	int y_i = 31;
	int w = 80;
	x[0] = (x_i + w);
	y[0] = y_i;
	for (int i = 1; i < totalAliens; i++) {
		w += 80;
		x[i] = (x_i + w);
		y[i] = y_i;

		if (i == 4 || i == 9) {
			w = 0;
			x_i = 101 - 50;
			y_i += 60;
		}
		else {

		}

	}

}

void showAliens(int x[], int y[], int aliens[], int totalAliens) {

	for (int i = 0; i < totalAliens; i++) {
		drawAlien(x[i], y[i], aliens[i]);
	}
}

void hideAliens(int x[], int y[], int totalAliens) {

	for (int i = 0; i < totalAliens; i++) {
		
		drawAlien(x[i], y[i], 0);
	}

}

void dropAlien(int x[], int y[]) {
	int totalAliens = 15;
	int x_i = 101 - 50;
	int y_i = y[0];
	y_i += 50;
	int w = 80;
	x[0] = (x_i + w);
	y[0] = y_i;
	for (int i = 1; i < totalAliens; i++) {
		w += 80;
		x[i] = (x_i + w);
		y[i] = y_i;

		if (i == 4 || i == 9) {
			w = 0;
			x_i = 101 - 50;
			y_i += 60;
		}
		else {

		}

	}
}
void moveAliens(int w, int h, int x[], int y[], int totalAliens) {
	/*

	int x_i = 101;
	int y_i = 31;
	int w = 60;
	x[0] = (x_i + w);
	y[0] = y_i;
	for (int i = 1; i < totalAliens; i++) {
		w += 60;
		x[i] = (x_i + w);
		y[i] = y_i;

		if (i == 4 || i == 9) {
			w = 0;
			x_i = 101;
			y_i += 60;
		}
		else {

		}

	}

	*/
	int y_increment = 50;

	for (int i = 0; i < totalAliens; i++) {


		x[i] += 5;

		if (x[i] > w) {

			dropAlien(x,y);
			/*int x_i = 101 - 50;
			int y_i = 31;
			y_i += 50;
			int w = 80;
			x[0] = (x_i + w);
			y[0] = y_i;
			for (int i = 1; i < totalAliens; i++) {
				w += 80;
				x[i] = (x_i + w);
				y[i] = y_i;

				if (i == 4 || i == 9) {
					w = 0;
					x_i = 101 - 50;
					y_i += 60;
				}
				else {

				}

			}*/


		}
	}
}

void moveShip(int &x_ship, int &y_ship, char key) {

	if (key == 'd') {
		x_ship += 20;
	}

	if (key == 'a') {
		x_ship -= 20;
	}
}

void Ship(int x, int y, bool flag) {
	
	//main body
	drawRectangle(x, y , x + 50, y + 20, 0, 0,0, 0, 255*flag, 0);
	
}

void drawBullet(int x, int y,bool show) {
	
	drawLine(x, y, x, y + 5, 255*show, 0, 0);
}

int checkHit(int s_x, int s_y, int x_bullet, int y_bullet) {
	if (x_bullet > s_x && x_bullet < s_x + 48 && y_bullet > s_y && y_bullet < s_y + 50) {
		return 1;
	}
	else return 0;
}

int hit(int x[], int y[], int alien[],int totalShips, int x_bullet, int y_bullet) {
	int hit_a = 0;
	for (int i = 0; i < totalShips; i++) {
		if (checkHit(x[i], y[i], x_bullet, y_bullet) && alien[i] == 1) {
			alien[i] = 0;
			hit_a = 1;
			break;
		}
	}
	return hit_a;
}
int main() {
	cls();
	int w, h;
	getWindowDimensions(w, h);
	system("pause");
	cls();
	//cout << "press S to start the game" << endl;
	//cin >> enter;
	drawLine(0, 420, 2000, 420, 90, 180, 230);


	// Initialising
	showConsoleCursor(false);

	// main event loop;

	const int totalAliens = 15;
	int x[totalAliens];
	int y[totalAliens];
	int direction[totalAliens];
	int alien[totalAliens];
	int nullAll[totalAliens] = {};

	int x_i = 101 - 50;
	int y_i = 31;
	int s_x = w / 2;
	int s_y = (h/2) + 200;
	int x_bullet = s_x - 24;
	int y_bullet = s_y;
	char key ='a';
	bool fire = false;
	for (int i = 0; i < totalAliens; i++) {
		alien[i] = 1;
	}

	int score = 0;
	initializeAliens(x, y, totalAliens);
	while (true) {
		gotoxy(0, 0);
		cout << "Score : " << score;
		/*
				x_ship = w / 2;//ship is horizontally in the centre
	y_ship = 9 * h / 10;//ship is vertically in the last tenth of the screen
		*/
		moveShip(s_x, s_y, key);
		
		Ship(s_x, s_y,1);

		moveAliens(w, h, x, y, totalAliens);
		//x[0] += 10 * direction;
		//x[1] += 10 * direction;
		//if (x[0] > w - 10 || x[1] > w - 10) {
		//	direction = direction * -1;
		//}

		showAliens(x, y, alien, totalAliens);

		key = getKey();
		
		if (key == 'w') {
			fire = true;
		}

		

		if (fire) {
			drawBullet(x_bullet + 25, y_bullet, 1); 

		}


		delay(100);

		if (fire) {
			drawBullet(x_bullet + 25, y_bullet, 0);
			y_bullet -= 25;
			if (hit(x, y, alien, totalAliens, x_bullet, y_bullet)) {/*Check if bullet hits*/
				fire = false;
				score += 10;
			}
		}

		if (!fire) {
			x_bullet = s_x + 5;
			y_bullet = s_y;
		}


		if (y_bullet < 10) {

			fire = false;
			x_bullet = s_x + 5;
			y_bullet = s_y;
		}

		hideAliens(x, y, totalAliens);
		Ship(s_x, s_y, 0);
		
		drawBullet(x_bullet, y_bullet, 0);


	


		drawBullet(x_bullet, y_bullet, 0);


		if (score == 150) {
			break;
		}
		bool end = false;
		for (int i = 0;i < totalAliens; i++) {
			if (y[i] >= s_y - 50) {
				end = true;
				break;
			}
		}
		if (end)break;
		//drawAlien(x[0], y[0], 0);
		//drawAlien(x[1], y[1], 0);
	}
	cls();

	cout << endl;
	if (score == 150) {
		cout << "You Win!!!";
	}
	else {
		cout << "You Lose!!!";
	}
	cout << endl;

	showConsoleCursor(true);

	gotoxy(0, 0);
	system("PAUSE");
	return 0;
}

