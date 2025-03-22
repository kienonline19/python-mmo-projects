#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    int maxLength = 0;
    int left = 0;
    
    for (int right = 1; right < n; right++) {
        while (a[right] - a[left] > k) {
            left++;
        }
        maxLength = std::max(maxLength, right - left + 1);
        left = 0;
    }
    
    std::cout << maxLength << std::endl;
    
    return 0;
}
