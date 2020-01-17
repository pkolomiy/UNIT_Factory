section .text
global _ft_isdigit
_ft_isdigit:        ; int ft_isdigit(int c) {
    mov rax, 0      ; int resp = 0;
    cmp rdi, '0'    ; int diff = c - '0';
    jl return_label ; if (diff < 0) goto return_label;
    cmp rdi, '9'    ; diff = c - '9';
    jg return_label ; if (diff > 0) goto return_label;
    mov rax, 1      ; resp = 1;
    return_label:   ; return_label:
        ret         ; return resp; }
