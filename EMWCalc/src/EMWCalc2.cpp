#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <unistd.h>


#include "Map.h"


#define SIZE 400
#define TIME 100
#define SHMSZ     SIZE*SIZE
#define Ez(I, J) ez[(I)*SIZE + (J)]
#define Hx(I, J) hx[(I)*SIZE + (J)]
#define Hy(I, J) hy[(I)*SIZE + (J)]




double grid[SIZE*SIZE] = {0};

double fin_time = 2000;

// Variables de la simulación
double Cdtds = 1.0 / sqrt(2.0);
double imp0 = 377.0f;
//Campos
double ez_[SIZE*SIZE] = {0};
double hx_[SIZE*SIZE] = {0};
double hy_[SIZE*SIZE] = {0};

double Chxh = 1.0;
double Chxe = Cdtds/imp0;
double Chyh = 1.0;
double Chye = Cdtds/imp0;
double Ceze = 1.0;
double Cezh = Cdtds*imp0;


void Update2D(double *ez, double *hx, double *hy){

	for(int mm = 0; mm < SIZE; mm++){
		for(int nn = 0; nn < SIZE-1; nn++){
			Hx(mm,nn) = Chxh*Hx(mm,nn) -
					Chxe * ( Ez(mm, nn+1) - Ez(mm, nn));
		}
	}

	for(int mm = 0; mm < SIZE-1; mm++){
		for(int nn = 0; nn < SIZE; nn++){
					Hy(mm,nn) = Chyh*Hy(mm,nn)+Chye*( Ez( mm + 1 , nn) - Ez(mm, nn) );
				}
	}
	for(int mm = 0; mm < SIZE-1; mm++){
			for(int nn = 0; nn < SIZE-1; nn++){
				Ez(mm,nn) = Ceze*Ez(mm,nn)+
						Cezh * ( (Hy(mm,nn) - Hy(mm-1,nn))-
								(Hx(mm,nn)-Hx(mm,nn-1)));
			}
		}
}



Map* Jread;


int main(){

	Jread = new Map();
	Jread->ReadJSON("world.json");

	int shmid;
	key_t key;
	double *shm;

	int Time = 0;
	double *ez = ez_;
	key = 5678;

	if ((shmid = shmget(key, SHMSZ*sizeof(double), 0666)) < 0) {
	        perror("shmget");
	        exit(1);
	    }

	if ((shm =(double*) shmat(shmid, NULL, 0)) == (double *) -1) {
	        perror("shmat");
	        exit(1);
	    }


	/* solid struct */
	int Cx = 50;
	int Cy = 200;
	int p = 40;
	int valor_metal=0;

	for(Time = 0; Time < fin_time; Time++){

		/*for(int i = 0; i < 100; i++){
			Ez(Cx-p+i,int(round(Cy+2*sqrt(p*i))))=valor_metal;
			Ez(Cx-p+i,int(round(Cy-2*sqrt(p*i))))=valor_metal;
			for(int j = 2*sqrt(p*(i)); j <= 2*(sqrt(p*(i+1))); j++){
				Ez( Cx-p+int(round((j*j)/(4*p))),  Cy+j) = valor_metal;
				Ez( Cx-p+int(round((j*j)/(4*p))),  Cy-j) = valor_metal;
			}
*/
		Jread->ModifyMap(ez);
			/*Ez(Cx-p+i+1,int(round(Cy-2*sqrt(p*i))))=valor_metal;
			Ez(Cx-p+i+1,int(round(Cy+2*sqrt(p*i))))=valor_metal;
			for(int j = 0; j <= ceil(2*(sqrt(p*(i+1))-sqrt(p*(i)))); j++){
					Ez( Cx-p+1+int(round((j*j)/(4*p))),  Cy+j) = valor_metal;
					Ez( Cx-p+1+int(round((j*j)/(4*p))), -(Cy+j)) = valor_metal;
			}
			Ez(Cx-p+i-1,int(round(Cy-2*sqrt(p*i))))=valor_metal;
			Ez(Cx-p+i-1,int(round(Cy+2*sqrt(p*i))))=valor_metal;*/
		//}

		/*if(Time==0){
			for( int i = 0; i < SIZE*SIZE ; i++){
				printf("%.0f ",ez_[i]);
			}
			fflush(stdout);
		}*/
		/*
		for(int i = 0; i < 200; i++){
			for (int j = 0; j < 100; j++){
				Ez(50+i,	150	) = 0;
				Ez(50 , 	150+j) = 0;
				//Ez(250 , 	150+j) = 0;
				Ez(50+i,	250	) = 0;
			}

		}*/

		Update2D(ez_,hx_, hy_);
		//Ez(SIZE/2, SIZE/2) += 10*sin(Time);
		//Ez(SIZE/2, SIZE/2) += 10*exp(-(Time - 30.0) *(Time - 30.0) / 50.0);
		Ez(Cx, Cy) += 10*exp(-(Time - 30.0) *(Time - 30.0) / 50.0);
		//Ez(100, 200) += 10*sin(Cdtds/10*Time);
		//printf("Time: %i\n", Time);

		//printf("new\n\n");

		usleep(40000);
		//getchar();

		memcpy(shm, ez_, SIZE*SIZE*sizeof(double));

	}
	return 0;

}
