#include <stdio.h>
#define NotFound (-1)
typedef int ElementType;
int BinarySearch(ElementType A[ ], ElementType X, int N ) { //khong dung de quy
    int Low, Mid, High;
    Low = 0; High = N - 1;
    while( Low <= High ) {
        Mid = ( Low + High ) / 2;
        if( A[ Mid ] < X )
            Low = Mid + 1;
        if( A[ Mid ] > X )
            High = Mid - 1;
        if( A[ Mid ] == X )
            return Mid;
    }
    return NotFound;
}

int BinarySearch2(ElementType A[ ], ElementType X, int Low, int High ) { //dung de quy
    if (Low > High) return NotFound;
    int Mid = ( Low + High ) / 2;
    if (A[ Mid ] < X )
        return BinarySearch2(A, X, Mid+1, High);
    if (A[ Mid ] > X )
        return BinarySearch2(A, X, Low, Mid-1);
    if (A[ Mid ] == X )
        return Mid;
    return NotFound;
}





main( )
{
    static int A[ ] = { 1, 3, 5, 7, 9, 13, 15 };
    int SizeofA = sizeof( A ) / sizeof( A[ 0 ] );
    int i;
    for( i = 0; i < 20; i++ )
        printf( "BinarySearch of %d returns %d\n",i, BinarySearch( A, i, SizeofA ) );
    for( i = 0; i < 20; i++ )
        printf( "BinarySearch of %d returns %d\n",i, BinarySearch2( A, i,0, SizeofA-1 ) );
    return 0;
}
