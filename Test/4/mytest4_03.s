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

check_abc:
  move $fp, $sp
  addi $sp, $sp, -140
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  sw $a2, -12($fp)
  sw $a3, -16($fp)
  lw $a0, 40($fp)
  sw $a0, -20($fp)
  lw $a0, 44($fp)
  sw $a0, -24($fp)
  lw $a0, 48($fp)
  sw $a0, -28($fp)
  lw $a0, 52($fp)
  sw $a0, -32($fp)
  li $a0, 0
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -40($fp)
  move $t1, $a0
  move $a0, $t1
  lw $t2, -44($fp)
  move $t2, $a0
  lw $t3, -4($fp)
  move $a0, $t3
  lw $t4, -48($fp)
  move $t4, $a0
  move $a1, $t2
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -52($fp)
  move $t5, $a0
  move $a0, $t5
  move $t1, $a0
  move $a0, $t1
  lw $t6, -56($fp)
  move $t6, $a0
  lw $t7, -8($fp)
  move $a0, $t7
  sw $t0, -36($fp)
  lw $t0, -60($fp)
  move $t0, $a0
  move $a1, $t6
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  move $a0, $t0
  move $t1, $a0
  move $a0, $t1
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  sw $t0, -68($fp)
  lw $t0, -12($fp)
  move $a0, $t0
  lw $t0, -72($fp)
  move $t0, $a0
  sw $t0, -72($fp)
  lw $t0, -68($fp)
  move $a1, $t0
  lw $t0, -72($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -76($fp)
  move $t0, $a0
  move $a0, $t0
  move $t1, $a0
  move $a0, $t1
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  sw $t0, -80($fp)
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t0, -84($fp)
  move $t0, $a0
  sw $t0, -84($fp)
  lw $t0, -80($fp)
  move $a1, $t0
  lw $t0, -84($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -88($fp)
  move $t0, $a0
  move $a0, $t0
  move $t1, $a0
  move $a0, $t1
  sw $t0, -88($fp)
  lw $t0, -92($fp)
  move $t0, $a0
  sw $t0, -92($fp)
  lw $t0, -20($fp)
  move $a0, $t0
  lw $t0, -96($fp)
  move $t0, $a0
  sw $t0, -96($fp)
  lw $t0, -92($fp)
  move $a1, $t0
  lw $t0, -96($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -100($fp)
  move $t0, $a0
  move $a0, $t0
  move $t1, $a0
  move $a0, $t1
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  sw $t0, -104($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -108($fp)
  move $t0, $a0
  sw $t0, -108($fp)
  lw $t0, -104($fp)
  move $a1, $t0
  lw $t0, -108($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -112($fp)
  move $t0, $a0
  move $a0, $t0
  move $t1, $a0
  move $a0, $t1
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  sw $t0, -116($fp)
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t0, -120($fp)
  move $t0, $a0
  sw $t0, -120($fp)
  lw $t0, -116($fp)
  move $a1, $t0
  lw $t0, -120($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -124($fp)
  move $t0, $a0
  move $a0, $t0
  move $t1, $a0
  move $a0, $t1
  sw $t0, -124($fp)
  lw $t0, -128($fp)
  move $t0, $a0
  sw $t0, -128($fp)
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t0, -132($fp)
  move $t0, $a0
  sw $t0, -132($fp)
  lw $t0, -128($fp)
  move $a1, $t0
  lw $t0, -132($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -136($fp)
  move $t0, $a0
  move $a0, $t0
  move $t1, $a0
  move $a0, $t1
  sw $t0, -136($fp)
  lw $t0, -140($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -40($fp)
  sw $t2, -44($fp)
  sw $t4, -48($fp)
  sw $t5, -52($fp)
  sw $t6, -56($fp)
  sw $t0, -140($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -92
  li $a0, 1
  lw $t0, -4($fp)
  move $t0, $a0
  li $a0, 2
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 3
  lw $t2, -12($fp)
  move $t2, $a0
  li $a0, 4
  lw $t3, -16($fp)
  move $t3, $a0
  li $a0, 5
  lw $t4, -20($fp)
  move $t4, $a0
  li $a0, 6
  lw $t5, -24($fp)
  move $t5, $a0
  li $a0, 7
  lw $t6, -28($fp)
  move $t6, $a0
  li $a0, 8
  lw $t7, -32($fp)
  move $t7, $a0
  addi, $sp, $sp, -16
  move $a0, $t7
  sw $a0, 12($sp)
  move $a0, $t6
  sw $a0, 8($sp)
  move $a0, $t5
  sw $a0, 4($sp)
  move $a0, $t4
  sw $a0, 0($sp)
  move $a3, $t3
  move $a2, $t2
  move $a1, $t1
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
  jal check_abc
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
  sw $t0, -4($fp)
  lw $t0, -36($fp)
  move $t0, $v0
  move $a0, $t0
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  li $a0, 8
  sw $t0, -40($fp)
  lw $t0, -44($fp)
  move $t0, $a0
  li $a0, 7
  sw $t0, -44($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  li $a0, 6
  sw $t0, -48($fp)
  lw $t0, -52($fp)
  move $t0, $a0
  li $a0, 5
  sw $t0, -52($fp)
  lw $t0, -56($fp)
  move $t0, $a0
  li $a0, 4
  sw $t0, -56($fp)
  lw $t0, -60($fp)
  move $t0, $a0
  li $a0, 3
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -68($fp)
  lw $t0, -72($fp)
  move $t0, $a0
  addi, $sp, $sp, -16
  move $a0, $t0
  sw $a0, 12($sp)
  sw $t0, -72($fp)
  lw $t0, -68($fp)
  move $a0, $t0
  sw $a0, 8($sp)
  lw $t0, -64($fp)
  move $a0, $t0
  sw $a0, 4($sp)
  lw $t0, -60($fp)
  move $a0, $t0
  sw $a0, 0($sp)
  lw $t0, -56($fp)
  move $a3, $t0
  lw $t0, -52($fp)
  move $a2, $t0
  lw $t0, -48($fp)
  move $a1, $t0
  lw $t0, -44($fp)
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
  jal check_abc
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
  lw $t0, -76($fp)
  move $t0, $v0
  move $a0, $t0
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  sw $t0, -80($fp)
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t0, -84($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -84($fp)
  lw $t0, -80($fp)
  move $a0, $t0
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
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  sw $t0, -92($fp)
  jr $ra
