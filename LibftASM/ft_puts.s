%include "syscalls.inc"

section .data
null_str db `(null)\n`     ; char *null_str = "(null)\n";

section .text
global _ft_puts
extern _ft_strlen, _ft_putchar
_ft_puts:                   ; int ft_puts(char *s) {
    cmp rdi, 0              ; int flag = s == NULL
    jne print_label         ; if (flag) goto print_label;
    mov rdi, STDOUT         ; int fd = 1;
    lea rsi, [rel null_str] ; char *buf = null_str;
    mov rdx, 7              ; size_t size = 7;
    mov rax, SYS_WRITE      ; // save syscall number to rax
    syscall                 ; int resp = write(fd, buf, size); // call syscall according to number in rax
    ret                     ; return resp;
print_label:                ; print_label:
    push rdi                ; char *temp = s;
    call _ft_strlen         ; size_t len = ft_strlen(s);
    mov rdi, STDOUT         ; int fd = 1;
    pop rsi                 ; char *buf = temp;
    mov rdx, rax            ; size_t size = len;
    mov rax, SYS_WRITE      ; // save syscall number to rax
    syscall                 ; int resp = write(fd, buf, size); // call syscall according to number in rax
    mov rdi, `\n`           ; char c = '\n';
    call _ft_putchar        ; ft_putchar(c);
    ret                     ; return resp; }
