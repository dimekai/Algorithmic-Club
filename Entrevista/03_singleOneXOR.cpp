/*
@date:		October 17th, 2018.
@author:	Jesús Díaz
@problem:	Given an array of integers, every element 
            appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. 
      Could you implement it without using extra memory?
			
@topic:		Manipulation of Bits.

HINT
    A xor A = 0
    A xor 0 = A
*/
int Solution::singleNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int unique = A[0]; /*Inicializo el que será unico con el principio del vector*/
    for( int i = 1; i < A.size() ; i++) 
        unique ^= A[i];                 // Voy haciendo XOR de cada uno de los elementos del vector
        
    return unique;
}
