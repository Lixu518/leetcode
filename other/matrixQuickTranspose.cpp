#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#include <vector>
#include <cstring>
using namespace std;
/***
*
* Sparse matrix 
* Compressed storage
* Transpos(Ordinary transpose and fast transpose)
******************/

template<class T>
struct Triple
{
	size_t _row;
	size_t _col;
	T _value;
	Triple(){}
	Triple(size_t row, size_t col, T value)
	:_row(row)
	,_col(col)
	,_value(value)
	{}
};

template<class T>
class SparesMatrix
{
public:
	SparesMatrix();
	SparesMatrix(const T* array, size_t row, size_t col, const T& invalid);
	SparesMatrix<T> Transport();     
	SparesMatrix<T> FastTransport(); 
	void Display() const;
protected:
	vector<Triple<T> > _array;
	size_t _rowMatrix;
	size_t _colMatrix;
	T _invalid;
};


template<class T> 
SparesMatrix<T>::SparesMatrix(){}


template<class T>
SparesMatrix<T>::SparesMatrix(const T* array, size_t row, size_t col, const T& invalid)
	:_rowMatrix(row)
	,_colMatrix(col)
	,_invalid(invalid){
	for (size_t i = 0; i < _rowMatrix; i++){
		for (size_t j = 0; j < _colMatrix; j++){
			if (array[i * col + j] != invalid){
				_array.push_back(Triple<T>(i, j, array[i * col + j]));
			}
		}
	}
}


template<class T>
void SparesMatrix<T>::Display() const{
	size_t arr_size = _array.size();
	assert(arr_size != 0);	
	size_t index = 0;
	for (size_t i = 0; i < _rowMatrix; i++){
		for (size_t j = 0; j < _colMatrix; j++){
			if (index < arr_size && _array[index]._row == i && _array[index]._col == j){
				cout<<_array[index]._value<<"";
				index++;
			}else{
				cout<<_invalid<<"";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}


template<class T>
SparesMatrix<T> SparesMatrix<T>::Transport(){
	size_t arr_size = _array.size();
	assert(arr_size != 0);
	SparesMatrix<T> ret;
	ret._rowMatrix = _colMatrix;
	ret._colMatrix = _rowMatrix;
	ret._invalid = _invalid;
	ret._array.reserve(arr_size);
	for(size_t j = 0; j < _colMatrix; j++){
		size_t index = 0;
		while(index < arr_size){
			if (_array[index]._col == j){
				ret._array.push_back(Triple<T>(_array[index]._col, _array[index]._row, _array[index]._value));
			}
			index++;
		}
		if (arr_size == ret._array.size()){
			break;
		}
	}
    return ret;
}


template<class T>
SparesMatrix<T> SparesMatrix<T>::FastTransport(){
    size_t arr_size = _array.size();
    assert(arr_size > 0);
    size_t index = 0;
    SparesMatrix<T> ret;
    ret._rowMatrix = _colMatrix;
    ret._colMatrix = _rowMatrix;
    ret._invalid = _invalid;
    ret._array.resize(arr_size);
    int* RowCounts = new int[_colMatrix];
    int* RowStart = new int[_colMatrix];
    memset(RowCounts, 0, _colMatrix * sizeof(int));
    memset(RowStart, 0, _colMatrix * sizeof(int));
    for (size_t i = 0; i < arr_size; i++){
        RowCounts[_array[i]._col]++;
    }
    RowStart[0] = 0;
    for (size_t i = 1; i < _colMatrix; i++){
        RowStart[i] = RowStart[i - 1] + RowCounts[i - 1];
    }
    for (size_t i = 0; i< arr_size; i++){
        ret._array[RowStart[_array[i]._col]++] = Triple<T>(_array[i]._col, _array[i]._row, _array[i]._value);
    }
    delete[] RowCounts;
    delete[] RowStart;
    return ret;
}

void testSparseMatrix(){
    int array[6][5] = { {1, 0, 3, 0, 5 },
                        {0, 0, 0, 0, 0,},
                        {0, 0, 0, 0, 0,},
                        {1, 0, 3, 0, 5 },
                        {0, 0, 0, 0, 0,},
                        {0, 0, 0, 0, 0,},
                        };
    SparesMatrix<int> s1((int*)array, 6, 5, 0);
    s1.Display();
    clock_t start1, start2, end1, end2;
    SparesMatrix<int> s2;
    start1 = clock();
    s2 = s1.Transport();
    end1 = clock();
    cout<<"After transposition by column transpose: "<<endl;
    s2.Display();
    cout<<"Time: "<<(double)(end1 - start1)<<"ms"<<endl;
    SparesMatrix<int> s3;
    start2 = clock();
    s3 = s1.FastTransport();
    end2 = clock();
    cout<<"After transposition by Fast transpose: "<<endl;
    s3.Display();
    cout<<"Time: "<<(double)(end2 - start2)<<"ms"<<endl;
    }

int main(){
    testSparseMatrix();
    return 0;
}
