# ANALYSIS 'a'

### 1. Execute
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

### 2. Valgrind Checking
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
