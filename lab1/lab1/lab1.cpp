#include <iostream>
using namespace std;
template <class T>
class Matrix {
protected:
    int a;
    int b;
    T** matr;
public:
    Matrix() : a(0), b(0), matr(nullptr) {}
    Matrix(int a, int b) : a(a), b(b) {
        matr = new int* [a];
        for (int i = 0; i < a; i++) {
            matr[i] = new int[b];
        }
    }
    Matrix(const Matrix& p) : a(p.a), b(p.b) {
        matr = new int* [p.a];
        for (int i = 0; i < p.a; i++) {
            matr[i] = new int[p.b];
        }
        for (int i = 0; i < p.a; i++) {
            for (int j = 0; j < p.b; j++) {
                matr[i][j] = p.matr[i][j];
            }
        }
    }
    ~Matrix() {
        if (matr != nullptr) {
            for (int i = 0; i < a; i++) {
                delete[] matr[i];
            }
            delete[] matr;
        }
        matr = nullptr;
    }
    int geta()
    {
        return a;
    }
    int getb()
    {
        return b;
    }
    void seta(int x)
    {
        a = x;
    }
    void setb(int x)
    {
        b = x;
    }
    void Cin();
    virtual void Cout();
    int getEl(int x, int y) {
        return matr[y][x];
    }
    int* operator [] (int i) { return matr[i]; };
    friend Matrix<T> operator *(int k, Matrix& m) {
        Matrix<T> tmp(m);

        for (int i = 0; i < m.a; i++) {
            for (int j = 0; j < m.b; j++) {

                tmp[i][j] *= k;
            }
        }
        return Matrix<T>(tmp);

    };
    friend Matrix operator + (int k, Matrix& m) {
        Matrix<T> tmp(m);
        for (int i = 0; i < m.a; i++) {
            for (int j = 0; j < m.b; j++) {

                tmp[i][j] += k;
            }
        }
        return tmp;
    };
    friend Matrix operator - (Matrix& m, int k) {
        Matrix<T> tmp(m);
        for (int i = 0; i < m.a; i++)
            for (int j = 0; j < m.b; j++)

                tmp[i][j] -= k;
        return tmp;
    };
    friend istream& operator>><T>(istream&, Matrix&);
    friend ostream& operator<<<T>(ostream&, Matrix&);
    Matrix& operator = (const Matrix& d);
};
template<class T>
istream& operator>>(istream& s, Matrix<T>& p)
{
    cout << "enter matrix\n";
    for (int i = 0; i < p.a; i++) {
        for (int j = 0; j < p.b; j++) {
            s >> p[i][j];
        }
    }

    return s;
}
template<class T>
ostream& operator<<(ostream& s, Matrix<T>& p)
{
    for (int i = 0; i < p.a; i++) {
        for (int j = 0; j < p.b; j++) {
            s << p[i][j] << " ";
        }
        s << endl;
    }

    return s;
}
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& p)
{
    matr = new int* [p.a];
    for (int i = 0; i < p.a; i++) {
        matr[i] = new int[p.b];
    }
    for (int i = 0; i < p.a; i++) {
        for (int j = 0; j < p.b; j++) {
            matr[i][j] = p.matr[i][j];
        }
    }
    return *this;
}


template<class T>
void Matrix<T>::Cin() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            matr[i][j] = rand() % 10;
        }
    }

}
template<class T>
void Matrix<T>::Cout() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << matr[i][j] << " ";

        }
        cout << endl;
    }
}
template<class T>
class subMatrix : public Matrix<T> {
protected:
    int x1;
    int y1;
    int x2;
    int y2;
public:

    subMatrix() {

    }
    void setx1(int x)
    {
        x1 = x;
    }
    void setx2(int x)
    {
        x2 = x;
    }
    void sety1(int x)
    {
        y1 = x;
    }
    void sety2(int x)
    {
        y2 = x;
    }
    subMatrix<T>(int x1, int y1, int x2, int y2) : x1(x1), x2(x2), y1(y1), y2(y2)
    {
        this->matr = new T * [abs(x2 - x1)];
        for (int i = 0; i < abs(x2 - x1); i++) {
            this->matr[i] = new T[abs(y2 - y1)];
        }
        for (int i = 0; i < abs(x2 - x1); i++) {
            for (int j = 0; j < abs(y2 - y1); j++) {
                this->matr[i][j] = rand() % 10;
            }
        }
    }

    void Cout()
    {
        for (int i = 0; i < abs(x2 - x1); i++) {
            for (int j = 0; j < abs(y2 - y1); j++) {
                cout << this->matr[i][j] << " ";
            }
            cout << endl;
        }
    }

};





int main()
{
    srand(time(0));
    int a, b, k = 5;
    cin >> a >> b;
    Matrix<int> matr1(a, b);
    Matrix<int> matr4;
    cin >> matr1;
    cout << matr1;
    matr4 = matr1;
    matr1 = k * matr1;
    matr1.Cout();
    matr1 = matr1 - k;
    matr1.Cout();
    matr4.Cout();
    int x, y;
    cin >> x >> y;
    cout << matr1.getEl(x, y) << endl;
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    subMatrix<int> matr5(x1, y1, x1, y2);
    matr5.Cout();
}
