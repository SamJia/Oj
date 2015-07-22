#include <iostream>
#include <cstring>
using namespace std;

class Vector{
public:
    Vector(int n):size_(n){
        date_ = new int[n];
    };
	Vector(const Vector& vec){
		size_ = vec.size_;
		date_ = new int[size_];
		for (int i = 0; i < size_; ++i)
			date_[i] = vec.date_[i];
	}
    ~Vector(){
        delete[] date_;
    };
    friend istream &operator>>(istream &is, const Vector &vec);
    friend ostream &operator<<(ostream &os, const Vector &vec);
    Vector operator+(Vector &vec);
    Vector &operator=(const Vector &vec);
    friend double operator*(Vector &vec1, Vector &vec2);
private:
    int *date_;
    int size_;
};

istream &operator>>(istream &is, const Vector &vec){
    for(int i = 0; i < vec.size_; ++i)
        is >> vec.date_[i];
    return is;
}

ostream &operator<<(ostream &os, const Vector &vec){
    for(int i = 0; i < vec.size_; ++i)
        os << vec.date_[i] << ' ';
    os << '\n';
    return os;
}

Vector Vector::operator+(Vector &vec){
    Vector tmp(size_);
    for(int i = 0; i < size_; ++i)
        tmp.date_[i] = date_[i] + vec.date_[i];
    return tmp;
}

double operator*(Vector &vec1, Vector &vec2){
    double tmp = 0;
    for(int i = 0; i < vec1.size_; ++i)
        tmp +=(vec1.date_[i] * vec2.date_[i]);
    return tmp;
}

Vector &Vector::operator=(const Vector &vec){
    for(int i = 0 ; i < size_; ++i)
        date_[i] = vec.date_[i];
    return *this;
}

class Matrix{
public:
    Matrix(int length = 0, int height = 0) : length_(length), height_(height){
        date_ = new Vector *[height];
        for(int i = 0; i < height; ++i)
            date_[i] = new Vector(length);
    }
    Matrix(const Matrix &matrix){
        date_ = new Vector *[matrix.height_];
        for(int i = 0; i < matrix.height_; ++i){
            date_[i] = new Vector(matrix.length_);
            *(date_[i]) = *(matrix.date_[i]);
        }
    }
    ~Matrix(){
        for(int i = 0; i < height_; ++i)
            delete date_[i];
        delete[] date_;
    }
    friend Matrix operator+(const Matrix &matrix1, const Matrix &matrix2);
    friend istream &operator>>(istream &is, const Matrix &matrix);
    friend ostream &operator<<(ostream &os, const Matrix &matrix);
    Matrix &operator=(const Matrix &matrix);
private:
    Vector **date_;
    int length_, height_;
};

Matrix operator+(const Matrix &matrix1, const Matrix &matrix2){
    Matrix tmp(matrix1.length_, matrix1.height_);
    for(int i = 0; i < matrix1.height_; ++i)
        *(tmp.date_[i]) = *(matrix1.date_[i]) + *(matrix2.date_[i]);
    return tmp;
}

istream &operator>>(istream &is, const Matrix &matrix){
    for(int i = 0; i < matrix.height_; ++i)
        is >> *(matrix.date_[i]);
    return is;
}

ostream &operator<<(ostream &os, const Matrix &matrix){
    for(int i = 0; i < matrix.height_; ++i)
        os << *(matrix.date_[i]);
    return os;
}

Matrix & Matrix::operator=(const Matrix &matrix){
    for(int i = 0; i < height_; ++i)
        *(date_[i]) = *(matrix.date_[i]);
    return *this;
}

int main(){
    // Vector a(5), b(5), c(5);
    // cin >> a >> b;
    // c = a + b;
    // cout << c;
    Matrix a(3, 3), b(3, 3), c(3, 3);
    cin >> a >> b;
    c = a + b;
    cout << c;
}