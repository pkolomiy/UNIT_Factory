%include "syscalls.inc"

section .bss
nbr resb 100                ; char nbr[100];

section .data
pos dq 0                    ; char *pos = NULL;
minus db '-'

section .text
global _ft_putnbr
_ft_putnbr:                 ; void ft_putnbr(int rdi) {
    lea rcx, [rel nbr]      ; char *rcx = nbr;
    mov [rel pos], rcx      ; pos = rcx;
    mov eax, edi            ; int eax = rdi
    cmp edi, 0              ; int diff = rdi - 0;
    jge div_nbr_label       ; (if diff >= 0) goto div_nbr_label;
    push rax                ; int temp = rax;
    mov rax, SYS_WRITE      ; // save syscall number to rax
    mov rdi, STDOUT         ; int rdi = 1;
    lea rsi, [rel minus]    ; char *rsi = pos;
    mov rdx, 1              ; rdx = 1;
    syscall                 ; write(rdi, rsi, rdx); // call syscall according to number in rax
    pop rax                 ; rax = temp;
    neg eax                 ; rax = -rax;
    div_nbr_label:          ; div_nbr_label:
        mov rdx, 0          ; int rdx = 0;
        mov rbx, 10         ; int rbx = 10;
        div rbx             ; rdx = eax % 10; eax /= 10;
        push rax            ; temp = rax;
        add rdx, 48         ; rdx += 48;
        mov rcx, [rel pos]  ; rcx = pos;
        mov [rcx], dl       ; *rcx = (char)rdx;
        inc rcx             ; rcx++;
        mov [rel pos], rcx  ; pos = rcx;
        pop rax             ; rax = temp;
        cmp eax, 0          ; diff = eax - 0;
        jne div_nbr_label   ; if (diff != 0) goto div_nbr_label;
    print_nbr_label:        ; print_nbr_label:
        mov rcx, [rel pos]  ; rcx = pos;
        lea rbx, [rel nbr]  ; char *temp2 = nbr;
        cmp rcx, rbx        ; diff = rcx - temp2;
        jle return_label    ; if (diff <= 0) goto return_label;
        dec rcx             ; rcx--;
        mov [rel pos], rcx  ; pos = rcx;
        mov rax, SYS_WRITE  ; // save syscall number to rax
        mov rdi, STDOUT     ; int rdi = 1;
        mov rsi, [rel pos]  ; char *rsi = pos;
        mov rdx, 1          ; rdx = 1;
        syscall             ; write(rdi, rsi, rdx); // call syscall according to number in rax
        jmp print_nbr_label ; goto print_nbr_label
    return_label:           ; return_label:
    ret                     ; return; }
