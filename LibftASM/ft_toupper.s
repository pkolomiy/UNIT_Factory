section .text
global _ft_toupper
_ft_toupper:        ; int ft_toupper(int c) {
    mov rax, rdi    ; int resp = c;
    cmp rdi, 'a'    ; int diff = c - 'a';
    jl return_label ; if (diff < 0) goto return_label;
    cmp rdi, 'z'    ; diff = c - 'z';
    jg return_label ; if (diff > 0) goto return_label;
    sub rax, 32     ; resp -= 32;
    return_label:   ; return_label:
        ret         ; return resp; }
