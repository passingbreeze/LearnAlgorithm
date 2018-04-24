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
      cout << "So much less cents." << endl;
      cents = 0.0;
    }

    else if (_c > 100.0) {
      cout << "So much cents." << endl;
      dollars++;
    }
  }
  USD(const class EUR&) { }

<<<<<<< HEAD
  operator EUR();

  friend USD operator+(const USD& a, const USD& b) {
=======
  friend USD operator+ (const USD& a, const USD& b) {
>>>>>>> 672fcb22499d14012fd8887e959c2badb65f3aa0

    USD result;

    result.dollars = a.dollars + b.dollars;
    result.cents = a.cents + b.cents;

    return result;
  }

  friend ostream& operator<<(ostream& os, const USD& a) {
<<<<<<< HEAD
    os << "USD : " << a.dollars + (float)(a.cents / 100.0);
=======
    os << "USD : " << a.dollars << ' ' << a.cents << endl;
>>>>>>> 672fcb22499d14012fd8887e959c2badb65f3aa0
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

<<<<<<< HEAD
  operator USD();

=======
  }

  EUR(const class USD&) {}

>>>>>>> 672fcb22499d14012fd8887e959c2badb65f3aa0
  friend EUR operator+(EUR& a, EUR& b) {
    EUR result;

    result.euros = a.euros + b.euros;
    result.cents = a.cents + b.cents;

    return result;
  }

<<<<<<< HEAD
  friend ostream& operator<<(ostream& os, const EUR& a) {
    os << "EUR : " << a.euros + (float)(a.cents / 100.0);
=======
  friend ostream& operator<<(ostream& os, EUR& a) {
    os << "EUR : " << a.euros << ' ' << a.cents << endl;
>>>>>>> 672fcb22499d14012fd8887e959c2badb65f3aa0
    return os;
  }
};

<<<<<<< HEAD
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

=======
>>>>>>> 672fcb22499d14012fd8887e959c2badb65f3aa0
int main()
{
  EUR myMoneyEuro;
  USD myMoneyUSD;

  myMoneyUSD = EUR(10, 20.0) + USD(20, 20.0);
  myMoneyEuro = USD(100, 30.0) + EUR(300, 20.0);

  cout << myMoneyUSD << endl;
  cout << myMoneyEuro << endl;
  return 0;
}
