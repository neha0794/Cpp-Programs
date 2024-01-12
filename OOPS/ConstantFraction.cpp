class Fraction{
    private:
    int numerator;
    int denominator;
    
    public:
    Fraction (){

    }
    Fraction(int numerator,int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
}

int  getNumerator() const{
    return numerator;
}

int  getDenominator() const{
  return denominator;
}
void setNumerator(int n){
    numerator = n;
}
void setrollno(int d){
    denominator = d;
}
void print(){
    cout << numerator << "" << denominator <<endl;

}
void simplify() {
    int gcd = 1;
    int j = min(this-> numerator , this-> denominator);
    for(int i=1; i<=j; i++) {
        if (numerator % i == 0 && denominator % i == 0){
            gcd = i;
        }
this-> numerator = numerator/gcd;
this-> denominator = denominator/gcd;
    }
}
void add(Fraction const &f2) {
int lcm = numerator * (f2.denominator);
int x = lcm / denominator;
int y = lcm / (f2.denominator);
int num = (x*numerator) + (y*f2.numerator);

int numerator = num;
int denominator = lcm;
simplify();

}
};