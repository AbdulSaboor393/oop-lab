#include <iostream>
using namespace std;

class Vector2D{
    protected:
    double x,y;
    public:
    Vector2D(double x1=0,double y1=0):x(x1),y(y1){}
    Vector2D operator+(Vector2D &other){
        return Vector2D(x+other.x,y+other.y);
    }
    Vector2D operator- (Vector2D &other)
    {
        return Vector2D(x-other.x,y-other.y);
    }
    Vector2D operator*(double scalar){
        return Vector2D(x*scalar,y*scalar);
    }
    friend double dotprod(Vector2D &v1, Vector2D &v2);

    friend ostream &operator <<(ostream &out, Vector2D &v){
        out<<"("<<v.x<<","<<v.y<<")";
        return out;
    }
};

double dotprod(Vector2D &v1, Vector2D &v2){
    return v1.x*v2.x + v1.y*v2.y;
}

int main (){
    Vector2D a(1,2);
    Vector2D b(4,5);

    Vector2D sum = a+b;
    Vector2D diff  = a-b;
    Vector2D scalar  = a*4.7;
    double dot  = dotprod(a,b);
    cout << "Vector A: " << a << endl;
    cout << "Vector B: " << b << endl;
    cout << "A + B: " << sum << endl;
    cout << "A - B: " << diff << endl;
    cout << "A * 4.7: " << scalar << endl;
    cout << "Dot Product of A and B: " << dot << endl;

    return 0;

}
