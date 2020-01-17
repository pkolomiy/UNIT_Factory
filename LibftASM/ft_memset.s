section .text
global _ft_memset
_ft_memset:         ; void *ft_memset(void *b, int c, size_t len) {
    push rdi        ; void *temp = b;
    mov rcx, rdx    ; size_t i = len;
    mov al, sil     ; char d = c;
    cld             ; int direction = 0;
    rep stosb       ; while (i != 0) { if (direction) { *b-- = d; } else { *b++ = d; } i--; }
    pop rax         ; void *resp = temp;
    ret             ; return resp; }
