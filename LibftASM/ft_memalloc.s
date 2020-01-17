section .text
global _ft_memalloc
extern _malloc, _ft_bzero
_ft_memalloc:       ; void *ft_memalloc(size_t size) {
    call _malloc    ; void *resp = malloc(size);
    mov rsi, rdi    ; size_t n = size;
    mov rdi, rax    ; void *s = resp;
    call _ft_bzero  ; ft_bzero(s, n);
    ret             ; return resp; }
