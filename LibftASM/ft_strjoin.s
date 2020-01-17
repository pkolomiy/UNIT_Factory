section .data
len dq 0                ; size_t len = 0;

section .text
global _ft_strjoin
extern _ft_strcat, _ft_strlen, _malloc, _ft_memcpy
_ft_strjoin:            ; char *ft_strjoin(char *s1, char *s2) {
    push rsi            ; char *temp1 = s2;
    push rdi            ; char *temp2 = s1;
    call _ft_strlen     ; size_t rax = ft_strlen(s1);
    mov rcx, rax        ; size_t rcx = rax;
    inc rcx             ; rcx++;
    mov [rel len], rcx  ; len = rcx;
    mov rdi, rsi        ; s1 = s2;
    call _ft_strlen     ; rax = ft_strlen(s1);
    add rcx, rax        ; rcx += rax;
    mov rdi, rcx        ; size_t size = rcx;
    call _malloc        ; void *mem = malloc(size);
    mov rdi, rax        ; void *dst = mem;
    mov rdx, [rel len]  ; size_t rdx = len;
    pop rsi             ; s2 = temp2;
    call _ft_memcpy     ; void *resp = ft_memcpy(dst, s2, rdx);
    mov rdi, rax        ; s1 = resp;
    pop rsi             ; s2 = temp1;
    call _ft_strcat     ; resp = ft_strcat(s1, s2);
    ret                 ; return resp; }
