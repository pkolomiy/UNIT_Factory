%include "syscalls.inc"

section .bss
mem resb 10001              ; char mem[10001];

section .data
fd dq 0                     ; int fd = 0;

section .text
global _ft_cat
_ft_cat:                    ; void ft_cat(int rdi) {
    mov [rel fd], rdi       ; int fd = rdi;
    lea rsi, [rel mem]      ; char *buf = mem;
    read_label:             ; read_label:
        mov rdi, [rel fd]   ; rdi = fd;
        mov rdx, 10000      ; size_t nbyte = 10000;
        mov rax, SYS_READ   ; // save syscall number to rax
        syscall             ; ssize_t nbr = read(rdi, buf, nbyte); // call syscall according to number in rax
        cmp rax, 0          ; int diff = nbr - 0;
        je return_label     ; if (diff == 0) goto return_label;
        mov rdi, STDOUT     ; rdi = 1;
        mov rdx, rax        ; size_t size = nbr;
        mov rax, SYS_WRITE  ; // save syscall number to rax
        syscall             ; write(rdi, buf, size); // call syscall according to number in rax
        jmp read_label      ; goto read_label;
    return_label:           ; return_label;
        ret                 ; return ; }
