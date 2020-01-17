section .text
global _ft_strcat
extern _ft_strlen, _ft_memcpy
_ft_strcat:         ; char *ft_strcat(char *s1, char *s2) {
    push rdi        ; char *temp1 = s1;
    push rdi        ; char *temp2 = s1;
    call _ft_strlen ; size_t len = ft_strlen(s1);
    pop rdi         ; s1 = temp2;
    add rdi, rax    ; s1 += len;
    push rdi        ; temp2 = s1;
    mov rdi, rsi    ; s1 = s2;
    call _ft_strlen ; len = ft_strlen(s1);
    pop rdi         ; s1 = temp2;
    inc rax         ; len++;
    mov rdx, rax    ; size_t n = len;
    call _ft_memcpy ; char *resp = ft_memcpy(s1, s2, n);
    pop rax         ; resp = temp1;
    ret             ; return resp; }
