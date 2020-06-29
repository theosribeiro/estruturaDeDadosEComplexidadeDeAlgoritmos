#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

struct vertex{
    int number;
    int weight;
};

int **AllocateMatrix(int rows, int columns)
{
    int **m = ( int** ) malloc ( rows * sizeof(int*) );

    for ( int i = 0; i < rows; i++)
    {
        m[i] = ( int* ) malloc ( columns * sizeof(int) );

        for ( int j = 0; j < columns; j++ )
        {
            m[i][j] = 0;
        }
    }

    return m;
}

void PrintMatrix( int **matrix, int size )
{
    cout << "Matriz Inicial: " << endl;

    for ( int i = 0; i < size; ++i )
    {
        for (int j = 0; j <= size-1 ; ++j )
        {
            if( i == j )
                matrix[i][j] = 0;

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout <<  endl;
}

int **reader( int** matrix, char url[], int *size )
{
    ifstream file(url);

    file >> *size;

    matrix = AllocateMatrix( *size, *size );

    int value;

    for ( int i = 0; i < *size-1; ++i )
    {
        for ( int j = i + 1; j < *size ; ++j )
        {
            file >> value;
            matrix[i][j] = value;
            matrix[j][i] = value;
        }
    }

    cout << "Size: " << *size << endl;
    PrintMatrix(matrix, *size);

    return matrix;
}

void PrintVector(struct vertex arr[], int size)
{
    cout << endl;
    for( int i = 0; i < size; i++ )
        cout << arr[i].number << " - " << arr[i].weight << endl;
    cout << endl;
}

void MinHeap(int dad, int size, struct vertex array[] )
{
    int i;
    int leftchild = 2*dad+1;
    int rightchild = 2*dad+2;

    if( (leftchild < size) && (array[leftchild].weight < array[dad].weight) )
        i = leftchild;
    else
        i = dad;

    if( (rightchild < size) && (array[rightchild].weight < array[dad].weight) )
        i = rightchild;

    if( dad != i )
    {
        swap(array[dad], array[i]);

        MinHeap( i, size, array );
    }
}

void BuildHeap( struct vertex arr[] , int size )
{
    for( int i = (size-1)/2; i >= 0; i-- )
        MinHeap(i, size-1, arr);
}

struct vertex ExtractMin( struct vertex arr[] , int* size )
{
    BuildHeap( arr, *size );

    struct vertex min = arr[0];

    arr[0] = arr[*size-1];

    *size -= 1;

    MinHeap( 0, *size, arr );

    return min;
}

bool Belongs(int id , struct vertex arr[] , int n )
{
  for(int i=0;i<n;i++)
  {
    if(id == arr[i].number)
        return true;
  }
  return false;
}

int ReturnWeight( int number, struct vertex arr[] , int size )
{
    for( int i = 0; i < size; ++i )
    {
        if(number == arr[i].number)
            return arr[i].weight;
    }
    return arr[number].weight;
}

void Decrease(struct vertex arr[] , int i, int key , int size )
{
    for( int j = 0; j < size; ++j )
    {
        if( i == arr[j].number )
        {
            i=j;
            break;
        }
    }

    arr[i].weight = key;

    BuildHeap( arr, size );
}

void Dijkstra( int** matrix, int size, int first )
{
    struct vertex adjvert[size];
    //int dad[size] = {-1};
    vector<int> dad(size);

    for( int i = 0; i < size; ++i )
    {
        adjvert[i].number = i;
        adjvert[i].weight = 2147483647;
    }

    adjvert[first].weight = 0;

    struct vertex Q[size];

    for( int i = 0; i < size; ++i )
        Q[i] = adjvert[i];

    BuildHeap( Q, size );

    int sizeaux = size;

    while( size > 0 )
    {
        struct vertex u = ExtractMin( Q, &size );

        adjvert[u.number] = u;

        for( int i = 0; i < sizeaux; i++ )
        {
            if( matrix[u.number][i] != 0 )
            {
                if( ( Belongs(i , Q , size) ) && ( matrix[u.number][i] + u.weight < ReturnWeight(i , Q , size) ) )
                {
                    dad[i] = u.number;
                    Decrease(Q , i , matrix[u.number][i] + u.weight , size);
                }
            }
        }
    }

    int soma=0;
    int soma2=0;

    for ( int i = 1; i < sizeaux; i++ )
    {
        for ( int j = i; j != 0; )
        {
            soma += matrix[j][dad[j]];
            //soma2 += matrix[j][dad[j]];
            j = dad[j];
        }

        cout << "Distancia de 0 ate " << i << ": " << soma << "\n";
        if(i==sizeaux-1){
            soma2 = soma;
        }
        soma = 0;
    }
    cout << "Soma: " << soma2 << "\n";

}

int main( )
{
    int **matrix;

    int size;

    matrix = reader(matrix, "dij10.txt", &size);

    Dijkstra( matrix, size, 0);

    return 0;
}
