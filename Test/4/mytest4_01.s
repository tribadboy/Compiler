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

main:
  move $fp, $sp
  addi $sp, $sp, -84
  li $a0, 0
  lw $t0, -4($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -12($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  li $a0, 0
  lw $t4, -20($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -24($fp)
  move $t5, $a0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t6, -28($fp)
  move $t6, $v0
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
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -36($fp)
  move $t1, $a0
  lw $t2, -32($fp)
  move $a0, $t2
  lw $t3, -40($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -36($fp)
  sw $t3, -40($fp)
  blt $a1, $a2, label2
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
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -52($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -56($fp)
  move $t5, $a0
  move $a0, $t2
  lw $t6, -60($fp)
  move $t6, $a0
  move $a0, $t6
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $a0, $t2
  lw $t7, -64($fp)
  move $t7, $a0
  move $a0, $t7
  move $t0, $a0
  move $a0, $t5
  sw $t0, -8($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  move $a0, $t0
  move $t2, $a0
  sw $t0, -68($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -72($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -72($fp)
  lw $t0, -76($fp)
  move $t0, $a0
  sw $t0, -76($fp)
  lw $t0, -72($fp)
  move $a1, $t0
  lw $t0, -76($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -80($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -80($fp)
  lw $t0, -24($fp)
  move $t0, $a0
  sw $t2, -16($fp)
  sw $t0, -24($fp)
  sw $t1, -44($fp)
  sw $t3, -48($fp)
  sw $t4, -52($fp)
  sw $t5, -56($fp)
  sw $t6, -60($fp)
  sw $t7, -64($fp)
  j label1
label3:
  li $a0, 0
  lw $t0, -84($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -84($fp)
  jr $ra
