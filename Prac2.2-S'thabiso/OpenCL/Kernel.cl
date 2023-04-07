
//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory

__kernel void matrixMultiplication(__global int* matrixA, __global int* matrixB, __global int* output)
{	
	//TODO: program your kernel here
	
	int workItemNum = get_global_id(0);
	int workGroupNum = get_group_id(0);
	int size = get_local_size(0);

	//initialize memory buffers below
	int* argument1 = matrixA;
	int* argument2 = matrixB;

	//the actual multiplication
	int total = 0;

	for (int i = 0; i < size; i++)
	{
		total += argument1[size*workGroupNum+i] * argument2[size*i + workItemNum%size];
	}

	output[workGroupNum*size + workItemNum%size] = total;
}




