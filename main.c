#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h>
#include <string.h>
#include "drone_movement.h"
#include <pthread.h>
#include <stdio.h>

#define NUM_DRONES 20

pthread_mutex_t move_mutex = PTHREAD_MUTEX_INITIALIZER;

void *worker(void *idp) {
  int my_id = *((int *)idp);
  //pthread_mutex_unlock(&move_mutex);
  //double x_max=1280, y_max=800, x_min=0, y_min=0, xin=640, yini=400;
  /*int count=0;
  for (int i=1; i<NUM_DRONES+1; i++){
	if (count==0){
		move_towards(&xin, &yini, x_min, y_min);
		printf ("I'm thread %d, I'm going to (%.0f, %.0f) \n", my_id, x_min, y_min);
	}
	else if (count==1){
		move_towards(&xin, &yini, x_min, y_max);
		printf ("I'm thread %d, I'm going to (%.0f, %.0f) \n", my_id, x_min, y_max);
	}
	else if (count==2){
		move_towards(&xin, &yini, x_max, y_max);
		printf ("I'm thread %d, I'm going to (%.0f, %.0f) \n", my_id, x_max, y_max);
	}
	else if (count==3){
		move_towards(&xin, &yini, x_max, y_min);
		printf ("I'm thread %d, I'm going to (%.0f, %.0f) \n", my_id, x_max, y_min);
		count=-1;
	}
	count++;*/
	sleep(1);
	printf("I'm thread %d and I'm leaving\n", my_id);	
	//pthread_mutex_lock(&move_mutex);
	//}  
  pthread_exit(NULL);
  return NULL;
}

void cria_drones(){
	int id[NUM_DRONES], i;
	pthread_t threads[NUM_DRONES];
	if (pthread_create(&threads[0], NULL, worker, &id[0])!=0){
		perror ("ERROR CREATE THREAD DRONE!\n");
	}

	for (i=1; i<NUM_DRONES; i++){
		id[i]=i;
		if (pthread_create(&threads[i], NULL, worker, &id[i])!=0){
			perror ("ERROR CREATE THREAD DRONE!\n");
		}
	}
	for (i=0; i<NUM_DRONES; i++){
		pthread_join(threads[i], NULL);
	}
}

void cria_processo_central(){
	pid_t central;
	central= fork(); 
 	if (central!=0){
		printf("\nProcesso central criado...\n\n A criar thread drones...\n");
		cria_drones();
 	}
}

int main(){
  int comando, opcao;
  cria_processo_central();
  //while(1){
  		printf("\n------------Menu----------- \n [1]Movimentar o drone \n Opcao:");
  		do{
  			scanf("%d", &comando);
  		}while(comando!=1);
  		switch(comando){
  			case 1:
  				printf("[1] Deslocar drone para a base \n[2] Deslocar drone para armazem \n Opcao:");
  				scanf("%d", &opcao);
  		}

  	
 //} 
  return 0;
//  exit (0);
}