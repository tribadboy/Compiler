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

purchase_abc:
  move $fp, $sp
  addi $sp, $sp, -32
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  sw $a2, -12($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -16($fp)
  move $t1, $a0
  lw $t2, -8($fp)
  move $a0, $t2
  lw $t3, -20($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  mul $a0, $a1, $a2
  lw $t4, -24($fp)
  move $t4, $a0
  lw $t5, -12($fp)
  move $a0, $t5
  lw $t6, -28($fp)
  move $t6, $a0
  move $a1, $t4
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -32($fp)
  move $t7, $a0
  move $sp, $fp
  move $v0, $t7
  sw $t1, -16($fp)
  sw $t3, -20($fp)
  sw $t4, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  jr $ra

sum_abc:
  move $fp, $sp
  addi $sp, $sp, -20
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -12($fp)
  move $t1, $a0
  lw $t2, -8($fp)
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -20($fp)
  move $t4, $a0
  move $sp, $fp
  move $v0, $t4
  sw $t1, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -160
  addi $t0, $fp, -12
  move $a0, $t0
  lw $t1, -16($fp)
  move $t1, $a0
  move $a0, $t1
  lw $t2, -20($fp)
  move $t2, $a0
  li $a0, 2
  lw $t3, -24($fp)
  move $t3, $a0
  move $a0, $t3
  sw $a0, 0($t2)
  move $a0, $t0
  lw $t4, -28($fp)
  move $t4, $a0
  move $a1, $t4
  li $a2, 4
  add $a0, $a1, $a2
  lw $t5, -32($fp)
  move $t5, $a0
  li $a0, 5
  lw $t6, -36($fp)
  move $t6, $a0
  move $a0, $t6
  sw $a0, 0($t5)
  move $a0, $t0
  lw $t7, -40($fp)
  move $t7, $a0
  move $a1, $t7
  li $a2, 8
  add $a0, $a1, $a2
  lw $t0, -44($fp)
  move $t0, $a0
  li $a0, 4
  sw $t0, -44($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -48($fp)
  lw $t0, -44($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -12
  move $a0, $t0
  lw $t0, -52($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -52($fp)
  lw $t0, -56($fp)
  move $t0, $a0
  sw $t0, -56($fp)
  addi $t0, $fp, -12
  move $a0, $t0
  lw $t0, -60($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  sw $t0, -68($fp)
  addi $t0, $fp, -12
  move $a0, $t0
  lw $t0, -72($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  add $a0, $a1, $a2
  sw $t0, -72($fp)
  lw $t0, -76($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  move $a2, $t0
  sw $t0, -80($fp)
  lw $t0, -68($fp)
  move $a1, $t0
  lw $t0, -56($fp)
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
  jal purchase_abc
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
  lw $t0, -84($fp)
  move $t0, $v0
  move $a0, $t0
  sw $t0, -84($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  sw $t0, -88($fp)
  addi $t0, $fp, -12
  move $a0, $t0
  lw $t0, -92($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -92($fp)
  lw $t0, -96($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  sw $t0, -100($fp)
  lw $t0, -96($fp)
  move $a1, $t0
  lw $t0, -100($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -104($fp)
  move $t0, $a0
  sw $t0, -104($fp)
  addi $t0, $fp, -12
  move $a0, $t0
  lw $t0, -108($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -108($fp)
  lw $t0, -112($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -116($fp)
  lw $t0, -120($fp)
  move $t0, $a0
  sw $t0, -120($fp)
  lw $t0, -116($fp)
  move $a1, $t0
  lw $t0, -120($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -124($fp)
  move $t0, $a0
  sw $t0, -124($fp)
  addi $t0, $fp, -12
  move $a0, $t0
  lw $t0, -128($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  add $a0, $a1, $a2
  sw $t0, -128($fp)
  lw $t0, -132($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -132($fp)
  lw $t0, -136($fp)
  move $t0, $a0
  move $a2, $t0
  sw $t0, -136($fp)
  lw $t0, -124($fp)
  move $a1, $t0
  lw $t0, -104($fp)
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
  jal purchase_abc
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
  lw $t0, -140($fp)
  move $t0, $v0
  move $a0, $t0
  sw $t0, -140($fp)
  lw $t0, -144($fp)
  move $t0, $a0
  sw $t0, -144($fp)
  lw $t0, -88($fp)
  move $a0, $t0
  lw $t0, -148($fp)
  move $t0, $a0
  sw $t0, -148($fp)
  lw $t0, -144($fp)
  move $a0, $t0
  lw $t0, -152($fp)
  move $t0, $a0
  move $a1, $t0
  sw $t0, -152($fp)
  lw $t0, -148($fp)
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
  jal sum_abc
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
  lw $t0, -156($fp)
  move $t0, $v0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  sw $t0, -156($fp)
  lw $t0, -160($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -16($fp)
  sw $t2, -20($fp)
  sw $t3, -24($fp)
  sw $t4, -28($fp)
  sw $t5, -32($fp)
  sw $t6, -36($fp)
  sw $t7, -40($fp)
  sw $t0, -160($fp)
  jr $ra
