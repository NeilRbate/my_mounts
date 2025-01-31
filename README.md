# 🖥️ my_mounts, a simple linux kernel module who list mount points

## 📌 Overview

This project is a **Linux kernel module** named `my_mounts`, developed for educational purposes. The module creates an entry in `/proc/my_mounts`, and when read using `cat`, it lists all the mount points on the system.

## ✨ Features

- Creates `/proc/my_mounts` entry
- Lists all mounted filesystems when accessed
- Provides an easy way to inspect system mount points
- Fully compatible with **Linux Kernel 6.10.12**

## 🚀 Installation Guide

### 1️⃣ Clone the Repository

```sh
git clone https://github.com/yourusername/my_mounts.git
cd my_mounts
```

### 2️⃣ Build the Module

```sh
make
```

### 3️⃣ Load the Module

```sh
sudo insmod my_mounts.ko
```

### 4️⃣ Verify Installation

Check if the module is loaded:

```sh
dmesg | tail -n 20
lsmod | grep my_mounts
```

### 5️⃣ Read the Mount Points

Once the module is loaded, read the list of mount points using:

```sh
cat /proc/my_mounts
dmesg | tail -n 20
```

### 6️⃣ Unload the Module (if needed)

```sh
sudo rmmod my_mounts
```

## 🛠️ Prerequisites

- Linux Kernel **6.10.12**
- GNU Make
- GCC Compiler

## ⚠️ Important Notice

This module is created **for learning purposes only** and is **not intended for production environments**.

## 📜 License

This project is licensed under the **GNU General Public License v3.0**. See the `LICENSE` file for details.

## 👨‍💻 Author

[Julien Barbate](https://github.com/NeilRbate)

---
⭐ If you find this project useful, consider giving it a star!

