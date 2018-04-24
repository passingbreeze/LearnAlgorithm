#include <iostream>

using namespace std;

class EUR;
class USD {
  int dollars;
  float cents; // 0.0<=cent<100

public:
  USD() : dollars(0), cents(0.0) {}
  USD(int _d, float _c) : dollars(_d), cents(_c) {
    if (_c < 0.0) {
      cerr << "So much less cents." << endl;
      cents = 0.0;
    }

    else if (_c > 100.0) {
      cerr << "So much cents." << endl;
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
    os << "USD : " << a.dollars + (float)(a.cents / 100.0);
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
      cents = 0.0;
    }

    else if (_c > 100.0) {
      cerr << "So much cents.\n";
      euros++;
    }
  }
  EUR(const USD e) {

  }

  friend EUR operator+(EUR& a, EUR& b) {
    EUR result;

    result.euros = a.euros + b.euros;
    result.cents = a.cents + b.cents;

    return result;
  }

  friend ostream& operator<<(ostream& os, const EUR& a) {
    os << "EUR : " << a.euros + (float)(a.cents / 100.0);
    return os;
  }
};

USD::operator EUR()
{
  int conv_e = (int)((100 / 81) * dollars);
  float conv_ec = (float)((100 / 81) * cents);
  return EUR(conv_e, conv_ec);
}

EUR::operator USD()
{
  int conv_d = (int)((0.81) * euros);
  float conv_dc = (float)(0.81 * cents);
  return USD(conv_d, conv_dc);
}

int main()
{
  EUR  myMoneyEuro;
  USD  myMoneyUSD;

  myMoneyUSD = EUR(10, 20.0) + USD(20, 20.0);
  myMoneyEuro = USD(100, 30.0) + EUR(300, 20.0);

  cout << myMoneyUSD << endl;
  cout << myMoneyEuro << endl;
  return 0;
}
