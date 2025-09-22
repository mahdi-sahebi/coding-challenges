# Binary Crash Debugging

This repository demonstrates the process of **debugging a stripped binary** that crashes at runtime.  
In release binaries, symbols are eliminated, which makes debugging much harder. Here, we will talk how to do this.



## 🔍 Problem Statement

We are given two binaries that **Crashes during execution** with no obvious explanation.

Goal:
1. Understand why the crash happens.
2. Document the entire debugging process.


## 📦 Dependencies

To reproduce the analysis, install the following tools on Linux:


```bash
# Update package index
sudo apt update

# Install debugging tools
sudo apt install gdb valgrind
```

## Analysis
The report has been provided for [binary a](./doc/analysis_a.md) and [binary b](./doc/analysis_b.md).

