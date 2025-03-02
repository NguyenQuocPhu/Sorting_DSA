#include <bits/stdc++.h>
using namespace std;
// Hàm merge: Trộn hai mảng con đã được sắp xếp vào mảng chính
void merge(vector<int>& vec, int left, int mid, int right) {
    int i, j, k;

    // Xác định kích thước của hai mảng con
    int n1 = mid - left + 1;  // Độ dài của mảng con trái
    int n2 = right - mid;      // Độ dài của mảng con phải
    // Tạo hai mảng con
    vector<int> leftVec(n1), rightVec(n2);

    // Sao chép dữ liệu vào mảng con trái
    for (i = 0; i < n1; i++)
        leftVec[i] = vec[left + i];

    // Sao chép dữ liệu vào mảng con phải
    for (j = 0; j < n2; j++)
        rightVec[j] = vec[mid + 1 + j];

    // Chỉ số ban đầu của mảng con trái, mảng con phải, và mảng chính
    i = 0;   
    j = 0;
    k = left;

    // Trộn hai mảng con trở lại mảng chính theo thứ tự tăng dần
    while (i < n1 && j < n2) {
        if (leftVec[i] <= rightVec[j]) {
            vec[k] = leftVec[i];  // Chọn phần tử nhỏ hơn từ mảng con trái
            i++;
        } else {
            vec[k] = rightVec[j];  // Chọn phần tử nhỏ hơn từ mảng con phải
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con trái (nếu có)
    while (i < n1) {
        vec[k] = leftVec[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của mảng con phải (nếu có)
    while (j < n2) {
        vec[k] = rightVec[j];
        j++;
        k++;
    }
}

// Hàm mergeSort: Sắp xếp mảng bằng thuật toán Merge Sort
void mergeSort(vector<int>& vec, int left, int right) {
    if (left < right) {  // Điều kiện dừng: Khi left >= right, tức là chỉ còn 1 phần tử

        // Tìm vị trí giữa của mảng
        int mid = left + (right - left) / 2;

        // Gọi đệ quy để sắp xếp nửa trái của mảng
        mergeSort(vec, left, mid);

        // Gọi đệ quy để sắp xếp nửa phải của mảng
        mergeSort(vec, mid + 1, right);

        // Trộn hai nửa đã sắp xếp
        merge(vec, left, mid, right);
    }
}
vector <int> a;
int SIZE = 1e6;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // Lặp kiểm tra 10 test liên tiép
    for(int test = 1 ; test <= 10 ; test++){
        // Lấy dữ liệu trong file
        string filename = "test_" + to_string(test) + ".txt";
        freopen(filename.c_str(), "r", stdin);
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1 ; i <= SIZE; i++){
            int x; cin>>x;
            a.push_back(x);
        }
        mergeSort(a, 0, a.size() - 1);
        auto end = std::chrono::high_resolution_clock::now();
        a.clear();
        // Tính thời gian chạy
        std::chrono::duration<double, std::milli> elapsed = end - start;
        std::cout << "Runtime "<<test<<": "<< elapsed.count() << " ms" << std::endl;
    }
    return 0;
}
