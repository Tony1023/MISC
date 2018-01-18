#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vint;

class PositiveHugeNumber {
private:
    vint dig;
    int unit;
    void carry() {
        int thisL = dig.size() + 1;
        dig.push_back(0);
        int carry = dig[0] / unit;
        for (int i = 1; i < thisL; ++i) {
            if (carry == 0) {
                carry = dig[i] / unit;
                continue;
            }
            dig[i] += carry;
            carry = dig[i] / unit;
            dig[i - 1] %= unit;
        }
        if (dig.at(thisL - 1) == 0)
            dig.pop_back();
    }
    void shift() {
        for (int i = 0, l = dig.size(); i < l; ++i)
            dig[i] *= 10;
        this->carry();
    }
public:
    PositiveHugeNumber() {
        unit = 10000;
        dig.resize(0);
    }
    PositiveHugeNumber(int value) {
        unit = 10000;
        while (value > 0) {
            dig.push_back(value % unit);
            value /= unit;
        }
    }
    PositiveHugeNumber(const PositiveHugeNumber& n) {
        this->unit = 10000;
        this->dig = n.dig;
    }
    void print() const {
        for (int i = dig.size() - 1; i >= 0; --i)
            cout << dig.at(i) << " ";
        cout << endl;
    }
    void plus(const PositiveHugeNumber& n) {
        int thisL = this->dig.size();
        int thatL = n.dig.size();
        if (thisL < thatL)
            this->dig.resize(thatL);
        for (int i = 0; i < thatL; ++i)
            this->dig[i] += n.dig[i];
        this->carry();
    }
    void times(int value) {
        PositiveHugeNumber n(0), copy(*this);
        while (value > 0) {
            int mul = value % 10;
            PositiveHugeNumber tmp(copy);
            for (int i = 0, l = tmp.dig.size(); i < l; ++i) {
                tmp.dig[i] *= mul;
                //    cout << tmp.dig[i] << " ";
            }
            tmp.carry();
            n.plus(tmp);
            value /= 10;
            copy.shift();
        }
        *this = n;
    }
    void divide(int value) {
    }
};
    
int main() {
    PositiveHugeNumber a(111111);
    a.times(22);
    a.print();
    return 0;
}
