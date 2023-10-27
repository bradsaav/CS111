#include<iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
using namespace std;
bool testPrime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i < n/2; ++i) {
        if(n % i == 0) {
            return false;
        }
    }
    return true; // since n is not divisible by any i, n must be prime
}
int findP(int n) {
    for(unsigned i = 0; i < sqrt(n); ++i) {
        if(testPrime(i)) {
            if(n % i == 0) {
                int p = i;
                return p;
            }
        }
    }
    return -1;
}


int gcd(int x, int y) {
    int temp;
    while (1) { //infinite loop
        temp = x % y;
        if (temp == 0)
            return y;
        x = y;
        y = temp;
    }
}

int calculateD(int e, int n) {
    int scalarE = 1;
    int scalarN = 1;
    int E = e;
    int N = n;
    while((E-N) != 1) {
        if(E > N) {
            scalarN++;
            N = n * scalarN;
        } else {
            scalarE++;
            E = e * scalarE;
        }
    }
    return scalarE;
}

int decrypt(string c, int d, int n) {
    int cInt = stoi(c);
    int value = 1;
    while(d > 0) {
      value = value * cInt;
      value = value % n;
      d--;
   }
   //decrypt(value);
   
   return value;
}
string breaker(string cipherText, int start, int size, int d, int n , int i) {
    string sub;
    if(start == 0) {
        sub = cipherText.substr(0, size);
        return sub;
    } else {
        sub = cipherText.substr(start, size);
        return sub;
    }
}

int main() {
    map<int, string> map;
    map[5] = "A";
    map[6] = "B";
    map[7] = "C";
    map[8] = "D";
    map[9] = "E";
    map[10] = "F";
    map[11] = "G";
    map[12] = "H";
    map[13] = "I";
    map[14] = "J";
    map[15] = "K";
    map[16] = "L";
    map[17] = "M";
    map[18] = "N";
    map[19] = "O";
    map[20] = "P";
    map[21] = "Q";
    map[22] = "R";
    map[23] = "S";
    map[24] = "T";
    map[25] = "U";
    map[26] = "V";
    map[27] = "W";
    map[28] = "X";
    map[29] = "Y";
    map[30] = "Z";
    map[31] = " ";
    map[32] = "\"";
    map[33] = ",";
    map[34] = ".";
    map[35] = "'";
    
    int e;
    int n;
    string cipherText;
    cin >> e >> n;
    int m;
    cin >> m;
    cin.ignore();
    getline(cin, cipherText);
    
    if(gcd(e, n) != 1) {
        cout << "Public key is not valid!" << endl;
        return 0;
    }
    int p = findP(n);
    int q = n / p;
    cout << p;
    cout << " " << q;
    int phi = (p - 1) * (q - 1);
    cout << " " << phi;
    int d = calculateD(e, phi);
    cout << " " << d << endl;
    int i = 0;
    int start = 0;
    int size = 0;
    int code;
    string sub;
    vector<string> charVec;
    while(i < cipherText.size()) {
        if(cipherText.at(i) == ' ') {
            sub = breaker(cipherText, start, size, d, n, i);
            code = decrypt(sub, d, n);
            cout << code << " ";
            charVec.push_back(map[code]);
            start = i + 1;
            size = 0;
        }
        if(cipherText.size() - 1 == i) {
            sub = cipherText.substr(i + 1 - size, i);
            code = decrypt(sub, d, n);
            cout << code << " ";
            charVec.push_back(map[code]);
        }
        i++;
        size++;
    }
    cout << endl;
    for(unsigned j = 0; j < charVec.size(); ++j) {
        cout << charVec[j];
    }
    cout << endl;
    return 0;
}