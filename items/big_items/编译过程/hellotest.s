	.file	"hellotest.c"
	.text
	.section	.rodata
.LC0:
	.string	"abc"
.LC1:
	.string	"a+"
.LC2:
	.string	"log"
	.align 8
.LC3:
	.string	"[%04d-%02d-%02d][%02d:%02d:%02d][%s][%s][%2d]123%s\n"
.LC4:
	.string	"hellotest.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	.LC0(%rip), %rax
	movq	%rax, -32(%rbp)
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	fopen@PLT
	movq	%rax, -24(%rbp)
	leaq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	time@PLT
	leaq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	localtime@PLT
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edi
	movq	-16(%rbp), %rax
	movl	4(%rax), %esi
	movq	-16(%rbp), %rax
	movl	8(%rax), %r9d
	movq	-16(%rbp), %rax
	movl	12(%rax), %r10d
	movq	-16(%rbp), %rax
	movl	16(%rax), %eax
	leal	1(%rax), %ecx
	movq	-16(%rbp), %rax
	movl	20(%rax), %eax
	leal	1900(%rax), %edx
	movq	-24(%rbp), %rax
	pushq	-32(%rbp)
	pushq	$19
	leaq	__FUNCTION__.3596(%rip), %r8
	pushq	%r8
	leaq	.LC4(%rip), %r8
	pushq	%r8
	pushq	%rdi
	pushq	%rsi
	movl	%r10d, %r8d
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addq	$48, %rsp
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	xorq	%fs:40, %rdx
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.type	__FUNCTION__.3596, @object
	.size	__FUNCTION__.3596, 5
__FUNCTION__.3596:
	.string	"main"
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
