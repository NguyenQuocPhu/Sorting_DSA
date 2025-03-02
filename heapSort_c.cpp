#include <bits/stdc++.h>
using namespace std;
// Hàm heapSort sử dụng priority_queue (Heap)
void heapSort(vector<int>& arr) {
    // Tạo một max-heap từ vector arr
    priority_queue<int> pq(arr.begin(), arr.end());

    // Lấy từng phần tử lớn nhất từ heap và gán vào mảng arr theo thứ tự giảm dần
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = pq.top(); // Lấy phần tử lớn nhất
        pq.pop();          // Loại bỏ phần tử đó khỏi heap
    }
}

vector <int> a;
int SIZE = 1e6;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Lặp kiểm tra 10 test liên tiép
    for(int test = 1 ; test <= 10 ; test++){
        string filename = "test_" + to_string(test) + ".txt";
        freopen(filename.c_str(), "r", stdin);
        // Lấy dữ liệu trong file
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1 ; i <= SIZE; i++){
            int x; cin>>x;
            a.push_back(x);
        }
        heapSort(a);
        auto end = std::chrono::high_resolution_clock::now();
        a.clear();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        // Tính thời gian chạy
        std::cout << "Runtime "<<test<<": "<< elapsed.count() << " ms" << std::endl;
    }
    return 0;
}
