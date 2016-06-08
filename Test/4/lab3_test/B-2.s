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
  addi $sp, $sp, -48
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
  li $a0, 0
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  sw $t0, -40($fp)
  lw $t0, -36($fp)
  move $a1, $t0
  lw $t0, -40($fp)
  move $a2, $t0
  sw $t1, -12($fp)
  sw $t2, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  beq $a1, $a2, label1
  j label2
label1:
  li $a0, 0
  lw $t0, -44($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -44($fp)
  jr $ra
  j label3
label2:
  li $a0, 1
  lw $t0, -48($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -48($fp)
  jr $ra
label3:

prime_Number_abc:
  move $fp, $sp
  addi $sp, $sp, -56
  sw $a0, -4($fp)
  li $a0, 2
  lw $t0, -8($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -12($fp)
  move $t1, $a0
  sw $t0, -8($fp)
  sw $t1, -12($fp)
label4:
  lw $t0, -12($fp)
  move $a0, $t0
  lw $t1, -16($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -20($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -16($fp)
  sw $t3, -20($fp)
  blt $a1, $a2, label5
  j label6
label5:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -24($fp)
  move $t1, $a0
  lw $t2, -12($fp)
  move $a0, $t2
  lw $t3, -28($fp)
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
  lw $t4, -32($fp)
  move $t4, $v0
  li $a0, 0
  lw $t5, -36($fp)
  move $t5, $a0
  move $a1, $t4
  move $a2, $t5
  sw $t1, -24($fp)
  sw $t3, -28($fp)
  sw $t4, -32($fp)
  sw $t5, -36($fp)
  beq $a1, $a2, label7
  j label8
label7:
  li $a0, 0
  lw $t0, -40($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -40($fp)
  jr $ra
label8:
  lw $t0, -12($fp)
  move $a0, $t0
  lw $t1, -44($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -48($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -52($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  sw $t0, -12($fp)
  sw $t1, -44($fp)
  sw $t2, -48($fp)
  sw $t3, -52($fp)
  j label4
label6:
  li $a0, 1
  lw $t0, -56($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -56($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -64
  li $a0, 2
  lw $t0, -4($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 20
  lw $t2, -12($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  move $a0, $t1
  lw $t4, -20($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -24($fp)
  move $t5, $a0
  sw $t0, -4($fp)
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
label9:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  lw $t2, -16($fp)
  move $a0, $t2
  lw $t3, -32($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -28($fp)
  sw $t3, -32($fp)
  blt $a1, $a2, label10
  j label11
label10:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -36($fp)
  move $t1, $a0
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
  jal prime_Number_abc
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
  lw $t2, -40($fp)
  move $t2, $v0
  li $a0, 1
  lw $t3, -44($fp)
  move $t3, $a0
  move $a1, $t2
  move $a2, $t3
  sw $t1, -36($fp)
  sw $t2, -40($fp)
  sw $t3, -44($fp)
  beq $a1, $a2, label12
  j label13
label12:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -48($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t1, -48($fp)
label13:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -52($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -56($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -60($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  sw $t0, -24($fp)
  sw $t1, -52($fp)
  sw $t2, -56($fp)
  sw $t3, -60($fp)
  j label9
label11:
  li $a0, 0
  lw $t0, -64($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -64($fp)
  jr $ra
