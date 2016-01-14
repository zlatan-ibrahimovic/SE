        .text
        .align 2
        .globl _ThreadRoot
_ThreadRoot:

        pushq %rbp
        movq %rsp,%rbp
        pushq %rdi
        pushq %rsi
        pushq %rdx
        call *%rcx
        popq %rdi
        popq %rsi
        call *%rsi
        popq %rdi
        call *%rdi


        movq %rbp,%rsp
        popq %rbp
        ret
        .comm _rax_save,8

        .globl _SWITCH
_SWITCH:

        movq %rax,_rax_save
        movq %rdi,%rax
        movq %rbx,16(%rax)
        movq %rcx,24(%rax)
        movq %rdx,32(%rax)
        movq %rsi,48(%rax)
        movq %rdi,56(%rax)
        movq %r12,64(%rax)
        movq %r13,72(%rax)
        movq %r14,80(%rax)
        movq %r15,88(%rax)
        movq %rbp,40(%rax)
        movq %rsp,0(%rax)
        movq _rax_save,%rbx
        movq %rbx,8(%rax)
        movq 0(%rsp),%rbx
        movq %rbx,96(%rax)

        movq %rsi,%rax

        movq 8(%rax),%rbx
        movq %rbx,_rax_save
        movq 16(%rax),%rbx
        movq 24(%rax),%rcx
        movq 32(%rax),%rdx
        movq 48(%rax),%rsi
        movq 56(%rax),%rdi
        movq 64(%rax),%r12
        movq 72(%rax),%r13
        movq 80(%rax),%r14
        movq 88(%rax),%r15
        movq 40(%rax),%rbp
        movq 0(%rax),%rsp
        movq 96(%rax),%rax
        movq %rax,0(%rsp)
        movq _rax_save,%rax

        ret
