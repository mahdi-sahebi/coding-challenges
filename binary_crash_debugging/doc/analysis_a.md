# ANALYSIS 'a'

## 1. Execute
To get start, first of all let's execute the binary file normally and see the result.

```bach
cd ./deps
./a
```

Output:
```
 ./a 
Segmentation fault (core dumped)
```

Now we see the program crashes without any sign and the sitation is bad!, so we need a run-time analyser tools like **Valgrind** and also **GDB** is possible.

<br>
<br>

## 2. Valgrind Checking
To use Valgrind as analyser use command below with options:

Command:
```bash
valgrind --tool=memcheck --track-origins=yes ./a
```

Output:
```
==7699== Memcheck, a memory error detector
==7699== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==7699== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==7699== Command: ./a
==7699== 
==7699== Conditional jump or move depends on uninitialised value(s)
==7699==    at 0x414E83: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x46BFEA: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43F17E: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x440780: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401CE0: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699==  Uninitialised value was created
==7699==    at 0x462999: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43D130: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x4022C7: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401C75: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699== 
==7699== Conditional jump or move depends on uninitialised value(s)
==7699==    at 0x414F29: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x46BFEA: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43F17E: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x440780: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401CE0: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699==  Uninitialised value was created
==7699==    at 0x462999: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43D130: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x4022C7: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401C75: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699== 
==7699== Conditional jump or move depends on uninitialised value(s)
==7699==    at 0x413213: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x413FE4: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x414F38: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x46BFEA: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43F17E: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x440780: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401CE0: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699==  Uninitialised value was created
==7699==    at 0x462999: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43D130: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x4022C7: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401C75: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699== 
==7699== Conditional jump or move depends on uninitialised value(s)
==7699==    at 0x439A54: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x470638: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x4650CE: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x4657C7: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43F650: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x440780: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401CE0: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699==  Uninitialised value was created by a stack allocation
==7699==    at 0x465738: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699== 
==7699== Conditional jump or move depends on uninitialised value(s)
==7699==    at 0x439A32: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x470638: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x4650CE: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x4657C7: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x43F650: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x440780: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401CE0: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699==  Uninitialised value was created by a stack allocation
==7699==    at 0x465738: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699== 
==7699== Warning: invalid file descriptor -1 in syscall read()
==7699== Warning: invalid file descriptor -1 in syscall close()
==7699== Invalid write of size 8
==7699==    at 0x401776: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401D78: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==7699== 
==7699== 
==7699== Process terminating with default action of signal 11 (SIGSEGV)
==7699==  Access not within mapped region at address 0x0
==7699==    at 0x401776: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401D78: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
==7699==  If you believe this happened as a result of a stack
==7699==  overflow in your program's main thread (unlikely but
==7699==  possible), you can try to increase the size of the
==7699==  main thread stack using the --main-stacksize= flag.
==7699==  The main thread stack size used in this run was 8388608.
==7699== 
==7699== HEAP SUMMARY:
==7699==     in use at exit: 0 bytes in 0 blocks
==7699==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7699== 
==7699== All heap blocks were freed -- no leaks are possible
==7699== 
==7699== For lists of detected and suppressed errors, rerun with: -s
==7699== ERROR SUMMARY: 6 errors from 6 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```


### Heap

According to this report:
```
==7699== HEAP SUMMARY:
==7699==     in use at exit: 0 bytes in 0 blocks
==7699==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==7699== 
==7699== All heap blocks were freed -- no leaks are possible
```

We find out no memroy leak exists and also no **heap** allocation was used. Therefore, let's go to check memory corruption issues.


### Uninitialized

The the begin of Valgrind report we see some uninitialized variables in the code which can be error-prone.

| Address |
| :--: |
| 0x414E83 |
| 0x462999 |
| 0x414F29 |
| 0x462999 |
| 0x413213 |
| 0x462999 |
| 0x439A54 |
| 0x465738 |


### System Call

For report below:
```
==7699== Warning: invalid file descriptor -1 in syscall read()
==7699== Warning: invalid file descriptor -1 in syscall close()
==7699== Invalid write of size 8
==7699==    at 0x401776: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401D78: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
```

It tried to use 'read()' and 'close()' system calls with invalid file descriptor **-1**.


### Access Violation
And if look at this report:

```
==7699== Process terminating with default action of signal 11 (SIGSEGV)
==7699==  Access not within mapped region at address 0x0
==7699==    at 0x401776: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401D78: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x401609: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a)
==7699==    by 0x1FFEFFFCB7: ???
```

It is obvious that program has tried to access the **0x00** address which is not valid in many cases specially in OS.
It is similiar to NULL derefrencing.



<br>
<br>

## GDB
Now let's dive into more details in binary. First, let's see are debug symbols are available or not.


```bash
 gdb ./deps/a 
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
(No debugging symbols found in ./deps/a)
(gdb) 
```

See **No debugging symbols found** which tells us the debug symbols are available. Maybe it is a release version or even stripped.

Debugging for this file is a little challenging without debugging symbols.


### Run
To execute the program, run command below:

```bash
(gdb) run
Starting program: /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/a 

Program received signal SIGSEGV, Segmentation fault.
0x0000000000401776 in ?? ()
(gdb)
```

Now we see the crashing.


### Info
For reading value of possible variables, args and registers use commands below:

**Local Variables:**
```
info locals
```

**Arguments:**
```
info args
```

**Registers:**
```
info registers
```


**Output:**:
```
(gdb) info args 
No symbol table info available.
(gdb) info locals 
No symbol table info available.
(gdb) info registers
rax            0x7fffffffd790      140737488344976
rbx            0x400470            4195440
rcx            0x400               1024
rdx            0x0                 0
rsi            0x0                 0
rdi            0xffffffffffffffff  -1
rbp            0x7fffffffdbb0      0x7fffffffdbb0
rsp            0x7fffffffd790      0x7fffffffd790
r8             0x0                 0
r9             0xb                 11
r10            0x0                 0
r11            0x246               582
r12            0x4024d0            4203728
r13            0x0                 0
r14            0x4a4018            4866072
r15            0x0                 0
rip            0x401776            0x401776
eflags         0x10206             [ PF IF RF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
fs_base        0x4a8880            4884608
gs_base        0x0                 0
(gdb) 
```

Well, No local and arguments symbols are available.
As we are using on x86 CPU, so the let's check the current instruction.
In ARM architecture, the current instruction is **PC** register and on the x86 is **RIP** which contains **0x401776**.


### Instruction Inspection
Now we can diassemble the instruction that caused the crash. For doing this we use commands below:

```
(gdb) x/1i $rip
=> 0x401776:	mov    %rsi,(%rdx)
(gdb) 
```
It says shows one instruction from location of **RIP** register.
We see that tried to copy value from register **RSI** to the memory pointed at address of **RDX** register, so let's watch the values of these registers by command below:

```
(gdb) info registers rsi rdx
rsi            0x0                 0
rdx            0x0                 0
```

Now we found the problem. The register rsi holds 0 which is ok, but wanted to copy value 0 to address **0x00** which is the problem. It is similar to derefrencing a NULL pointer.


