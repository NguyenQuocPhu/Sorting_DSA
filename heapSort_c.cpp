#include <bits/stdc++.h>
using namespace std;
void heapSort(vector<int>& arr) {
    priority_queue<int> pq(arr.begin(), arr.end()); 
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = pq.top(); 
        pq.pop();          
    }
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
        heapSort(a);
        auto end = std::chrono::high_resolution_clock::now();
        a.clear();
        std::chrono::duration<double, std::milli> elapsed = end - start;
    
        std::cout << "Runtime "<<test<<": "<< elapsed.count() << " ms" << std::endl;
    }
    return 0;
}