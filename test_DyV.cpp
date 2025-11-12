#include <iostream>
#include <vector>
#include <string>
#include "DyV.h"

using namespace std;

void expect_equal(int got, int want, const string& test){
    cout << test << ": ";
    if(got == want) cout << "OK (" << got << ")\n";
    else cout << "FAIL - got " << got << " expected " << want << "\n";
}

int main(){
    // 1) Ints - already supported by original functions
    vector<int> vi = {1,2,3,4,5,6,7};
    expect_equal(BusquedaBinaria(4, vi, 0, (int)vi.size()-1), 3, "int found");
    expect_equal(BusquedaBinaria(10, vi, 0, (int)vi.size()-1), -1, "int not found");

    // 2) Floats - use templated version
    vector<float> vf = {0.5f, 1.0f, 1.5f, 2.0f};
    expect_equal(BusquedaBinaria<float>(1.5f, vf, 0, (int)vf.size()-1), 2, "float found");
    expect_equal(BusquedaBinaria<float>(3.14f, vf, 0, (int)vf.size()-1), -1, "float not found");

    // 3) Chars
    vector<char> vc = {'a','b','c','d'};
    expect_equal(BusquedaBinaria<char>('c', vc, 0, (int)vc.size()-1), 2, "char found");
    expect_equal(BusquedaBinaria<char>('z', vc, 0, (int)vc.size()-1), -1, "char not found");

    // 4) Strings
    vector<string> vs = {"apple","banana","cherry","date"};
    expect_equal(BusquedaBinaria<string>(string("banana"), vs, 0, (int)vs.size()-1), 1, "string found");
    expect_equal(BusquedaBinaria<string>(string("pear"), vs, 0, (int)vs.size()-1), -1, "string not found");

    // 5) QuickSort templated: test sorting an unsorted vector of floats
    vector<float> uns = {3.5f, 1.2f, 4.8f, 2.1f};
    QuickSort<float>(uns, 0, (int)uns.size()-1);
    // after sort, find 2.1f
    int idx = BusquedaBinaria<float>(2.1f, uns, 0, (int)uns.size()-1);
    expect_equal(idx, 1, "quicksort+search float");

    cout << "Tests finished." << endl;
    return 0;
}
