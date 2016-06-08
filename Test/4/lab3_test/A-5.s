.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra

write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra

remainder_abc:
  move $fp, $sp
  addi $sp, $sp, -36
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -12($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -16($fp)
  move $t2, $a0
  lw $t3, -8($fp)
  move $a0, $t3
  lw $t4, -20($fp)
  move $t4, $a0
  move $a1, $t2
  move $a2, $t4
  div $a1, $a2
  mflo $a0
  lw $t5, -24($fp)
  move $t5, $a0
  move $a0, $t3
  lw $t6, -28($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -32($fp)
  move $t7, $a0
  move $a1, $t1
  move $a2, $t7
  sub $a0, $a1, $a2
  lw $t0, -36($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -12($fp)
  sw $t2, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  sw $t0, -36($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -92
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t0, -4($fp)
  move $t0, $v0
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t2, -12($fp)
  move $t2, $v0
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  move $a0, $t1
  lw $t4, -20($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -24($fp)
  move $t5, $a0
  move $a0, $t3
  lw $t6, -28($fp)
  move $t6, $a0
  move $a0, $t6
  lw $t7, -32($fp)
  move $t7, $a0
  sw $t0, -4($fp)
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
label1:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -36($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -40($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -36($fp)
  sw $t2, -40($fp)
  bne $a1, $a2, label2
  j label3
label2:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -44($fp)
  move $t1, $a0
  lw $t2, -16($fp)
  move $a0, $t2
  lw $t3, -48($fp)
  move $t3, $a0
  move $a1, $t3
  move $a0, $t1
  addi $sp, $sp, -40
  sw $ra, 36($sp)
  sw $fp, 32($sp)
  sw $t0, 28($sp)
  sw $t1, 24($sp)
  sw $t2, 20($sp)
  sw $t3, 16($sp)
  sw $t4, 12($sp)
  sw $t5, 8($sp)
  sw $t6, 4($sp)
  sw $t7, 0($sp)
  jal remainder_abc
  lw $ra, 36($sp)
  lw $fp, 32($sp)
  lw $t0, 28($sp)
  lw $t1, 24($sp)
  lw $t2, 20($sp)
  lw $t3, 16($sp)
  lw $t4, 12($sp)
  lw $t5, 8($sp)
  lw $t6, 4($sp)
  lw $t7, 0($sp)
  addi $sp, $sp, 40
  lw $t4, -52($fp)
  move $t4, $v0
  move $a0, $t4
  lw $t5, -56($fp)
  move $t5, $a0
  move $a0, $t2
  lw $t6, -60($fp)
  move $t6, $a0
  move $a0, $t6
  move $t0, $a0
  move $a0, $t5
  lw $t7, -64($fp)
  move $t7, $a0
  move $a0, $t7
  move $t2, $a0
  sw $t0, -8($fp)
  sw $t2, -16($fp)
  sw $t1, -44($fp)
  sw $t3, -48($fp)
  sw $t4, -52($fp)
  sw $t5, -56($fp)
  sw $t6, -60($fp)
  sw $t7, -64($fp)
  j label1
label3:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -68($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t2, -24($fp)
  move $a0, $t2
  lw $t3, -72($fp)
  move $t3, $a0
  lw $t4, -32($fp)
  move $a0, $t4
  lw $t5, -76($fp)
  move $t5, $a0
  move $a1, $t3
  move $a2, $t5
  mul $a0, $a1, $a2
  lw $t6, -80($fp)
  move $t6, $a0
  move $a0, $t0
  lw $t7, -84($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  div $a1, $a2
  mflo $a0
  lw $t0, -88($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  sw $t0, -88($fp)
  lw $t0, -92($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -68($fp)
  sw $t3, -72($fp)
  sw $t5, -76($fp)
  sw $t6, -80($fp)
  sw $t7, -84($fp)
  sw $t0, -92($fp)
  jr $ra
