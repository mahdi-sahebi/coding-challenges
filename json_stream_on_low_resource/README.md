# JSON STREAM ON LOW-RESOURCE SYSTEMS

This project demonstrates how to **parse and analyze extremely large JSON files** on **low-resource systems**.  
The input dataset is: [bigf.json.bz2](https://quiz.storpool.com/bigf.json.bz2)  

- **Compressed size:** ~3 GB  
- **Uncompressed size:** ~22.5 GB  

The JSON file describes disks with their `model` and `serial` numbers.  
The goal is to **count how many unique models exist** and **how many times each one is present**, while using minimal memory.

---

## Why is this Challenging?

- **Huge dataset:** 22.5 GB of JSON is far too large to fit in RAM on typical machines, and impossible for embedded devices with only a few KB of memory.  
- **Streaming only:** The parser cannot load the file at once; instead, it must process the JSON in a streaming manner, byte by byte or chunk by chunk.  
- **Low memory footprint:** This project is designed to work with as little as **4 KB of RAM** — meaning all parsing, counting, and string handling must be done without traditional in-memory object trees.  


This makes the project relevant for **embedded systems, IoT devices, and constrained environments** where full JSON libraries are impractical.

---

## Dependencies
Install the required tools and libraries on Ubuntu/Debian:

#### GCC
```bash
sudo apt update
sudo apt install build-essential
```

#### CMake
```bash
sudo apt install cmake
```

#### Git
```bash
sudo apt install git
```


# Output
```
 Count of models: 13
[RDV2]: 33332954 Times
[DRV1]: 33338513 Times
[SSDLP2]: 33345174 Times
[SSDF1]: 33328579 Times
[123456789]: 33327094 Times
[HGST2048T]: 33332531 Times
[DSD07461]: 33333959 Times
[broken]: 33328584 Times
[SSDDC1]: 33327742 Times
[SCSI3HD]: 33329611 Times
[HGST3T]: 33337292 Times
[HGST8T]: 33337967 Times
[MODEL]: 1 Times
```
