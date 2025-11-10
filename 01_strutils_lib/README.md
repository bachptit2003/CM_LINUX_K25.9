#  **strutils_lib** — Static & Shared Library in C

> 🚀 A practical example demonstrating how to build, link, and use **static (.a)** and **shared (.so)** libraries in C, with simple string utility functions.  
> 📘 Perfect for students learning Embedded Linux, BeagleBone, or low-level C development.

---

## 🧠 **Tổng quan**

This project shows how to:
- Create and compile **Static Library (`.a`)** and **Shared Library (`.so`)**
- Link them to your C application (`main.c`)
- Understand how **static** vs **dynamic linking** works under Linux

The sample library `strutils` provides basic string manipulation utilities.

---

## 📁 **Cấu trúc dự án**
```text
strutils_lib/
├── libstrutils.a        # Static library
├── libstrutils.so       # Shared library
├── main.c               # Example program using the library
├── main_static          # Executable linked statically
├── main_shared          # Executable linked dynamically
├── Makefile             # Build automation file
├── README.md            # Project documentation
├── strutils.c           # Implementation of string utility functions
├── strutils.h           # Header file with function declarations
└── strutils.o           # Compiled object file
```

---

## 🧱 Các hàm có trong thư viện `strutils`

| Hàm | Mô tả |
|------|-------|
| `void str_reverse(char *str)` | Đảo ngược chuỗi in-place. |
| `void str_trim(char *str)` | Xóa khoảng trắng đầu và cuối chuỗi. |
| `void str_copy_safe(char *dest, const char *src, int max_len)` | Sao chép chuỗi an toàn, tránh tràn bộ nhớ. |

---

## ⚙️ Hướng dẫn biên dịch và chạy

### 1. Clone repository

```bash
git clone https://github.com/bachptit2003/strutils_lib.git
cd strutils_lib

Sau khi build xong , ta sẽ có :
libstrutils.a      # Static library
libstrutils.so     # Shared library
main_static        # Chương trình link với static lib
main_shared        # Chương trình link với shared lib
```
### 2. Chạy chương trình link tĩnh
``` bash
./main_static
```
### 3. Chạy chương trình link động
``` bash
Vì main_shared sử dụng thư viện .so, nên bạn cần thêm đường dẫn thư viện vào biến môi trường LD_LIBRARY_PATH:

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
./main_shared
```
 ### 🧩 Ví dụ kết quả chạy
 ``` text
Chuỗi ban đầu: '  Hello Embedded Linux  '
Sau khi trim: 'Hello Embedded Linux'
Sau khi đảo ngược: 'xuniL deddebmE olleH'
Copy an toàn: 'BeagleBone Black'
```
---
### 🧹 Các lệnh tiện ích

Dọn dẹp toàn bộ file biên dịch:
```bash
make clean 
```
Chỉ build static library:
```bash
make static
```
Chỉ build shared library:
```bash
make shared
```
---
### 🧰 Cấu trúc Makefile (mô tả nhanh)
Makefile tự động biên dịch hai loại thư viện và chương trình mẫu:
```bash
all: static shared main_static main_shared

static:
	gcc -c strutils.c -o strutils.o
	ar rcs libstrutils.a strutils.o

shared:
	gcc -fPIC -c strutils.c -o strutils.o
	gcc -shared -o libstrutils.so strutils.o

main_static:
	gcc main.c -L. -lstrutils -o main_static

main_shared:
	gcc main.c -L. -lstrutils -o main_shared
```
### 🧠 Kiến thức củng cố được
```text
Phân biệt giữa Static Linking và Dynamic Linking.

Cách tạo và quản lý .a, .so trong Linux.

Sử dụng Makefile để tự động hóa quy trình build.

Thiết lập biến môi trường LD_LIBRARY_PATH.

Kỹ năng làm việc với Git & GitHub.
```
### 🧑‍💻 Tác giả
```text
Nguyễn Bá Bách_ B21DCDT042
Kĩ thuật Điện tử Máy tính _PTIT
📧 Email: bach06092003@gmail.com
```
### Giấy phép

Dự án này được phát hành dưới giấy phép MIT License.
Bạn có thể tự do sử dụng, chỉnh sửa và phân phối mã nguồn này cho mục đích học tập hoặc nghiên cứu







