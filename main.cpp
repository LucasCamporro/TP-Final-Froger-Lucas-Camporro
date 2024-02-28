#include<iostream>
#include <ctime>
#include <conio2.h>
#include <cstdio>
#include <windows.h>

using namespace std;

class Obstaculo {
protected:
	int yObjeto;
	int dy;
	int dx;
	int xObjeto;
	
public:
	Obstaculo();
	int getXObjeto(); // M�todo para obtener la posici�n xObjeto
	virtual void chckBordes();
	virtual void dibujar();
	virtual void mover1();
};

Obstaculo::Obstaculo() {
	xObjeto = rand() % (220 - 10 + 1) + 10;
	yObjeto = rand() % (50 - 10 + 1) + 10;
	dx = 1;
	dy = 1;
}

int Obstaculo::getXObjeto() {
	return xObjeto;
}

void Obstaculo::mover1() {
	chckBordes();
	
	if (dx == 1) {
		xObjeto += 1;
	}
	if (dx == -1) {
		xObjeto -= 1;
	}
	dibujar();
}

void Obstaculo::dibujar() {
	textcolor(3);
	for (int i = 1; i < 10; i++) {
		gotoxy(xObjeto + i, yObjeto);
		cout << (char)219;
	}
	for (int i = 1; i < 10; i++) {
		gotoxy(xObjeto + i, yObjeto - 1);
		cout << (char)219;
	}
}

void Obstaculo::chckBordes() {
	if (xObjeto > 225) {
		dx = -1;
	}
	if (xObjeto < 10) {
		dx = 1;
	}
}

class Obstaculo2 : public Obstaculo {
public:
	Obstaculo2();
	virtual void dibujar();
};

Obstaculo2::Obstaculo2() {
	xObjeto = rand() % (220 - 10 + 1) + 10;
	yObjeto = rand() % (50 - 10 + 1) + 10;
	dx = 1;
	dy = 1;
}

void Obstaculo2::dibujar() {
	textcolor(3);
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto);
		cout << (char)219;
	}
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto - 1);
		cout << (char)219;
	}
}



class Rana {
	
protected:
	int x;
	int y;
	
public:
	Rana();
	int getx(); // M�todo para obtener la posici�n xObjeto
	void dibujar();
	void mover(int i); // Correcci�n: el par�metro i debe ir aqu�
};

Rana::Rana() {
	
	x = 85; //130 en el monitor casa chimbas
	y = 41;    //60 casa chimbas
	
}

int Rana::getx() {
	return x;
}

void Rana::mover(int i) { // Correcci�n: El par�metro i debe ser declarado aqu�
	
	switch (i) { // Correcci�n: Cambiado de tecla a i
	case 1: //arriba
		y -= 1;
		break;
	case 2: //izquierda
		x -= 1;
		break;
	case 3: //derecha
		x += 1;
		break;
	case 4: //abajo
		y += 1;
		break;
		
	}
	
	
}

void Rana::dibujar() {
	
	textcolor(2);
	gotoxy(x, y);
	cout << (char)219;
	gotoxy(x + 1, y);
	cout << (char)219;
	gotoxy(x - 1, y);
	cout << (char)219;
	gotoxy(x, y - 1);
	cout << (char)219;
	gotoxy(x + 1, y - 1);
	cout << (char)219;
	gotoxy(x - 1, y - 1);
	cout << (char)219;
	gotoxy(x - 2, y + 1);
	cout << (char)254;
	gotoxy(x + 2, y + 1);
	cout << (char)254;
	gotoxy(x - 2, y - 2);
	cout << (char)254;
	gotoxy(x + 2, y - 2);
	cout << (char)254;
	
}


class Play {
public:
	Play() {};
	void jugar();
};

void Play::jugar() {
	
	Rana player;
	Obstaculo obst1;
	Obstaculo obst2;
	Obstaculo obst3;
	Obstaculo obst4;
	Obstaculo obst5;
	Obstaculo *obst6 = new Obstaculo2();
	
	
	player.dibujar();
	obst1.dibujar();
	obst2.dibujar();
	obst3.dibujar();
	obst4.dibujar();
	obst6->dibujar();
	
	int i = 0;
	bool finish = true;
	while (finish == true) {
		
		if (kbhit()) {
			int tecla = getch();
			
			switch (tecla) {
			case 72: //arriba
				i = 1;
				clrscr();
				player.mover(i);
				player.dibujar();
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst6->mover1();
				if(player.getx() == obst1.getXObjeto()){
					finish = false;
				}if(player.getx() == obst2.getXObjeto()){
					finish = false;
				}
				
				break;
			case 75: //izquierda
				i = 2;
				clrscr();
				player.mover(i);
				player.dibujar();
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst6->mover1();
				break;
			case 77: //derecha
				i = 3;
				clrscr();
				player.mover(i);
				player.dibujar();
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst6->mover1();
				break;
			case 80: //abajo
				i = 4;
				clrscr();
				player.mover(i);
				player.dibujar();
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst6->mover1();
				break;
				
			}
		}
	}
}


int main() {
	srand(time(NULL)); // Inicializar la semilla para generar n�meros aleatorios
	HWND hwnd = GetConsoleWindow(); // Obt�n el identificador de la ventana de la consola
	ShowWindow(hwnd, SW_SHOWMAXIMIZED); // Maximiza la ventana de la consola
	Play empezar;
	empezar.jugar();
}

