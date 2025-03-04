    #include <iostream>
    using namespace std;
    #define MIN(a,b) (((a)<(b)) ? a : b)
    int main ()
    {
        float i, j;
        i = 100.1;
        j = 100.01;
        cout <<"The minimum is " << MIN(i, j) << endl;
        return 0;
    }