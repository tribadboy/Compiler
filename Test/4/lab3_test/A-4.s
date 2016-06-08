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

abs_abc:
  move $fp, $sp
  addi $sp, $sp, -24
  sw $a0, -4($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -12($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  blt $a1, $a2, label1
  j label2
label1:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -16($fp)
  move $t1, $a0
  li $a1, 0
  move $a2, $t1
  sub $a0, $a1, $a2
  lw $t2, -20($fp)
  move $t2, $a0
  move $sp, $fp
  move $v0, $t2
  sw $t1, -16($fp)
  sw $t2, -20($fp)
  jr $ra
  j label3
label2:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -24($fp)
  move $t1, $a0
  move $sp, $fp
  move $v0, $t1
  sw $t1, -24($fp)
  jr $ra
label3:

multAbs_abc:
  move $fp, $sp
  addi $sp, $sp, -28
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -12($fp)
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
  jal abs_abc
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
  lw $t2, -16($fp)
  move $t2, $v0
  lw $t3, -8($fp)
  move $a0, $t3
  lw $t4, -20($fp)
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
  jal abs_abc
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
  lw $t5, -24($fp)
  move $t5, $v0
  move $a1, $t2
  move $a2, $t5
  mul $a0, $a1, $a2
  lw $t6, -28($fp)
  move $t6, $a0
  move $sp, $fp
  move $v0, $t6
  sw $t1, -12($fp)
  sw $t2, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -200
  li $a0, 0
  lw $t0, -24($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -32($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -36($fp)
  move $t3, $a0
  sw $t0, -24($fp)
  sw $t1, -28($fp)
  sw $t2, -32($fp)
  sw $t3, -36($fp)
label4:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -40($fp)
  move $t1, $a0
  li $a0, 5
  lw $t2, -44($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -40($fp)
  sw $t2, -44($fp)
  blt $a1, $a2, label5
  j label6
label5:
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t1, -48($fp)
  move $t1, $a0
  lw $t2, -28($fp)
  move $a0, $t2
  lw $t3, -52($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -56($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -60($fp)
  move $t5, $a0
  move $a0, $t2
  lw $t6, -64($fp)
  move $t6, $a0
  move $a0, $t2
  lw $t7, -68($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  mul $a0, $a1, $a2
  lw $t0, -72($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -72($fp)
  lw $t0, -76($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -80($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  sw $t0, -84($fp)
  lw $t0, -80($fp)
  move $a1, $t0
  lw $t0, -84($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -88($fp)
  move $t0, $a0
  sw $t0, -88($fp)
  lw $t0, -76($fp)
  move $a1, $t0
  lw $t0, -88($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -92($fp)
  move $t0, $a0
  sw $t0, -92($fp)
  lw $t0, -72($fp)
  move $a1, $t0
  lw $t0, -92($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -96($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  li $a0, 4
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  sw $t0, -104($fp)
  lw $t0, -100($fp)
  move $a1, $t0
  lw $t0, -104($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -108($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -108($fp)
  lw $t0, -112($fp)
  move $t0, $a0
  sw $t0, -112($fp)
  lw $t0, -108($fp)
  move $a1, $t0
  lw $t0, -112($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -116($fp)
  move $t0, $a0
  sw $t0, -116($fp)
  lw $t0, -96($fp)
  move $a1, $t0
  lw $t0, -116($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -120($fp)
  move $t0, $a0
  move $a0, $t0
  sw $a0, 0($t5)
  move $a0, $t2
  sw $t0, -120($fp)
  lw $t0, -124($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -124($fp)
  lw $t0, -128($fp)
  move $t0, $a0
  sw $t0, -128($fp)
  lw $t0, -124($fp)
  move $a1, $t0
  lw $t0, -128($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -132($fp)
  move $t0, $a0
  move $a0, $t0
  move $t2, $a0
  sw $t2, -28($fp)
  sw $t1, -48($fp)
  sw $t3, -52($fp)
  sw $t4, -56($fp)
  sw $t5, -60($fp)
  sw $t6, -64($fp)
  sw $t7, -68($fp)
  sw $t0, -132($fp)
  j label4
label6:
  li $a0, 0
  lw $t0, -136($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  sw $t1, -28($fp)
  sw $t0, -136($fp)
label7:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -140($fp)
  move $t1, $a0
  li $a0, 5
  lw $t2, -144($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -140($fp)
  sw $t2, -144($fp)
  blt $a1, $a2, label8
  j label9
label8:
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t1, -148($fp)
  move $t1, $a0
  lw $t2, -28($fp)
  move $a0, $t2
  lw $t3, -152($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -156($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -160($fp)
  move $t5, $a0
  lw $a0, 0($t5)
  lw $t6, -164($fp)
  move $t6, $a0
  move $a0, $t6
  lw $t7, -168($fp)
  move $t7, $a0
  lw $t0, -36($fp)
  move $a0, $t0
  lw $t0, -172($fp)
  move $t0, $a0
  move $a0, $t7
  sw $t0, -172($fp)
  lw $t0, -176($fp)
  move $t0, $a0
  move $a1, $t0
  sw $t0, -176($fp)
  lw $t0, -172($fp)
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
  jal multAbs_abc
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
  lw $t0, -180($fp)
  move $t0, $v0
  move $a0, $t0
  sw $t0, -180($fp)
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -36($fp)
  lw $t0, -184($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -184($fp)
  lw $t0, -188($fp)
  move $t0, $a0
  sw $t0, -188($fp)
  lw $t0, -184($fp)
  move $a1, $t0
  lw $t0, -188($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -192($fp)
  move $t0, $a0
  move $a0, $t0
  move $t2, $a0
  sw $t2, -28($fp)
  sw $t1, -148($fp)
  sw $t3, -152($fp)
  sw $t4, -156($fp)
  sw $t5, -160($fp)
  sw $t6, -164($fp)
  sw $t7, -168($fp)
  sw $t0, -192($fp)
  j label7
label9:
  lw $t0, -36($fp)
  move $a0, $t0
  lw $t1, -196($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  lw $t2, -200($fp)
  move $t2, $a0
  move $sp, $fp
  move $v0, $t2
  sw $t1, -196($fp)
  sw $t2, -200($fp)
  jr $ra
