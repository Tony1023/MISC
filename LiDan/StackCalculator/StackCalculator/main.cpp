#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
bool pred(char op1, char op2) {
    if (op1 == '=' || op1 == ')')
        return false;
    switch (op1) {
        case '*':
        case '/':
            if (op2 == '+' || op2 == '-')
                return true;
            else
                return false;
        case '+':
        case '-':
            return false;
        default: break;
    }
    return false;
}
double compute() {
    vector<double> opd;
    vector<char> op;
    string input;
    while (cin >> input) {
        if (input.size() > 1)
            opd.push_back(atof(input.c_str()));
        else {
            char temp = input.c_str()[0];
            if (temp >= 48 && temp <= 57) {
                opd.push_back(temp - 48);
            } else {
                if (temp == '(')
                    opd.push_back(compute());
                if (op.empty()) {
                    op.push_back(temp);
                    continue;
                }
                while (!pred(temp, op[op.size() - 1]) && opd.size() > 1) {
                    char oper = op[op.size() - 1];
                    double opd1 = opd[opd.size() - 2], opd2 = opd[opd.size() - 1];
                    opd.pop_back();
                    op.pop_back();
                    double result;
                    switch (oper) {
                        case '+':
                            result = opd1 + opd2; break;
                        case '-':
                            result = opd1 - opd2; break;
                        case '*':
                            result = opd1 * opd2; break;
                        case '/':
                            result = opd1 / opd2; break;
                        default:
                            cout << "Error\n";
                            return 0.0; break;
                    }
                    cout << opd1 << " " << oper << opd2 << " = " << result << endl;
                    opd[opd.size() - 1] = result;
                }
                if (temp == ')')
                    return opd[0];
                op.push_back(temp);
            }
        }
    }
    return opd[0];
}
int main() {
    freopen("input.txt", "r", stdin);
    double output = compute();
    cout << output << '\n';
    return 0;
}
