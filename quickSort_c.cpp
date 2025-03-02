#include <bits/stdc++.h>
using namespace std;
long long random(int l, int r){
    return l + 1LL * rand()*rand()%(r - l + 1);
}
void quickSort(vector<int>&a, int l, int r){
    int p = a[random(l,r)];
    int i = l, j = r;
    while (i < j){
        while (a[i] < p){
            i++;
        }
        while (a[j] > p){
            j--;
        }
        if (i <= j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r) quickSort(a, i, r);
    if (l < j) quickSort(a, l, j);
}
vector <int> a;
int SIZE = 1e6;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int test = 1 ; test <= 10 ; test++){
        string filename = "test_" + to_string(test) + ".txt";
        freopen(filename.c_str(), "r", stdin);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1 ; i <= SIZE; i++){
            int x; cin>>x;
            a.push_back(x);
        }
        quickSort(a, 0, a.size() -1 );
        auto end = std::chrono::high_resolution_clock::now();
        a.clear();
        std::chrono::duration<double, std::milli> elapsed = end - start;
    
        std::cout << "Runtime "<<test<<": "<< elapsed.count() << " ms" << std::endl;
    }
    return 0;
}
