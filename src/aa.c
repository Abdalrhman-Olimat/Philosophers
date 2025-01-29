#include "../includes/test.h"


// pthread_mutex_t mutex; 

// int y = 0;

// void *print_message(void *arg)
// {
// 	int x = *((int *)arg);
// 	pthread_mutex_lock(&mutex);
// 	printf("Thread: x = %d  started y = %d\n", x,y);
// 	for(int i = 0; i < 100; i++)
// 	{
// 		y++;		
// 	}
// 	printf("Thread: x = %d  finish y = %d\n", x,y);
// 	pthread_mutex_unlock(&mutex);
	
// 	return NULL;
// }

// int main(int ac, char **av)
// {
// 	int i = 0;
// 	(void ) ac;
// 	int *num_of_th=malloc(sizeof(atoi(av[1])));
// 	pthread_mutex_init(&mutex, NULL);
// 	pthread_t phlo[atoi(av[1])];


// 	while(i < atoi(av[1]))
// 	{
// 		num_of_th[i] = i;
// 		pthread_create(&phlo[i], NULL, print_message, &num_of_th[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while(i < atoi(av[1]))
// 	{
// 		pthread_join(phlo[i], NULL);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// }


// ////////////////////////////////////////returning value from thread//////////////////////////////////////////
// // #include <stdlib.h>
// // #include <stdio.h>
// // #include <pthread.h>
// // #include <time.h>

// // void* roll_dice() {
// //     int value = (rand() % 6) + 1;
// // 	int *result = malloc(sizeof(int));
// // 	*result = value;
// //     return (void*) result;
// // }

// // int main(int argc, char* argv[]) {
// //     int* res;
// //     srand(time(NULL));
// //     pthread_t th;
// //     if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
// //         return 1;
// //     }
// //     if (pthread_join(th, (void**) &res) != 0) {
// //         return 2;
// //     }
    
// //     printf("Result: %d\n", *res);
// //     free(res);
// //     return 0;
// // }


