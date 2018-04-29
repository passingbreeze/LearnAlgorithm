#include <iostream>
#include <cmath>

using namespace std;

class EUR;//필수 선언
class USD {
  int dollars;
  float cents; // 0.0<=cent<100
public:
  USD() : dollars(0), cents(0.0) {}
  USD(int _d, float _c) : dollars(_d), cents(_c) {
    if (_c < 0.0) {
      cerr << "So much less cents.\n";
    }

    else if (_c > 100.0) {
      cerr << "So much cents.\n";
    }
  }

  int getdollars() const {
    return dollars;
  }

  float getusdcents() const {
    return cents;
  }

  USD& operator=(const EUR&);

  friend USD operator+(const USD& a, const USD& b) {
    USD sum;

    sum.dollars = a.dollars + b.dollars;
    sum.cents = a.cents + b.cents;

    return sum;
  }

  friend USD operator-(const USD& a, const USD& b) {
    USD sub;

    sub.dollars = a.dollars - b.dollars;
    sub.cents = a.cents - b.cents;

    if (sub.dollars < 0 || sub.cents < 0.0) {
      sub.dollars = -(sub.dollars);
      sub.cents = -(sub.cents);
    }

    return sub;
  }

  friend ostream& operator<<(ostream& os, const USD& a) {
    os << "USD : " << a.dollars + a.cents;
    return os;
  }
};

class EUR {
  int euros;
  float cents; // 0.0<=cent<100
public:
  EUR() : euros(0), cents(0.0) {}
  EUR(int _d, float _c) : euros(_d), cents(_c) {
    if (_c < 0.0) {
      cerr << "So much less cents.\n";
    }

    else if (_c > 100.0) {
      cerr << "So much cents.\n";
    }
  }
  EUR(const USD& u) {
    float fleuros = 0.0;
    float subeurcents = 0.0;

    euros = (100.0 / 81.0) * u.getdollars();
    fleuros = ((100.0 / 81.0) * u.getdollars());
    subeurcents = fleuros - (float)euros;
    cents = (100.0 / 81.0) * u.getusdcents() + subeurcents;
    while (cents >= 100.0) {
      cents -= 100.0;
      euros += 1;
    }
  }

  int geteuros() const {
    return euros;
  }

  float geteurcents() const {
    return cents;
  }

  friend EUR operator+(const EUR& a, const EUR& b) {
    EUR sum;

    sum.euros = a.euros + b.euros;
    sum.cents = a.cents + b.cents;

    return sum;
  }

  friend EUR operator-(const EUR& a, const EUR& b) {
    EUR sub;
    sub.euros = a.euros - b.euros;
    sub.cents = a.cents - b.cents;

    if (sub.euros < 0 || sub.cents < 0.0) {
      sub.euros = -(sub.euros);
      sub.cents = -(sub.cents);
    }

    return sub;
  }

  friend ostream& operator<<(ostream& os, const EUR& a) {
    os << "EUR : " << a.euros + a.cents;
    return os;
  }
};

USD& USD::operator=(const EUR& e) // EUR -> USD
{
  dollars = (int)((float)(0.81) * e.geteuros());
  cents = (float)((float)(0.81) * e.geteurcents());
  while (cents >= 100.0) {
    cents -= 100.0;
    dollars += 1;
  }
  return *this;
} // EUR+EUR -> USD

int main()
{
  EUR  myMoneyEuro;
  USD  myMoneyUSD;

  myMoneyUSD = EUR(10, 20.0) + USD(20, 20.0);
  myMoneyEuro = USD(100, 30.0) + EUR(300, 20.0);

  cout << myMoneyUSD << endl;
  cout << myMoneyEuro << endl;

  myMoneyUSD = EUR(1, 0.0) - USD(1, 0.0);
  myMoneyEuro = USD(1, 30.0) - EUR(300, 20.0);

  cout << myMoneyUSD << endl;
  cout << myMoneyEuro << endl;
  return 0;
}
