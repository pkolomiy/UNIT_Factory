section .text
global _ft_tolower
_ft_tolower:        ; int ft_tolower(int c) {
    mov rax, rdi    ; int resp = c;
    cmp rdi, 'A'    ; int diff = c - 'A';
    jl return_label ; if (diff < 0) goto return_label;
    cmp rdi, 'Z'    ; diff = c - 'Z';
    jg return_label ; if (diff > 0) goto return_label;
    add rax, 32     ; resp += 32;
    return_label:   ; return_label:
        ret         ; return resp; }
