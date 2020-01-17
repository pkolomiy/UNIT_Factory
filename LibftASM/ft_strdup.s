section .text
global _ft_strdup
extern _ft_strlen, _malloc, _ft_memcpy
_ft_strdup:         ; char *ft_strdup(char *s1) {
    push rdi        ; char *temp1 = s1;
    call _ft_strlen ; size_t len = ft_strlen(s1);
    inc rax         ; len++;
    push rax        ; size_t temp2 = len;
    mov rdi, rax    ; size_t size = len;
    call _malloc    ; char *mem = malloc(size);
    mov rdi, rax    ; char *dst = mem;
    pop rdx         ; size_t n = temp2;
    pop rsi         ; char *src = temp1;
    call _ft_memcpy ; char *resp = ft_memcpy(dst, src, n);
    ret             ; return resp; }
