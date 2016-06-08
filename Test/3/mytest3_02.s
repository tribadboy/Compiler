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

fact_abc:
  move $fp, $sp
  addi $sp, $sp, -40
  sw $a0, -4($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -12($fp)
  move $t2, $a0
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  beq $t1, $t2, label1
  j label2
label1:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -16($fp)
  move $t1, $a0
  move $sp, $fp
  move $v0, $t1
  sw $t1, -16($fp)
  jr $ra
  j label3
label2:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -20($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -24($fp)
  move $t2, $a0
  li $a0, 1
  lw $t3, -28($fp)
  move $t3, $a0
  move $a1, $t2
  move $a2, $t3
  sub $a0, $a1, $a2
  lw $t4, -32($fp)
  move $t4, $a0
  move $a0, $t4
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
  jal fact_abc
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
  lw $t5, -36($fp)
  move $t5, $v0
  move $a1, $t1
  move $a2, $t5
  mul $a0, $a1, $a2
  lw $t6, -40($fp)
  move $t6, $a0
  move $sp, $fp
  move $v0, $t6
  sw $t1, -20($fp)
  sw $t2, -24($fp)
  sw $t3, -28($fp)
  sw $t4, -32($fp)
  sw $t5, -36($fp)
  sw $t6, -40($fp)
  jr $ra
label3:

main:
  move $fp, $sp
  addi $sp, $sp, -40
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
  move $a0, $t1
  lw $t2, -12($fp)
  move $t2, $a0
  li $a0, 1
  lw $t3, -16($fp)
  move $t3, $a0
  sw $t0, -4($fp)
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  bgt $t2, $t3, label4
  j label5
label4:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -20($fp)
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
  jal fact_abc
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
  lw $t2, -24($fp)
  move $t2, $v0
  move $a0, $t2
  lw $t3, -28($fp)
  move $t3, $a0
  sw $t1, -20($fp)
  sw $t2, -24($fp)
  sw $t3, -28($fp)
  j label6
label5:
  li $a0, 1
  lw $t0, -32($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  sw $t1, -28($fp)
  sw $t0, -32($fp)
label6:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -36($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  lw $t2, -40($fp)
  move $t2, $a0
  move $sp, $fp
  move $v0, $t2
  sw $t1, -36($fp)
  sw $t2, -40($fp)
  jr $ra
