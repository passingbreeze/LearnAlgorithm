#include <iostream>

using namespace std;

class USD {
  int dollars;
  float cents; // 0.0<=cent<100

public:
  USD() : dollars(0), cents(0.0) {}
  USD(int _d, float _c) : dollars(_d), cents(_c) {
    if (_c < 0.0) {
      cout << "So much less cents." << endl;
      cents = 0.0;
    }

    else if (_c > 100.0) {
      cout << "So much cents." << endl;
      dollars++;
    }
  }


  friend USD operator+(const USD& a, const USD& b) {

    USD result;

    result.dollars = a.dollars + b.dollars;
    result.cents = a.cents + b.cents;

    return result;
  }

  friend ostream& operator<<(ostream& os, const USD& a) {
    os << a.dollars << ' ' << a.cents << endl;
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
      cout << "So much less cents." << endl;
      cents = 0.0;
    }

    else if (_c > 100.0) {
      cout << "So much cents." << endl;
      euros++;
    }
  }

  operator USD() const {
    return USD();
  }

  friend EUR operator+(const EUR& a, const EUR& b) {
    EUR result;

    result.euros = a.euros + b.euros;
    result.cents = a.cents + b.cents;

    return result;
  }

  friend ostream& operator<<(ostream& os, const EUR& a) {
    os << a.euros << ' ' << a.cents << endl;
    return os;
  }
};



int main()
{
  EUR  myMoneyEuro;
  USD  myMoneyUSD;

  myMoneyUSD = EUR(10, 20.0) + USD(20, 20.0);
  myMoneyEuro = USD(100, 30.0) + EUR(300, 20.0);

  cout << myMoneyUSD << endl;
  cout << myMoneyEuro << endl;
}
