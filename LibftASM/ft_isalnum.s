section .text
global _ft_isalnum
extern _ft_isalpha, _ft_isdigit
_ft_isalnum:            ; int ft_isalnum(int c) {
    call _ft_isalpha    ; int resp = ft_isalpha(c);
    cmp rax, 1          ; int diff = resp - 1;
    je return_label     ; if (diff == 0) goto return_label;
    call _ft_isdigit    ; resp = ft_isdigit(c);
    return_label:       ; return_label:
        ret             ; return resp; }
