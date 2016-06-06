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

add_abc:
  move $fp, $sp
  addi $sp, $sp, -28
  sw $a0, -4($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  lw $a0, 0($t1)
  lw $t2, -12($fp)
  move $t2, $a0
  move $a0, $t0
  lw $t3, -16($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  add $a0, $a1, $a2
  lw $t4, -20($fp)
  move $t4, $a0
  lw $a0, 0($t4)
  lw $t5, -24($fp)
  move $t5, $a0
  move $a1, $t2
  move $a2, $t5
  add $a0, $a1, $a2
  lw $t6, -28($fp)
  move $t6, $a0
  move $sp, $fp
  move $v0, $t6
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -108
  li $a0, 0
  lw $t0, -4($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  addi $t2, $fp, -64
  move $a0, $t2
  lw $t3, -68($fp)
  move $t3, $a0
  move $a0, $t3
  lw $t4, -72($fp)
  move $t4, $a0
  li $a0, 1
  lw $t5, -76($fp)
  move $t5, $a0
  move $a0, $t5
  sw $a0, 0($t4)
  move $a0, $t2
  lw $t6, -80($fp)
  move $t6, $a0
  move $a1, $t6
  li $a2, 4
  add $a0, $a1, $a2
  lw $t7, -84($fp)
  move $t7, $a0
  li $a0, 2
  sw $t0, -4($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  move $a0, $t0
  sw $a0, 0($t7)
  move $a0, $t2
  sw $t0, -88($fp)
  lw $t0, -92($fp)
  move $t0, $a0
  move $a0, $t0
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
  jal add_abc
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
  sw $t0, -92($fp)
  lw $t0, -96($fp)
  move $t0, $v0
  move $a0, $t0
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  sw $t0, -104($fp)
  lw $t0, -108($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -8($fp)
  sw $t3, -68($fp)
  sw $t4, -72($fp)
  sw $t5, -76($fp)
  sw $t6, -80($fp)
  sw $t7, -84($fp)
  sw $t0, -108($fp)
  jr $ra
