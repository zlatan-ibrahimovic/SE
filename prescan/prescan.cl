
__kernel void prescan(__global int *A,
		      __global int *B,
		       int n)
{
  __local int temp[10];

  int tid = get_local_size(0);
  int offset =1;
 
  B[offset] = 2 *A[offset];
  temp[2*tid+1] = A[2*tid+1];
  for (int d = n>>1; d > 0; d >>= 1) // build sum in place up the tree
  {  
  barrier(CLK_GLOBAL_MEM_FENCE);
  if (tid < d)
  {
  int ai = offset*(2*tid+1)-1;
  int bi = offset*(2*tid+2)-1;
  temp[bi] += temp[ai];
  }
  offset *= 2;	
  }

  if (tid == 0) { temp[n - 1] = 0; } // clear the last element
  for (int d = 1; d < n; d *= 2) // traverse   down tree & build scan
  {
  offset >>= 1;
  barrier(CLK_GLOBAL_MEM_FENCE);
  if (tid < d)
   {
  int ai = offset*(2*tid+1)-1;
  int bi = offset*(2*tid+2)-1;

  int t= temp[ai];
  temp[ai] = temp[bi];
  temp[bi] += t;
  }
  }
  barrier(CLK_GLOBAL_MEM_FENCE);
  B[2*tid] = temp[2*tid]; // write results to device memory
  B[2*tid+1] = temp[2*tid+1];


}
