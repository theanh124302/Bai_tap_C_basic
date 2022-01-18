/*Exercise•Define an array of integers, load from 1 to 100 in order to the array.
•Read a number from the standard input, perform the binary search for an array. Output "Not Found" if the array does not have it.
•When you perform the binary search, output the array index compared to the standard output.
Also, display the number of comparisons achieved until the target number is found.
Execise•Use recursive function for binary search operation
•Print out the number of function call of the Binary Search until the target number is found
•Compare it with the non recursive version.*/

#include <stdio.h>
#define NotFound (-1)
int sosanh=0, dequy=0;
typedef int ElementType;
int BinarySearch2(ElementType A[ ], ElementType X, int Low, int High ) { //dung de quy
    dequy++;
    if (Low > High){
        sosanh++;
        return NotFound;
    }
    else{
        sosanh++;
    }
    int Mid = ( Low + High ) / 2;
    if (A[ Mid ] < X ){
        sosanh++;
        return BinarySearch2(A, X, Mid+1, High);
    }
    else{
        sosanh++;
    }
    if (A[ Mid ] > X ){
        sosanh++;
        return BinarySearch2(A, X, Low, Mid-1);
    }
    else{
        sosanh++;
    }
    if (A[ Mid ] == X ){
        sosanh++;
        return Mid;
    }
    else{
        sosanh++;
    }
    return NotFound;
}





int main( )
{
    static int A[ ] = { 1, 3, 5, 7, 9, 13, 15 };
    int SizeofA = sizeof( A ) / sizeof( A[ 0 ] );
    int i=3;
    printf("Vi tri : %d\n",BinarySearch2( A, i,0, SizeofA-1 ));
    printf("So phep so sanh : %d\nSo lan de quy: %d\n",sosanh,dequy);
    return 0;
}
