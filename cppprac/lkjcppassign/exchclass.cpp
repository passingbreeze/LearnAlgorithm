#include <iostream>
#include <cstdio>

class Fahrenheit;
class Celcius {
     double Tem;
public:
     Celcius(): Tem(0.0) {}
     Celcius(double aTem) : Tem(aTem) { }
     operator Fahrenheit();
     double getceltem() const {
          return Tem;
     }
     void OutTem() {
          printf("섭씨=%f\n", Tem);
     }

};

class Fahrenheit {
     double Tem;
public:
     Fahrenheit(): Tem(0.0) { }
     Fahrenheit(double aTem) : Tem(aTem) {}
     operator Celcius();
     double getfahtem() const {
          return Tem;
     }
     void OutTem() {
          printf("화씨=%f\n", Tem);
     }

};


Celcius::operator Fahrenheit() // Cel -> Fah
{
     return Fahrenheit(getceltem() * 1.8 + 32);
}


Fahrenheit::operator Celcius() // Fah -> Cel
{
     return Celcius((getfahtem() - 32) / 1.8);
}

int main()
{
     Celcius C(100);
     Fahrenheit F = C;
     C.OutTem();
     F.OutTem();
     printf("\n");
     Fahrenheit F2 = 120;
     Celcius C2 = F2;
     F2.OutTem();
     C2.OutTem();
     return 0;
}
