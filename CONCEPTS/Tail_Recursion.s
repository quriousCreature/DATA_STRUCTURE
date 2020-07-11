	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
	.globl	_factorial              ## -- Begin function factorial
_factorial:                             ## @factorial
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%esi, %eax
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$1, %edi
	je	LBB0_3
## %bb.1:                               ##   in Loop: Header=BB0_2 Depth=1
	imull	%edi, %eax
	decl	%edi
	jmp	LBB0_2
LBB0_3:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_fact                   ## -- Begin function fact
_fact:                                  ## @fact
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$1, %eax
	cmpl	$1, %edi
	je	LBB1_3
## %bb.1:
	movl	$1, %eax
LBB1_2:                                 ## =>This Inner Loop Header: Depth=1
	imull	%edi, %eax
	decl	%edi
	cmpl	$1, %edi
	jne	LBB1_2
LBB1_3:
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	L_.str(%rip), %rdi
	movl	$120, %esi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Factorial is %d \n"


.subsections_via_symbols
