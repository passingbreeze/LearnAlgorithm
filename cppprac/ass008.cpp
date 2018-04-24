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
  USD(const class EUR&) { }

  friend USD operator+ (const USD& a, const USD& b) {

    USD result;

    result.dollars = a.dollars + b.dollars;
    result.cents = a.cents + b.cents;

    return result;
  }

  friend ostream& operator<<(ostream& os, const USD& a) {
    os << "USD : " << a.dollars << ' ' << a.cents << endl;
    return os;
  }
};

class EUR {
  int euros;
  float cents; // 0.0<=cent<100
public:
  EUR() : euros(0), cents(0.0) {}
  EUR(const EUR& e) {
    euros = e.euros;
    cents = e.cents;
  }
  EUR(int _e, float _c): euros(_e), cents(_c) {
    if (_c < 0.0) {
      cout << "So much less cents." << endl;
      cents = 0.0;
    }

    else if (_c > 100.0) {
      cout << "So much cents." << endl;
      euros++;
    }

  }

  EUR(const class USD&) {}

  friend EUR operator+(EUR& a, EUR& b) {
    EUR result;

    result.euros = a.euros + b.euros;
    result.cents = a.cents + b.cents;

    return result;
  }

  friend ostream& operator<<(ostream& os, EUR& a) {
    os << "EUR : " << a.euros << ' ' << a.cents << endl;
    return os;
  }
};

int main()
{
  EUR myMoneyEuro;
  USD myMoneyUSD;

  myMoneyUSD = EUR(10, 20.0) + USD(20, 20.0);
  myMoneyEuro = USD(100, 30.0) + EUR(300, 20.0);

  cout << myMoneyUSD << endl;
  cout << myMoneyEuro << endl;
}
