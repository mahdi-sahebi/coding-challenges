# ANALYSIS 'b'
For debugging this file, we act like the file [analysis_a](analysis_a.md).

## 1. Execute
To get start, first of all let's execute the binary file normally and see the result.

```bach
cd ./deps
./b
```

Output:
```
./b
Segmentation fault (core dumped)
```

Now we see the program crashes, so we need a run-time analyser tools like **Valgrind** and also **GDB** is possible.

<br>
<br>


# 2. Valgrind Checking
To use Valgrind as analyser use command below with options:

Command:
```bash
valgrind --tool=memcheck --track-origins=yes ./b
```

Output:
```
 valgrind --tool=memcheck --track-origins=yes ./b 
==5991== Memcheck, a memory error detector
==5991== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==5991== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==5991== Command: ./b
==5991== 
==5991== Conditional jump or move depends on uninitialised value(s)
==5991==    at 0x4102E8: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x45B7E8: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x45BDE4: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x435B93: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x436427: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x400DD4: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4010ED: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4009B9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x1FFEFFFD07: ???
==5991==  Uninitialised value was created
==5991==    at 0x458EE9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x433C88: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x401516: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x400D8C: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4010ED: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4009B9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x1FFEFFFD07: ???
==5991== 
==5991== Conditional jump or move depends on uninitialised value(s)
==5991==    at 0x41033D: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x45B7E8: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x45BDE4: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x435B93: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x436427: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x400DD4: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4010ED: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4009B9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x1FFEFFFD07: ???
==5991==  Uninitialised value was created
==5991==    at 0x458EE9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x433C88: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x401516: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x400D8C: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4010ED: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4009B9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x1FFEFFFD07: ???
==5991== 
==5991== Invalid read of size 1
==5991==    at 0x400B67: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x400E62: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4010ED: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4009B9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x1FFEFFFD07: ???
==5991==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
==5991== 
==5991== 
==5991== Process terminating with default action of signal 11 (SIGSEGV)
==5991==  Access not within mapped region at address 0x0
==5991==    at 0x400B67: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x400E62: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4010ED: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4009B9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x1FFEFFFD07: ???
==5991==  If you believe this happened as a result of a stack
==5991==  overflow in your program's main thread (unlikely but
==5991==  possible), you can try to increase the size of the
==5991==  main thread stack using the --main-stacksize= flag.
==5991==  The main thread stack size used in this run was 8388608.
==5991== 
==5991== HEAP SUMMARY:
==5991==     in use at exit: 0 bytes in 0 blocks
==5991==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==5991== 
==5991== All heap blocks were freed -- no leaks are possible
==5991== 
==5991== For lists of detected and suppressed errors, rerun with: -s
==5991== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)
Segmentation fault (core dumped)
```



## Heap
According to this report:
```
==5991== HEAP SUMMARY:
==5991==     in use at exit: 0 bytes in 0 blocks
==5991==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==5991== 
==5991== All heap blocks were freed -- no leaks are possible
```

We find out no memroy leak exists and also no **heap** allocation was used. Therefore, let's go to check memory corruption issues.



## Uninitialized
The the begin of Valgrind report we see some uninitialized variables in the code which can be error-prone.

| Address |
| :--: |
| 0x458EE9 |
| 0x41033D |
| 0x458EE9 |


## Access Vialotion
If we take a look at this report:
```
==5991== Invalid read of size 1
==5991==    at 0x400B67: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x400E62: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4010ED: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x4009B9: ??? (in /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b)
==5991==    by 0x1FFEFFFD07: ???
==5991==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
```

We see an invalid access to address **0x00**, which probably is NULL derefrence. Keep in mind for later.



<br>
<br>

# GDB
Now let's dive into more details in binary. First, let's see are debug symbols are available or not.


```bash
gdb ./b
GNU gdb (Ubuntu 15.0.50.20240403-0ubuntu1) 15.0.50.20240403-git
Copyright (C) 2024 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./b...

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.ubuntu.com>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
(No debugging symbols found in ./b)
(gdb) 
```

Like binary **a**,  debug symbols are not available. Maybe it is a release version or even stripped.



## Run
To execute the program, run command below:

```bash
(gdb) run
Starting program: /media/mahdi/common/repositories/coding-challenges/binary_crash_debugging/deps/b 

Program received signal SIGSEGV, Segmentation fault.
0x0000000000400b67 in ?? ()
(gdb) 
```

Now we see the crashing.




## Info
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
(gdb) info locals
No symbol table info available.
(gdb) info args
No symbol table info available.
(gdb) info registers 
rax            0x0                 0
rbx            0x4002e0            4195040
rcx            0xca4               3236
rdx            0x40                64
rsi            0x0                 0
rdi            0x489ca4            4758692
rbp            0x7fffffffdc00      0x7fffffffdc00
rsp            0x7fffffffdbb0      0x7fffffffdbb0
r8             0xc                 12
r9             0x0                 0
r10            0x2                 2
r11            0x0                 0
r12            0x401700            4200192
r13            0x401790            4200336
r14            0x0                 0
r15            0x0                 0
rip            0x400b67            0x400b67
eflags         0x10206             [ PF IF RF ]
cs             0x33                51
ss             0x2b                43
ds             0x0                 0
es             0x0                 0
fs             0x0                 0
gs             0x0                 0
fs_base        0x6b6880            7039104
gs_base        0x0                 0
(gdb) 
```

Well, No local and arguments symbols are available.
As we are using on x86 CPU, so the let's check the current instruction.
In ARM architecture, the current instruction is **PC** register and on the x86 is **RIP** which contains **0x400b67**.


<br>

## Instruction Inspection
Now we can diassemble the instruction that caused the crash. For doing this we use commands below:

```
(gdb) x/1i $rip
=> 0x400b67:	movzbl (%rax),%eax
(gdb) 

```
It shows one instruction from location of **RIP** register.
It copies with zero-extend one byte from address at **RAX** to the address pointed at **EAX** register.

Note that the **EAX** is the lower 32bit of **RAX**, so when EAX is 0 the EAX is also 0.
so let's watch the values of these registers by command below:

```
=> 0x400b67:	movzbl (%rax),%eax
(gdb) info registers rax eax
rax            0x0                 0
eax            0x0                 0
```

Now we found the problem. The register rax holds 0 which is ok, but wanted to copy value 0 to address **0x00** which is the problem. It is derefrencing a NULL pointer.


<br>

## Inspecting Source
Ok, now how are we going to find out the source of this NULL pointer derefrence?
Maybe we should take a look at instructions before this error.

Use this command to look at 16 instructions at 40 bytes before **RIP**:
```
x/16i $rip-40
```

Output:
```
(gdb) x/10i $rip -40
   0x400b3f:	rex.RB sarb $1,0x20(%r10)
   0x400b46:	mov    $0x0,%esi
   0x400b4b:	mov    %rax,%rdi
   0x400b4e:	call   0x400360
   0x400b53:	lea    0x8914a(%rip),%rdi        # 0x489ca4
   0x400b5a:	call   0x406c70
   0x400b5f:	mov    %rax,-0x10(%rbp)
   0x400b63:	mov    -0x10(%rbp),%rax
=> 0x400b67:	movzbl (%rax),%eax
   0x400b6a:	cmp    $0x2f,%al
```

It is clear that the RAX is came from **RBP** which is came from **RAX** again as return value of call function at address **0x406c70**.

For making sure, lets set a break point just after the call instruction and read the returned value.

Set a breakpoint at address **0x406c70**:
```
break *0x406c70
```

Now re-run the program to stop at the breakpoint:
```
run
```

<br>
<br>




## Function
Not let's go to check how info are we able read from this function.

Read available info from this function address:
```
info symbol 0x406c70
```

Output:
```
(gdb) info symbol 0x406c70
No symbol matches 0x406c70.
(gdb) 
```

As we have saw earlier, this binary file has been stripped and has not any symbol.
Now let's extarct the function instruction from start address to the **ret** instruction.

Output:
```
(gdb) x/50i $rip
=> 0x406c70:	push   %r15
   0x406c72:	push   %r14
   0x406c74:	mov    %rdi,%r15
   0x406c77:	push   %r13
   0x406c79:	push   %r12
   0x406c7b:	push   %rbp
   0x406c7c:	push   %rbx
   0x406c7d:	sub    $0x8,%rsp
   0x406c81:	call   0x417e90
   0x406c86:	mov    0x2ad9b3(%rip),%rbp        # 0x6b4640
   0x406c8d:	test   %rbp,%rbp
   0x406c90:	je     0x406d48
   0x406c96:	mov    %rax,%r13
   0x406c99:	movzbl (%r15),%eax
   0x406c9d:	test   %al,%al
   0x406c9f:	je     0x406d48
   0x406ca5:	cmpb   $0x0,0x1(%r15)
   0x406caa:	jne    0x406cf0
   0x406cac:	mov    0x0(%rbp),%rbx
   0x406cb0:	or     $0x3d,%ah
   0x406cb3:	test   %rbx,%rbx
   0x406cb6:	jne    0x406ccd
   0x406cb8:	jmp    0x406cd6
   0x406cba:	nopw   0x0(%rax,%rax,1)
   0x406cc0:	add    $0x8,%rbp
   0x406cc4:	mov    0x0(%rbp),%rbx
   0x406cc8:	test   %rbx,%rbx
   0x406ccb:	je     0x406cd6
   0x406ccd:	cmp    (%rbx),%ax
   0x406cd0:	jne    0x406cc0
   0x406cd2:	add    $0x2,%rbx
   0x406cd6:	add    $0x8,%rsp
   0x406cda:	mov    %rbx,%rax
   0x406cdd:	pop    %rbx
   0x406cde:	pop    %rbp
   0x406cdf:	pop    %r12
   0x406ce1:	pop    %r13
   0x406ce3:	pop    %r14
   0x406ce5:	pop    %r15
   0x406ce7:	ret
```


I just have basic aesembly knowledge and not able to go further by now, but will try to understand soon.

