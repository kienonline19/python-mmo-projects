# Độ phức tạp thuật toán

## Big O Notation

Big O notation là cách chúng ta đo lường hiệu suất của thuật toán khi dữ liệu đầu vào tăng lên. Đây là các loại độ phức tạp phổ biến:

1. **O(1) - Thời gian không đổi**: 
   - Thuật toán thực hiện với thời gian không đổi, bất kể kích thước đầu vào
   - Ví dụ: Truy cập phần tử mảng bằng chỉ mục, thêm/xóa phần tử ở đầu/cuối stack

```python
def get_first_element(arr):
    return arr[0]  # O(1) - luôn truy cập phần tử đầu tiên
```

2. **O(log n) - Thời gian logarit**: 
   - Thuật toán giảm vấn đề xuống một nửa mỗi lần lặp
   - Ví dụ: Binary search, các thao tác trong cây nhị phân cân bằng

```python
def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1  # Loại bỏ nửa bên trái
        else:
            right = mid - 1  # Loại bỏ nửa bên phải
    
    return -1
```

3. **O(n) - Thời gian tuyến tính**: 
   - Thời gian thực hiện tăng tuyến tính với kích thước đầu vào
   - Ví dụ: Duyệt mảng, tìm kiếm tuyến tính

```python
def linear_search(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1
```

4. **O(n log n)**: 
   - Thuật toán sắp xếp hiệu quả như Merge sort, Quick sort (trường hợp trung bình)
   - Ví dụ: `sorted()` trong Python

5. **O(n²) - Thời gian bậc hai**: 
   - Thường xuất hiện khi có 2 vòng lặp lồng nhau
   - Ví dụ: Bubble sort, Selection sort

```python
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):  # Hai vòng lặp lồng nhau -> O(n²)
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
```

6. **O(2^n) - Thời gian hàm mũ**: 
   - Thời gian tăng gấp đôi với mỗi phần tử được thêm vào
   - Ví dụ: Giải thuật đệ quy không tối ưu như dãy Fibonacci đệ quy

```python
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)  # O(2^n)
```

## Phân tích thời gian và không gian

### Phân tích thời gian
- **Best case**: Trường hợp tốt nhất (dữ liệu đã sắp xếp, phần tử cần tìm ở đầu)
- **Average case**: Trường hợp trung bình
- **Worst case**: Trường hợp xấu nhất (thường được sử dụng nhiều nhất trong phân tích)

### Phân tích không gian
- **Không gian bổ sung**: Bộ nhớ bổ sung cần thiết ngoài dữ liệu đầu vào
- **Độ phức tạp không gian**: Tương tự như độ phức tạp thời gian (O(1), O(n), etc.)

# Cấu trúc dữ liệu cơ bản trong Python

## List
- Mảng động có thể thay đổi kích thước
- Các phần tử có thể thuộc nhiều kiểu dữ liệu khác nhau

```python
my_list = [1, 2, 3, "hello", True]
my_list.append(4)       # Thêm vào cuối - O(1)
my_list.insert(1, 5)    # Chèn tại vị trí - O(n)
my_list.pop()           # Xóa phần tử cuối - O(1)
my_list.remove(3)       # Xóa giá trị đầu tiên xuất hiện - O(n)
```

## Tuple
- Bất biến (không thể thay đổi sau khi tạo)
- Tương tự list nhưng không thể sửa đổi

```python
my_tuple = (1, 2, 3, "hello")
# my_tuple[0] = 5  # Lỗi: tuple không hỗ trợ gán giá trị
```

## Dictionary
- Lưu trữ cặp key-value
- Truy cập nhanh bằng key (thời gian hằng số trung bình)

```python
my_dict = {"name": "Alice", "age": 25}
my_dict["email"] = "alice@example.com"  # Thêm key-value mới
del my_dict["age"]                      # Xóa key-value
"name" in my_dict                       # Kiểm tra key tồn tại - O(1)
```

## Set
- Tập hợp các phần tử duy nhất, không có thứ tự
- Các thao tác tập hợp như union, intersection

```python
my_set = {1, 2, 3, 4}
my_set.add(5)           # Thêm phần tử - O(1)
my_set.remove(3)        # Xóa phần tử - O(1)
another_set = {4, 5, 6}
union_set = my_set | another_set    # Hợp
intersection = my_set & another_set # Giao
```

## Collections Module
Module `collections` cung cấp các cấu trúc dữ liệu chuyên biệt:

```python
from collections import Counter, defaultdict, deque, namedtuple

# Counter: đếm số lần xuất hiện
counter = Counter("hello world")  # Counter({'l': 3, 'o': 2, ...})

# defaultdict: dictionary với giá trị mặc định
d = defaultdict(int)  # Giá trị mặc định là 0
d["key"] += 1         # Không lỗi khi key không tồn tại

# deque: double-ended queue hiệu quả
queue = deque([1, 2, 3])
queue.append(4)       # Thêm vào bên phải
queue.appendleft(0)   # Thêm vào bên trái
queue.pop()           # Lấy và xóa phần tử bên phải
queue.popleft()       # Lấy và xóa phần tử bên trái

# namedtuple: tuple với tên trường
Person = namedtuple('Person', ['name', 'age'])
p = Person('Alice', 30)
print(p.name, p.age)  # Truy cập bằng tên trường
```