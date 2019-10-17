## Compile `.asm` Files for w32

### Dependencies

+ NASM compiler with environment path set
+ ld with environment path set
+ g++ with environment path set

### Usage

Compile program: `g++ asm_compiler.cpp -o asm_compiler.exe`

Compile `.asm` file named `simple.asm` into executable `example.exe`: `asm_compiler.exe simple example`

Compile and run new executable: `asm_compiler.exe simple example (-r or --run)`

Example output:
```terminal_session
C:\Users\IEUser\Documents>asm_compiler.exe simple example
[+] Created executable: 'example.exe'
[+] Cleanup complete.
```

Example output with run:
```terminal_session
C:\Users\IEUser\Documents>asm_compiler.exe simple example --run
[+] Created executable: 'example.exe'
[+] Cleanup complete.
[+] Executing new program...
[+] New program executed.
```
