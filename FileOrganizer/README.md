# 📂 File Organizer (C++17)

[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux-lightgrey)]()
[![Build](https://img.shields.io/badge/build-passing-success)]()

Tool sederhana untuk **merapikan file** dalam sebuah folder berdasarkan ekstensi.  
Dibuat menggunakan **C++17** dengan memanfaatkan fitur `<filesystem>` modern.

---

## ✨ Features
- 📸 `Images` → jpg, jpeg, png, gif  
- 🎥 `Videos` → mp4, mkv, avi  
- 🎵 `Music` → mp3, wav  
- 📑 `Documents` → pdf, docx, txt  
- 📦 `Archives` → zip, rar  
- ❓ `Others` → default jika tidak terdeteksi  
- 🖥️ Cross-platform (Windows / Linux)  
- 🗂️ Auto create folder tujuan  

---

## 🚀 Cara Compile & Run

### Windows (MinGW)
```bash
g++ src/main.cpp -o bin/file_organizer -std=c++17
bin\file_organizer.exe
