#include <stdio.h>
#include <iostream>
#include <string>

int main (int argc, char *argv[]){
    if (argc <= 2) {
        std::cout << "[!] Usage: asm_compiler.exe asmfile outputfile (optional -r or --run)\n";
        return 1;
    }
    else if (argc >= 5) {
        std::cout << "[!] Usage: asm_compiler.exe asmfile outputfile (optional -r or --run)\n";
        return 1;
    }

    if (argv[3]) {
        std::string arg3 = argv[3];
        if (arg3 == "-r" || arg3 == "--run") {
        }
        else {
            std::cout << "[!] Usage: asm_compiler.exe asmfile outputfile (optional -r or --run)\n";
            return 1;
        }
    }
    
    std::string command_nasm = "nasm -f win32 ";
    std::string asm_file = argv[1];
    command_nasm += asm_file;
    command_nasm += ".asm -o output.obj -Wno-all";
    int result1 = system(command_nasm.c_str());
    if (result1 == 0) {
    }
    else {
        std::cout << "[!] Unable to create obj file.\n";
        return 1;
        
    }

    std::string command_ld = "ld output.obj -o ";
    std::string exe_file = argv[2];
    command_ld += exe_file;
    command_ld += ".exe";
    int result2 = system(command_ld.c_str());
    std::string output_filename = argv[2];
    output_filename += ".exe";
    if (result2 == 0) {
        std::cout << "[+] Created executable: '" << output_filename << "'\n" ;
    }
    else {
        std::cout << "[!] Unable to create executable.\n";
        return 1;
    }

    std::string command_cleanup = "del /f output.obj";
    int result3 = system(command_cleanup.c_str());
    if (result3 == 0) {
        std::cout << "[+] Cleanup complete.\n";
    }
    else {
        std::cout << "[!] Unable to cleanup.\n";
        return 1;
    }
    
    if (argv[3]) {
        std::string run_command = argv[2];
        run_command += ".exe\n";
        std::cout << "[+] Executing new program...\n";
        int run_result = system(run_command.c_str());
        if (run_result == 0) {
            std::cout << "[+] New program executed.\n";
        }
        else {
            std::cout << "[!] Unable to successfully execute new program.\n";
            return 1;
        }
    }    

    return 0;

}
