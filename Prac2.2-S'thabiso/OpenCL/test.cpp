//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory

void test(__global int* matrixA, __global int* matrixB, __global int* output) //must correspond with the ones in multiplication.cpp
	{
	
	//TODO: program your kernel here

	int workitemNum = get_global_id(0);
	//in what workgroup?
	int workgroupNum = get_group_id(0);
	int Size= get_local_size(0);

	//create the memory buffers
	int* A1, A2;
	A1 = matrixA; A2 = matrixB;

	//using the code in the goldenStandard program,

	int sum = 0;
	for(int k = 0; k < Size; k++)
	{
		sum += A1[Size*workgroupNum + k] * A2[Size*k + workitemNum%Size];
	}

	//assign the output argument.
	output[workgroupNum*Size + workItemNum%Size] = sum;
	
	
}
