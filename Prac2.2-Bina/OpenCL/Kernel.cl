
//TODO: set your arguments for the kernel. 

__kernel void matrixMultiplication(__global int* matrixA, __global int* matrixB, __global int* output){
	
	//TODO: program your kernel here

	
	int workItemNum = get_global_id(0); //same as prac 2.1
	int workGroupNum = get_group_id(0);
	int size = get_local_size(0);
	//int localGroupID = get_local_id(0); //Work items ID within each work group
	
	//from memory buffers
	int* argument1 = matrixA;  
	int* argument2 = matrixB;

	//Multiplying 2 matrices as a single unit of execution
	int total = 0;

	for (int i = 0; i < size; i++)
	{
		total += argument1[size*workGroupNum+i] * argument2[size*i + workItemNum%size];
	}

	output[workGroupNum*size + workItemNum%size] = total;

	
}




