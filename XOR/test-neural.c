# include <stdio.h>
# include <stdlib.h>
# include <math.h>

#include "xor.h"

struct Network
{
	double *weightsHiden;
	double *weightsOutput;
	double *bias;
	int *input_value;
	double target;
	int inputValue1;
	int inputValue2;
	double *hidenValue;
	double step;
	double iteration;
	double learning_rate;
	double error_output;
	double *error_hidden;
	double output;
        

};

struct Network Initialise()
{
	struct Network net;
	net.weightsHiden = malloc(sizeof(double)*6);
	net.weightsOutput = malloc(sizeof(double)*3);
	net.input_value = malloc(sizeof(double)*8);
	net.bias = malloc(sizeof(double)*4);
	net.hidenValue = calloc(3, sizeof(double));
	net.error_hidden = malloc(sizeof(double)*3);
	net.iteration = 10000;
	net.learning_rate = 0.7;
	net.step = 2;
	net.output = 0;
	return(net);

}
// every possible cases;
void Initialise_values(struct Network *net)
{
		*((*net).input_value) = 0;
		*((*net).input_value + 1) = 0;
		*((*net).input_value + 2) = 0;
		*((*net).input_value + 3) = 1;
		*((*net).input_value + 4) = 1;
		*((*net).input_value + 5) = 0;
		*((*net).input_value + 6) = 1;
		*((*net).input_value + 7) = 1;
	
}

double cost_function(double target, double output)
{
	return (target -output)*(target - output);
}

double sigmoid(double x)
{
	return 1.0/(1.0+exp(-x));
}

double derivative_sigmoid(double x)
{
	return x*(1-x);
}
void randomize(struct Network *net)
{
	for(size_t i = 0; i < 6; i++)
	{
		(*((*net).weightsHiden + i)) = (double) rand() / (double) RAND_MAX; 
		
	}
	for(size_t i = 0; i < 3; i++)
	{
		(*((*net).weightsOutput + i)) = (double) rand() / (double) RAND_MAX;
		
	}
	for(size_t i = 0; i < 4; i++){
		(*((*net).bias + i)) = (double) rand() / (double) RAND_MAX;

	}
}

void forward_propagation(struct Network *net, int iteration)
{
	for (size_t i = 0; i < 3; ++i)
	{
		double sum_hidden = 0.0;
		
		sum_hidden += ((*net).inputValue1) * (*((*net).weightsHiden + i)) + (((*net).inputValue2) * (*((*net).weightsHiden + 3 + i)));
		*((*net).hidenValue + i) = sigmoid(sum_hidden + *((*net).bias + i));

	}
	if(iteration%100==0)
	{
	  printf("\n");
	  printf("|%d", (*net).inputValue1);
	  printf("|");
	  printf("%d|", (*net).inputValue2);
	}
	
	

	for(size_t ii = 0; ii <3; ii++)
		{
			(*net).output += (*((*net).hidenValue + ii))*(*((*net).weightsOutput + ii));
		}
	(*net).output = sigmoid((*net).output + *((*net).bias + 3));
	if(iteration%100== 0)
	{
	  printf("=> %f\n", (*net).output);
	  printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}

}
void back_propagation(struct Network *net)
{	
	(*net).error_output = ((*net).target - (*net).output)*derivative_sigmoid((*net).output);

	// WeightsOutput
	for(size_t i = 0; i < 3; i++)
	{
		(*((*net).weightsOutput + i)) += (*net).step * (*((*net).hidenValue + i)) * ((*net).error_output);
		
	}

	//WeightsHiden
	for(size_t ii = 0; ii <  3; ii++)
	{
		(*((*net).error_hidden + ii)) = ((*net).error_output * (*(*net).weightsOutput + ii)) * derivative_sigmoid(*((*net).hidenValue + ii)); 
		(*((*net).weightsHiden + ii)) += (*net).step * (*((*net).error_hidden + ii)) * (*net).inputValue1;
		(*((*net).weightsHiden + ii + 3)) += (*net).step * (*((*net).error_hidden + ii)) * (*net).inputValue2;
	}

}

void XOR(int x, int y)
{
	int iteration_final = 0;
	struct Network the_net = Initialise();

	double error_rate = 0;
	struct Network *net = &the_net;
	Initialise_values(net);
	randomize(net);

	(*net).inputValue1 = x;
	(*net).inputValue2 = y;
	
	if((x + y) == 1)
	{
		(*net).target = 1;
	}
	else
	{
		(*net).target = 0;
	}

	
	
	while(iteration_final <= 10000)
	{
	                forward_propagation(net,iteration_final);
			back_propagation(net);

			error_rate = fabs((*net).target - (*net).output);
			if(iteration_final %100 == 0)
			{
			  printf("Iteration number : \x1B[36m %u \x1B[0m\n", iteration_final);
			  printf("error_rate : \x1B[32m %f \x1B[0m", error_rate );
			  printf("\n");
			}
	
		       

			iteration_final+=1;

		
		
	}
}




