# filestat

A simple Linux command-line tool written in C to display file information using `lstat()`.

## Biên dịch
```bash
gcc filestat.c -o filestat
./filestat /etc/passwd
```
Example:
```bash
./filestat /etc/passwd
```
Kết quả:
```bash
./filestat /etc/passwd
File Path: /etc/passwd
File Type: Regular File
Size: 2850 bytes
Last Modified: 2025-10-11 20:06:19
```
Push github:
```bash
git add README.md
git commit -m "Add README"
git push
```

Repo  sẽ có cấu trúc:
```text
filestat-project/
│
├── filestat.c
├── .gitignore
└── README.md