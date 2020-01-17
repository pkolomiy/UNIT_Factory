section .text
global _ft_strlen
_ft_strlen:         ; size_t ft_strlen(char *s) {
    mov rcx, -1     ; size_t i = -1;
    mov al, 0       ; char c = 0;
    cld             ; int direction = 0;
    repne scasb     ; while (*s != c) { if (direction) { s--; } else { s++; } i--; }
    not rcx         ; i = -i;
    dec rcx         ; i--;
    mov rax, rcx    ; size_t len = i;
    ret             ; return len; }
