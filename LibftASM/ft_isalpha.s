section .text
global _ft_isalpha
extern _ft_toupper
_ft_isalpha:            ; int ft_isalpha(int c) {
    call _ft_toupper    ; int resp = ft_toupper(c);
    cmp rax, 'A'        ; int diff = resp - 'A';
    jl false_label      ; if (diff < 0) goto false_label;
    cmp rax, 'Z'        ; diff = c - 'Z';
    jg false_label      ; if (diff > 0) goto false_label;
    mov rax, 1          ; resp = 1;
    ret                 ; return resp;
    false_label:        ; false_label:
        mov rax, 0      ; resp = 0;
    ret                 ; return resp; }
