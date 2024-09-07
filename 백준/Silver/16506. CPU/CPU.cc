#include <iostream>
#include <map>
#include <string>

using namespace std;

void init_map(map<string, string>& m);
string int_to_binary(int num, int length);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, string> m;
    init_map(m);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string cmd;
        string result = "";
        int d, a, b;
        cin >> cmd >> d >> a >> b;
        result += m[cmd];
        result += int_to_binary(d, 3);
        result += int_to_binary(a, 3);
        if (result[4] == '0') {
            result += int_to_binary(b, 3) + "0";
        }
        else {
            result += int_to_binary(b, 4);
        }
        cout << result << "\n";
    }

    return 0;
}

void init_map(map<string, string>& m) {
    m["ADD"] = "000000";
    m["ADDC"] = "000010";
    m["SUB"] = "000100";
    m["SUBC"] = "000110";
    m["MOV"] = "001000";
    m["MOVC"] = "001010";
    m["AND"] = "001100";
    m["ANDC"] = "001110";
    m["OR"] = "010000";
    m["ORC"] = "010010";
    m["NOT"] = "010100";
    m["MULT"] = "011000";
    m["MULTC"] = "011010";
    m["LSFTL"] = "011100";
    m["LSFTLC"] = "011110";
    m["LSFTR"] = "100000";
    m["LSFTRC"] = "100010";
    m["ASFTR"] = "100100";
    m["ASFTRC"] = "100110";
    m["RL"] = "101000";
    m["RLC"] = "101010";
    m["RR"] = "101100";
    m["RRC"] = "101110";
}

string int_to_binary(int num, int length) {
    string result = "";
    while (num > 0) {
        if (num % 2 == 0) {
            result = "0" + result;
        } 
        else {
            result = "1" + result;
        }
        num /= 2;
    }
    while (result.length() < length) {
        result = "0" + result;
    }
    return result;
}