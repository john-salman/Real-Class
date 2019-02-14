#include <iostream>
#include <fstream>
#include <sstream>
#include "Real.h"

using namespace std;

int main (int argc, char * argv [])
{
        if (argc < 2)
                return 0;
        ifstream input (argv[1]);
        if (input.fail())
                return 0;
        cout << "Testing constructors\n";
        cout << "\tDefault constructor: ";
        Real dfc; cout << dfc << endl;
        cout << "\tDouble constructor: ";
        double D1; input >> D1;
        Real dc1(D1); cout << dc1 << endl;
        cout << "\tDouble constructor: ";
        double D2; input >> D2;
        Real dc2(D2); cout << dc2 << endl;
        cout << "\tString constructor: ";
        string S; input >> S;
        Real sc(S); cout << sc << endl;
        cout << "\tCopy constructor: ";
        Real cc(sc); cout << cc << endl;
        cout << "Testing assignment operator: ";
        Real r;
        r = sc; cout << r << endl;
        cout << "Testing input operator:\n";
        for (int i = 0; i < 4; i++)
        {
                input >> r;
                cout << '\t' << r << endl;
        }
 string TF [2] = {"false", "true"};
        string s1, s2;
        while (input >> s1 >> s2)
        {
                cout << "Testing string constructor and operators\n";
                cout << "\tInput strings: " << s1 << " and " << s2 << endl;
                Real r1 (s1);
                Real r2 (s2);
                cout << "\tReal objects: " << r1 << " and " << r2 << endl;
                cout << "\t\t" << r1 << " + " << r2 << " ==> " << r1 + r2 << endl;
                cout << "\t\t" << r1 << " - " << r2 << " ==> " << r1 - r2 << endl;
                cout << "\t\t" << r1 << " * " << r2 << " ==> " << r1 * r2 << endl;
                cout << "\t\t" << r1 << " == " << r2 << " ==> " << TF[r1 == r2] << endl;
                cout << "\t\t" << r1 << " != " << r2 << " ==> " << TF[r1 != r2] << endl;
                cout << "\t\t" << r1 << " < " << r2 << " ==> " << TF[r1 < r2] << endl;
                cout << "\t\t" << r1 << " <= " << r2 << " ==> " << TF[r1 <= r2] << endl;
                cout << "\t\t" << r1 << " > " << r2 << " ==> " << TF[r1 > r2] << endl;
                cout << "\t\t" << r1 << " >= " << r2 << " ==> " << TF[r1 >= r2] << endl;
                cout << "\t\t" << r1 << " += " << r2; cout << " ==> " << (r1 += r2) << endl;
                cout << "\t\t" << r1 << " -= " << r2; cout << " ==> " << (r1 -= r2) << endl;
                cout << "\t\t" << r1 << " *= " << r2; cout << " ==> " << (r1 *= r2) << endl;
                cout << endl;
        }
        input.close();
        return 0;
}
