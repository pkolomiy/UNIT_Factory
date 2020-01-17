section .data
char1 dq 0                      ; int char1 = 0;
char2 dq 0                      ; int char2 = 0;

section .text
global _ft_strcmp
_ft_strcmp:                     ; int ft_strcmp(char *s1, char *s2) {
    loop_label:                 ; loop_label:
        mov dl, byte [rdi]      ; char dl = *s1;
        mov cl, byte [rsi]      ; char cl = *s2;
        cmp dl, cl              ; int diff = dl - cl;
        jne return_label        ; if (diff != 0) goto return_label;
        cmp dl, 0               ; diff = dl - 0;
        je return_label         ; if (diff == 0) goto return_label;
        cmp cl, 0               ; diff = cl - 0;
        je return_label         ; if (diff == 0) goto return_label;
        inc rsi                 ; s1++;
        inc rdi                 ; s2++;
        jmp loop_label          ; goto loop_label;
    return_label:               ; return_label:
        mov [rel char1], dl     ; char1 = dl;
        mov [rel char2], cl     ; char2 = cl;
        mov rcx, [rel char1]    ; int rcx = char1;
        mov rdx, [rel char2]    ; int rdx = char2;
        sub rcx, rdx            ; rcx -= rdx;
        mov rax, rcx            ; int rax = rcx;
        ret                     ; return rax; }
