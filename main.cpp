#include<iostream>
#include <ctime>
#include <conio2.h>
#include <cstdio>
#include <windows.h>

using namespace std;

class pantalla {
private:
	int xpositionBordes;
	int ypositionBordes;
	int xpositionMeta;
	int ypositionMeta;
	int xpositionInicio;
	int ypositionInicio;
	
public:	
	pantalla();
	void dibujar();
};

pantalla::pantalla(){
	xpositionBordes = 40;
	ypositionBordes = 1;
	xpositionMeta = 40;
	ypositionMeta = 1;
	xpositionInicio = 40;
    ypositionInicio = 63;
}

void pantalla::dibujar() {
	textcolor(8);
	
	//borde izquierdo
	for (int i = 1; i < 65; i++) {
		gotoxy(xpositionBordes, ypositionBordes + i);
		cout << (char)219;
	}
	for (int i = 1; i < 65; i++) {
		gotoxy(xpositionBordes + 1 , ypositionBordes + i);
		cout << (char)219;
	}
	
	//borde derecho
	for (int i = 1; i < 65; i++) {
		gotoxy(xpositionBordes + 155, ypositionBordes + i);
		cout << (char)219;
	}
	for (int i = 1; i < 65; i++) {
		gotoxy(xpositionBordes + 156 , ypositionBordes + i);
		cout << (char)219;
	}
	
	//borde inferior
	for (int i = 1; i < 155; i++) {
		gotoxy(xpositionInicio + i, ypositionInicio + 1);
		cout << (char)219;
	}
	for (int i = 1; i < 155; i++) {
		gotoxy(xpositionInicio + i, ypositionInicio + 2);
		cout << (char)219;
	}
	
	//meta
	for (int i = 1; i < 155; i++) {
		if(i % 2 == 0){
		gotoxy(xpositionMeta + i, ypositionMeta + 1);
		cout << (char)219;
	}
	}
	for (int i = 1; i < 155; i++) {
		if(i % 2 == 1){
		gotoxy(xpositionMeta + i, ypositionMeta + 2);
		cout << (char)219;
	}
	}
	for (int i = 1; i < 155; i++) {
		if(i % 2 == 0){
			gotoxy(xpositionMeta + i, ypositionMeta + 3);
			cout << (char)219;
		}
	}
	
	
}

class Obstaculo {
protected:
	int yObjeto;
	int dy;
	int dx;
	int xObjeto;
	
public:
	Obstaculo();
	int getXObjeto();
	int getYObjeto();
	virtual void chckBordes();
	virtual void dibujar();
	virtual void mover1();
	virtual void borrar();
};

Obstaculo::Obstaculo() {
	xObjeto = rand() % (140 - 10 + 1) + 45;
	yObjeto = rand() % (55 - 10 + 1) + 10;
	dx = 1;
	dy = 1;
}

int Obstaculo::getXObjeto() {
	return xObjeto;
}

int Obstaculo::getYObjeto() {
	return yObjeto;
}

void Obstaculo::mover1() {
	borrar();
	chckBordes();
	
	if (dx == 1) {
		xObjeto += 3;
	}
	if (dx == -1) {
		xObjeto -= 3;
	}
	dibujar();
}

void Obstaculo::dibujar() {
	textcolor(3);
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto);
		cout << (char)219;
	}
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto - 1);
		cout << (char)219;
	}
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto - 2);
		cout << (char)219;
	}
}

void Obstaculo::borrar(){
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto);
		cout<<" ";
	}
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto - 1);
		cout<<" ";
	}
	for (int i = 1; i < 20; i++) {
		gotoxy(xObjeto + i, yObjeto - 2);
		cout<<" ";
	}
}

void Obstaculo::chckBordes() {
	if (xObjeto > 172) {
		dx = -1;
	}
	if (xObjeto < 45) {
		dx = 1;
	}
}

class Obstaculo2 : public Obstaculo {
public:
	Obstaculo2();
	int getXObjeto();
	int getYObjeto();
	virtual void chckBordes();
	virtual void dibujar();
	virtual void borrar();
};

Obstaculo2::Obstaculo2() {
	xObjeto = rand() % (120 - 10 + 1) + 45;
	yObjeto = rand() % (55 - 10 + 1) + 10;
	dx = 1;
	dy = 1;
}

int Obstaculo2::getXObjeto() {
	return xObjeto;
}

int Obstaculo2::getYObjeto() {
	return yObjeto;
}

void Obstaculo2::dibujar() {
	textcolor(3);
	for (int i = 1; i < 30; i++) {
		gotoxy(xObjeto + i, yObjeto);
		cout << (char)219;
	}
	for (int i = 1; i < 30; i++) {
		gotoxy(xObjeto + i, yObjeto - 1);
		cout << (char)219;
	}
	for (int i = 1; i < 30; i++) {
		gotoxy(xObjeto + i, yObjeto - 2);
		cout << (char)219;
	}
	
	
}

void Obstaculo2::borrar(){
	for (int i = 1; i < 30; i++) {
		gotoxy(xObjeto + i, yObjeto);
		cout<<" ";
	}
	for (int i = 1; i < 30; i++) {
		gotoxy(xObjeto + i, yObjeto - 1);
		cout<<" ";
	}
	for (int i = 1; i < 30; i++) {
		gotoxy(xObjeto + i, yObjeto - 2);
		cout<<" ";
	}
}

void Obstaculo2::chckBordes() {
	if (xObjeto > 160) {
		dx = -1;
	}
	if (xObjeto < 45) {
		dx = 1;
	}
}



class Rana {
	
protected:
	int x;
	int y;
	
public:
	Rana();
	int getx();
	int gety();
	void dibujar();
	void mover(int i); 
	void borrar();
};

Rana::Rana() {
	
	x = 110; 
	y = 60;
	
}

int Rana::getx() {
	return x;
}
int Rana::gety() {
	return y;
}

void Rana::mover(int i) {
	
	borrar();
	switch (i) {
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
	
	dibujar();
	
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

void Rana::borrar() {
	gotoxy(x,y);
	cout<<" ";
	gotoxy(x+1,y);
	cout<<" ";
	gotoxy(x-1,y);
	cout<<" ";
	gotoxy(x,y-1);
	cout<<" ";
	gotoxy(x+1,y-1);
	cout<<" ";
	gotoxy(x-1,y-1);
	cout<<" ";
	gotoxy(x-2,y+1);
	cout<<" ";
	gotoxy(x+2,y+1);
	cout<<" ";
	gotoxy(x-2,y-2);
	cout<<" ";
	gotoxy(x+2,y-2);
	cout<<" ";
}


class Play {
private:
	int contadorPuntos;
public:
	Play() {contadorPuntos = 0;};
	void jugar();
};

void Play::jugar() {
	int i = 0;
	textcolor(4);
	cout << "puntaje: ";
	cout<<endl << "teclas para jugar : w";
	cout<<endl << "                  a s d";
	
	Rana player;
	pantalla pantalla;
	Obstaculo obst1;
	Obstaculo obst2;
	Obstaculo obst3;
	Obstaculo obst4;
	Obstaculo obst5;
	Obstaculo *obst6 = new Obstaculo2();
	Obstaculo *obst7 = new Obstaculo2();
	Obstaculo *obst8 = new Obstaculo2();
	
	pantalla.dibujar();//los bordes y la meta se dibujan 1 sola vez
	//se dibujan los objetos 1 vez aca para que aparezcan sin la necesidad de apretar w,a,s,d
	player.dibujar();
	obst1.dibujar();
	obst2.dibujar();
	obst3.dibujar();
	obst4.dibujar();
	obst5.mover1();
	obst6->dibujar();
	obst7->dibujar();
	obst8->dibujar();

	
	
	bool juegoTerminado = false;
	
	while (!juegoTerminado) {
		gotoxy(10, 1);
		textcolor(6);
		cout <<contadorPuntos;
		if (kbhit()) {
			int tecla = getch();
			
			switch (tecla) {
			case 'w': //arriba
				i = 1;
				player.mover(i);
				player.dibujar();
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst5.mover1();
				obst6->mover1();
				obst7->mover1();
				obst8->mover1();
				contadorPuntos++;
				
				break;
			case 'a': //izquierda
				i = 2;
				player.mover(i);
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst5.mover1();
				obst6->mover1();
				obst7->mover1();
				obst8->mover1();
				break;
			case 'd': //derecha
				i = 3;
				player.mover(i);
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst5.mover1();
				obst6->mover1();
				obst7->mover1();
				obst8->mover1();
				break;
			case 's': //abajo
				i = 4;
				player.mover(i);
				obst1.mover1();
				obst2.mover1();
				obst3.mover1();
				obst4.mover1();
				obst5.mover1();
				obst6->mover1();
				obst7->mover1();
				obst8->mover1();
				break;
				
			}
		}
		
		// Verificar si la rana choca contra un obstáculo
		if ((player.getx() >= obst1.getXObjeto() && player.getx() <= obst1.getXObjeto() + 19 && player.gety() >= obst1.getYObjeto() - 2 && player.gety() <= obst1.getYObjeto()) ||      // intente hacerlo por mi cuenta pero 
			(player.getx() >= obst2.getXObjeto() && player.getx() <= obst2.getXObjeto() + 19 && player.gety() >= obst2.getYObjeto() - 2 && player.gety() <= obst2.getYObjeto()) ||		//por algun motivo no era consistente y 
			(player.getx() >= obst3.getXObjeto() && player.getx() <= obst3.getXObjeto() + 19 && player.gety() >= obst3.getYObjeto() - 2 && player.gety() <= obst3.getYObjeto()) ||		//el programa finalizaba cuando no debia
			(player.getx() >= obst4.getXObjeto() && player.getx() <= obst4.getXObjeto() + 19 && player.gety() >= obst4.getYObjeto() - 2 && player.gety() <= obst4.getYObjeto()) ||		//por lo tanto le pedi ayuda a chatGPT
			(player.getx() >= obst5.getXObjeto() && player.getx() <= obst5.getXObjeto() + 19 && player.gety() >= obst5.getYObjeto() - 2 && player.gety() <= obst5.getYObjeto()) ||		//
			(player.getx() >= obst6->getXObjeto() && player.getx() <= obst6->getXObjeto() + 29 && player.gety() >= obst6->getYObjeto() - 2 && player.gety() <= obst6->getYObjeto()) ||  //
			(player.getx() >= obst7->getXObjeto() && player.getx() <= obst7->getXObjeto() + 29 && player.gety() >= obst7->getYObjeto() - 2 && player.gety() <= obst7->getYObjeto()) ||  //
			(player.getx() >= obst8->getXObjeto() && player.getx() <= obst8->getXObjeto() + 29 && player.gety() >= obst8->getYObjeto() - 2 && player.gety() <= obst8->getYObjeto()) ||  //
			(player.gety() == 4)) { //esta linea es para finalizar cuando llegue la rana a la meta																						//exceptuando esta linea
			juegoTerminado = true;
			break;
		}
	}
}


int main() {
	srand(time(NULL));
	HWND hwnd = GetConsoleWindow(); // Obtén el identificador de la ventana de la consola
	ShowWindow(hwnd, SW_SHOWMAXIMIZED); // Maximiza la ventana de la consola
	Play empezar;
	empezar.jugar();
}

