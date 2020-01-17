section .text
global _ft_memcpy
_ft_memcpy:         ; void *ft_memcpy(void *dst, void *src, size_t n) {
    push rdi        ; void *temp = dst;
    mov rcx, rdx    ; size_t i = n;
    cmp rsi, rdi    ; int diff = src - dst;
    cld             ; int direction = 0;
    jg cpy          ; if (diff > 0) goto cpy;
    std             ; direction = 1;
    dec rdx         ; n--;
    add rdi, rdx    ; dst += n;
    add rsi, rdx    ; src += n;
    cpy:            ; cpy:
        rep movsb   ; while (i != 0) { if (direction) { *dst-- = *src--; } else { *dst++ = *src++; } i--; }
        pop rax     ; void *resp = temp;
        ret         ; return resp; }
