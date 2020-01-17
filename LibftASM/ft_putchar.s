%include "syscalls.inc"

section .text
global _ft_putchar
_ft_putchar:            ; void ft_putchar(char c) {
    push rdi            ; char temp = c;
    mov rax, SYS_WRITE  ; // save syscall number to rax
    mov rdi, STDOUT     ; int fd = 1;
    mov rsi, rsp        ; char *buf = &temp;
    mov rdx, 1          ; size_t size = 1;
    syscall             ; write(fd, buf, size); // call syscall according to number in rax
    pop rdi             ; c = temp;
    ret                 ; return ; }
