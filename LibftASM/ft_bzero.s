section .text
global _ft_bzero
extern _ft_memset
_ft_bzero:          ; void ft_bzero(void *s, size_t n) {
    mov rdx, rsi    ; size_t len = n;
    mov rsi, 0      ; int c = 0;
    call _ft_memset ; ft_memset(s, c, len);
    ret             ; return ; }
