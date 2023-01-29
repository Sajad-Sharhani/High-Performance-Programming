	.file	"loop_invariants.c"
# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.1) version 9.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl version isl-0.22.1-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -imultiarch x86_64-linux-gnu loop_invariants.c
# -mtune=generic -march=x86-64 -fverbose-asm -fasynchronous-unwind-tables
# -fstack-protector-strong -Wformat -Wformat-security
# -fstack-clash-protection -fcf-protection
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
# -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
# -fipa-stack-alignment -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
# -freg-struct-return -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fsemantic-interposition -fshow-column -fshrink-wrap-separate
# -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop
# -fstack-clash-protection -fstack-protector-strong -fstdarg-opt
# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
	.section	.rodata
.LC1:
	.string	"slow"
.LC3:
	.string	"Done. sum = %15.3f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$48, %rsp	#,
	movl	%edi, -36(%rbp)	# argc, argc
	movq	%rsi, -48(%rbp)	# argv, argv
# loop_invariants.c:8:   int N = 10000, i, j;
	movl	$10000, -20(%rbp)	#, N
# loop_invariants.c:10:   double *data = (double *)malloc(N * N * sizeof(double));
	movl	-20(%rbp), %eax	# N, tmp113
	imull	%eax, %eax	# tmp113, _1
	cltq
# loop_invariants.c:10:   double *data = (double *)malloc(N * N * sizeof(double));
	salq	$3, %rax	#, _3
	movq	%rax, %rdi	# _3,
	call	malloc@PLT	#
	movq	%rax, -8(%rbp)	# tmp114, data
# loop_invariants.c:11:   for (i = 0; i < N * N; i++)
	movl	$0, -28(%rbp)	#, i
# loop_invariants.c:11:   for (i = 0; i < N * N; i++)
	jmp	.L2	#
.L3:
# loop_invariants.c:12:     data[i] = 0;
	movl	-28(%rbp), %eax	# i, tmp115
	cltq
	leaq	0(,%rax,8), %rdx	#, _5
	movq	-8(%rbp), %rax	# data, tmp116
	addq	%rdx, %rax	# _5, _6
# loop_invariants.c:12:     data[i] = 0;
	pxor	%xmm0, %xmm0	# tmp117
	movsd	%xmm0, (%rax)	# tmp117, *_6
# loop_invariants.c:11:   for (i = 0; i < N * N; i++)
	addl	$1, -28(%rbp)	#, i
.L2:
# loop_invariants.c:11:   for (i = 0; i < N * N; i++)
	movl	-20(%rbp), %eax	# N, tmp118
	imull	%eax, %eax	# tmp118, _7
# loop_invariants.c:11:   for (i = 0; i < N * N; i++)
	cmpl	%eax, -28(%rbp)	# _7, i
	jl	.L3	#,
# loop_invariants.c:29:   printf("slow\n");
	leaq	.LC1(%rip), %rdi	#,
	call	puts@PLT	#
# loop_invariants.c:30:   for (i = 0; i < N; i++)
	movl	$0, -28(%rbp)	#, i
# loop_invariants.c:30:   for (i = 0; i < N; i++)
	jmp	.L4	#
.L7:
# loop_invariants.c:32:     for (j = 0; j < N; j++)
	movl	$0, -24(%rbp)	#, j
# loop_invariants.c:32:     for (j = 0; j < N; j++)
	jmp	.L5	#
.L6:
# loop_invariants.c:33:       data[i * N + j] += i * N / 7.7 + j;
	movl	-28(%rbp), %eax	# i, tmp119
	imull	-20(%rbp), %eax	# N, tmp119
	movl	%eax, %edx	# tmp119, _8
	movl	-24(%rbp), %eax	# j, tmp120
	addl	%edx, %eax	# _8, _9
	cltq
	leaq	0(,%rax,8), %rdx	#, _11
	movq	-8(%rbp), %rax	# data, tmp121
	addq	%rdx, %rax	# _11, _12
	movsd	(%rax), %xmm1	# *_12, _13
# loop_invariants.c:33:       data[i * N + j] += i * N / 7.7 + j;
	movl	-28(%rbp), %eax	# i, tmp122
	imull	-20(%rbp), %eax	# N, _14
# loop_invariants.c:33:       data[i * N + j] += i * N / 7.7 + j;
	cvtsi2sdl	%eax, %xmm0	# _14, _15
	movsd	.LC2(%rip), %xmm2	#, tmp123
	divsd	%xmm2, %xmm0	# tmp123, _15
	movapd	%xmm0, %xmm2	# _15, _16
# loop_invariants.c:33:       data[i * N + j] += i * N / 7.7 + j;
	cvtsi2sdl	-24(%rbp), %xmm0	# j, _17
	addsd	%xmm2, %xmm0	# _16, _18
# loop_invariants.c:33:       data[i * N + j] += i * N / 7.7 + j;
	movl	-28(%rbp), %eax	# i, tmp124
	imull	-20(%rbp), %eax	# N, tmp124
	movl	%eax, %edx	# tmp124, _19
	movl	-24(%rbp), %eax	# j, tmp125
	addl	%edx, %eax	# _19, _20
	cltq
	leaq	0(,%rax,8), %rdx	#, _22
	movq	-8(%rbp), %rax	# data, tmp126
	addq	%rdx, %rax	# _22, _23
	addsd	%xmm1, %xmm0	# _13, _24
	movsd	%xmm0, (%rax)	# _24, *_23
# loop_invariants.c:32:     for (j = 0; j < N; j++)
	addl	$1, -24(%rbp)	#, j
.L5:
# loop_invariants.c:32:     for (j = 0; j < N; j++)
	movl	-24(%rbp), %eax	# j, tmp127
	cmpl	-20(%rbp), %eax	# N, tmp127
	jl	.L6	#,
# loop_invariants.c:30:   for (i = 0; i < N; i++)
	addl	$1, -28(%rbp)	#, i
.L4:
# loop_invariants.c:30:   for (i = 0; i < N; i++)
	movl	-28(%rbp), %eax	# i, tmp128
	cmpl	-20(%rbp), %eax	# N, tmp128
	jl	.L7	#,
# loop_invariants.c:38:   sum = 0;
	pxor	%xmm0, %xmm0	# tmp129
	movsd	%xmm0, -16(%rbp)	# tmp129, sum
# loop_invariants.c:39:   for (i = 0; i < N * N; i++)
	movl	$0, -28(%rbp)	#, i
# loop_invariants.c:39:   for (i = 0; i < N * N; i++)
	jmp	.L8	#
.L9:
# loop_invariants.c:40:     sum += data[i];
	movl	-28(%rbp), %eax	# i, tmp130
	cltq
	leaq	0(,%rax,8), %rdx	#, _26
	movq	-8(%rbp), %rax	# data, tmp131
	addq	%rdx, %rax	# _26, _27
	movsd	(%rax), %xmm0	# *_27, _28
# loop_invariants.c:40:     sum += data[i];
	movsd	-16(%rbp), %xmm1	# sum, tmp133
	addsd	%xmm1, %xmm0	# tmp133, tmp132
	movsd	%xmm0, -16(%rbp)	# tmp132, sum
# loop_invariants.c:39:   for (i = 0; i < N * N; i++)
	addl	$1, -28(%rbp)	#, i
.L8:
# loop_invariants.c:39:   for (i = 0; i < N * N; i++)
	movl	-20(%rbp), %eax	# N, tmp134
	imull	%eax, %eax	# tmp134, _29
# loop_invariants.c:39:   for (i = 0; i < N * N; i++)
	cmpl	%eax, -28(%rbp)	# _29, i
	jl	.L9	#,
# loop_invariants.c:41:   printf("Done. sum = %15.3f\n", sum);
	movq	-16(%rbp), %rax	# sum, tmp135
	movq	%rax, %xmm0	# tmp135,
	leaq	.LC3(%rip), %rdi	#,
	movl	$1, %eax	#,
	call	printf@PLT	#
# loop_invariants.c:43:   free(data);
	movq	-8(%rbp), %rax	# data, tmp136
	movq	%rax, %rdi	# tmp136,
	call	free@PLT	#
# loop_invariants.c:45:   return 0;
	movl	$0, %eax	#, _49
# loop_invariants.c:46: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC2:
	.long	3435973837
	.long	1075760332
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
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
