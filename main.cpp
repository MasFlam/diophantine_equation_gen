#include <bits/stdc++.h>

using namespace std;

struct Diophantine_equation { int factor1; int factor2; int right_side; };
vector<Diophantine_equation> gen_solvable(const int&);
vector<Diophantine_equation> gen_solvable(const int&, const unsigned int&);
vector<Diophantine_equation> gen_unsolvable(const int&);
vector<Diophantine_equation> gen_unsolvable(const int&, const unsigned int&);
int gcd(const unsigned int&, const unsigned int&);

int main(int argc, char* args[])
{
    int solvable_count, unsolvable_count;
    
    if(argc <= 1){
        cout << "How many diophantine equations to generate with solutions?" << endl;
        cin >> solvable_count;
        cout << "How many diophantine equations to generate without solutions?" << endl;
        cin >> unsolvable_count;
        cout << endl;
    } else {
        solvable_count = atoi(args[1]);
        unsolvable_count = atoi(args[2]);
    }
    
    vector<Diophantine_equation> solvable = gen_solvable(solvable_count);
    vector<Diophantine_equation> unsolvable = gen_unsolvable(unsolvable_count);
    
    cout << "SOLVABLE:" << endl;
    for(Diophantine_equation eq : solvable) cout << eq.factor1 << "x + " << eq.factor2 << "y = " << eq.right_side << endl;
    
    cout << "UNSOLVABLE:" << endl;
    for(Diophantine_equation eq : unsolvable) cout << eq.factor1 << "x + " << eq.factor2 << "y = " << eq.right_side << endl;
    
    return 0;
}

vector<Diophantine_equation> gen_unsolvable(const int& quantity){
    return gen_unsolvable(quantity, time(NULL));
}

vector<Diophantine_equation> gen_unsolvable(const int& quantity, const unsigned int& seed){
    vector<Diophantine_equation> equations(quantity);
    
    srand(seed);
    for(int i = 0; i < quantity; ++i){
        int factor1 = rand();
        int factor2 = rand();
        int right_side;
        int gcd_ = gcd(max(factor1, factor2), min(factor1, factor2));
        do {
            right_side = rand();
        } while(right_side % gcd_ != 0);
        
        Diophantine_equation equation = {factor1, factor2, right_side};
        equations[i] = equation;
    }
    
    return equations;
}

vector<Diophantine_equation> gen_solvable(const int& quantity){
    return gen_solvable(quantity, time(NULL));
}

vector<Diophantine_equation> gen_solvable(const int& quantity, const unsigned int& seed){
    vector<Diophantine_equation> equations(quantity);
    
    srand(seed);
    for(int i = 0; i < quantity; ++i){
        int factor1 = rand();
        int factor2 = rand();
        int gcd_ = gcd(max(factor1, factor2), min(factor1, factor2));
        int right_side = gcd_ * (rand() % 420);
        Diophantine_equation equation = {factor1, factor2, right_side};
        equations[i] = equation;
    }
    
    return equations;
}

int gcd(const unsigned int& a, const unsigned int& b){
    if(a == 0)
        return b;
    else
        return gcd(b % a, a);
}
