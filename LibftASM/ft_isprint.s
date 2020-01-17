section .text
global _ft_isprint
_ft_isprint:        ; int ft_isprint(int c) {
    mov rax, 0      ; int resp = 0;
    cmp rdi, ' '    ; int diff = c - ' ';
    jl return_label ; if (diff < 0) goto return_label;
    cmp rdi, '~'    ; diff = c - '~';
    jg return_label ; if (diff > 0) goto return_label;
    mov rax, 1      ; resp = 1;
    return_label:   ; return_label:
        ret         ; return resp; }
