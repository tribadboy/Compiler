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

setInit_abc:
  move $fp, $sp
  addi $sp, $sp, -36
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -12($fp)
  move $t1, $a0
  move $a0, $t1
  lw $t2, -16($fp)
  move $t2, $a0
  lw $t3, -8($fp)
  move $a0, $t3
  lw $t4, -20($fp)
  move $t4, $a0
  move $a0, $t4
  sw $a0, 0($t2)
  move $a0, $t0
  lw $t5, -24($fp)
  move $t5, $a0
  move $a1, $t5
  li $a2, 4
  add $a0, $a1, $a2
  lw $t6, -28($fp)
  move $t6, $a0
  li $a0, 0
  lw $t7, -32($fp)
  move $t7, $a0
  move $a0, $t7
  sw $a0, 0($t6)
  li $a0, 0
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

addLog_abc:
  move $fp, $sp
  addi $sp, $sp, -140
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  sw $a2, -12($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -16($fp)
  move $t1, $a0
  move $a1, $t1
  li $a2, 4
  add $a0, $a1, $a2
  lw $t2, -20($fp)
  move $t2, $a0
  move $a0, $t0
  lw $t3, -24($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  add $a0, $a1, $a2
  lw $t4, -28($fp)
  move $t4, $a0
  lw $a0, 0($t4)
  lw $t5, -32($fp)
  move $t5, $a0
  li $a0, 1
  lw $t6, -36($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  add $a0, $a1, $a2
  lw $t7, -40($fp)
  move $t7, $a0
  move $a0, $t7
  sw $a0, 0($t2)
  move $a0, $t0
  lw $t0, -44($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  add $a0, $a1, $a2
  sw $t0, -44($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  sw $t0, -48($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t0, -52($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -52($fp)
  lw $t0, -56($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -56($fp)
  lw $t0, -60($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  sw $t0, -64($fp)
  lw $t0, -60($fp)
  move $a1, $t0
  lw $t0, -64($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -68($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -68($fp)
  lw $t0, -72($fp)
  move $t0, $a0
  sw $t0, -72($fp)
  lw $t0, -48($fp)
  move $a1, $t0
  lw $t0, -72($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -76($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -80($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  sw $t0, -84($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -88($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -88($fp)
  lw $t0, -84($fp)
  sw $a0, 0($t0)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t0, -92($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  add $a0, $a1, $a2
  sw $t0, -92($fp)
  lw $t0, -96($fp)
  move $t0, $a0
  sw $t0, -96($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t0, -100($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -104($fp)
  lw $t0, -108($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -108($fp)
  lw $t0, -112($fp)
  move $t0, $a0
  sw $t0, -112($fp)
  lw $t0, -108($fp)
  move $a1, $t0
  lw $t0, -112($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -116($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -116($fp)
  lw $t0, -120($fp)
  move $t0, $a0
  sw $t0, -120($fp)
  lw $t0, -96($fp)
  move $a1, $t0
  lw $t0, -120($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -124($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -124($fp)
  lw $t0, -128($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -128($fp)
  lw $t0, -132($fp)
  move $t0, $a0
  sw $t0, -132($fp)
  lw $t0, -12($fp)
  move $a0, $t0
  lw $t0, -136($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -136($fp)
  lw $t0, -132($fp)
  sw $a0, 0($t0)
  li $a0, 0
  lw $t0, -140($fp)
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
  sw $t0, -140($fp)
  jr $ra

weight_Now_abc:
  move $fp, $sp
  addi $sp, $sp, -96
  sw $a0, -4($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  lw $a0, 0($t1)
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
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
label1:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -32($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  add $a0, $a1, $a2
  lw $t4, -36($fp)
  move $t4, $a0
  lw $a0, 0($t4)
  lw $t5, -40($fp)
  move $t5, $a0
  move $a1, $t1
  move $a2, $t5
  sw $t1, -28($fp)
  sw $t3, -32($fp)
  sw $t4, -36($fp)
  sw $t5, -40($fp)
  blt $a1, $a2, label2
  j label3
label2:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -44($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -48($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 8
  add $a0, $a1, $a2
  lw $t4, -52($fp)
  move $t4, $a0
  lw $t5, -24($fp)
  move $a0, $t5
  lw $t6, -56($fp)
  move $t6, $a0
  move $a1, $t6
  li $a2, 8
  mul $a0, $a1, $a2
  lw $t7, -60($fp)
  move $t7, $a0
  move $a1, $t4
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -64($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -68($fp)
  lw $t0, -72($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -72($fp)
  lw $t0, -76($fp)
  move $t0, $a0
  move $a1, $t1
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -80($fp)
  lw $t0, -16($fp)
  move $t0, $a0
  move $a0, $t5
  sw $t0, -16($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -84($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  sw $t0, -88($fp)
  lw $t0, -84($fp)
  move $a1, $t0
  lw $t0, -88($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -92($fp)
  move $t0, $a0
  move $a0, $t0
  move $t5, $a0
  sw $t5, -24($fp)
  sw $t1, -44($fp)
  sw $t3, -48($fp)
  sw $t4, -52($fp)
  sw $t6, -56($fp)
  sw $t7, -60($fp)
  sw $t0, -92($fp)
  j label1
label3:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -96($fp)
  move $t1, $a0
  move $sp, $fp
  move $v0, $t1
  sw $t1, -96($fp)
  jr $ra

average_Lose_abc:
  move $fp, $sp
  addi $sp, $sp, -152
  sw $a0, -4($fp)
  li $a0, 0
  lw $t0, -8($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -12($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -16($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -20($fp)
  move $t3, $a0
  li $a0, 0
  lw $t4, -24($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -28($fp)
  move $t5, $a0
  li $a0, 0
  lw $t6, -32($fp)
  move $t6, $a0
  move $a0, $t6
  lw $t7, -36($fp)
  move $t7, $a0
  sw $t0, -8($fp)
  sw $t1, -12($fp)
  sw $t2, -16($fp)
  sw $t3, -20($fp)
  sw $t4, -24($fp)
  sw $t5, -28($fp)
  sw $t6, -32($fp)
  sw $t7, -36($fp)
label4:
  lw $t0, -20($fp)
  move $a0, $t0
  lw $t1, -40($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -44($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  add $a0, $a1, $a2
  lw $t4, -48($fp)
  move $t4, $a0
  lw $a0, 0($t4)
  lw $t5, -52($fp)
  move $t5, $a0
  move $a1, $t1
  move $a2, $t5
  sw $t1, -40($fp)
  sw $t3, -44($fp)
  sw $t4, -48($fp)
  sw $t5, -52($fp)
  blt $a1, $a2, label5
  j label6
label5:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -56($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -60($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 8
  add $a0, $a1, $a2
  lw $t4, -64($fp)
  move $t4, $a0
  lw $t5, -20($fp)
  move $a0, $t5
  lw $t6, -68($fp)
  move $t6, $a0
  move $a1, $t6
  li $a2, 8
  mul $a0, $a1, $a2
  lw $t7, -72($fp)
  move $t7, $a0
  move $a1, $t4
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -76($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -80($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  move $a1, $t1
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -84($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -88($fp)
  lw $t0, -28($fp)
  move $t0, $a0
  sw $t0, -28($fp)
  lw $t0, -36($fp)
  move $a0, $t0
  lw $t0, -92($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -92($fp)
  lw $t0, -96($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  add $a0, $a1, $a2
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  move $a0, $t5
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -104($fp)
  lw $t0, -108($fp)
  move $t0, $a0
  sw $t0, -108($fp)
  lw $t0, -100($fp)
  move $a1, $t0
  lw $t0, -108($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -112($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -116($fp)
  lw $t0, -120($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -120($fp)
  lw $t0, -124($fp)
  move $t0, $a0
  sw $t0, -124($fp)
  lw $t0, -92($fp)
  move $a1, $t0
  lw $t0, -124($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -128($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -128($fp)
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t5
  sw $t0, -36($fp)
  lw $t0, -132($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -132($fp)
  lw $t0, -136($fp)
  move $t0, $a0
  sw $t0, -136($fp)
  lw $t0, -132($fp)
  move $a1, $t0
  lw $t0, -136($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -140($fp)
  move $t0, $a0
  move $a0, $t0
  move $t5, $a0
  sw $t5, -20($fp)
  sw $t1, -56($fp)
  sw $t3, -60($fp)
  sw $t4, -64($fp)
  sw $t6, -68($fp)
  sw $t7, -72($fp)
  sw $t0, -140($fp)
  j label4
label6:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -144($fp)
  move $t1, $a0
  lw $t2, -36($fp)
  move $a0, $t2
  lw $t3, -148($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  div $a1, $a2
  mflo $a0
  lw $t4, -152($fp)
  move $t4, $a0
  move $sp, $fp
  move $v0, $t4
  sw $t1, -144($fp)
  sw $t3, -148($fp)
  sw $t4, -152($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -144
  addi $t0, $fp, -48
  move $a0, $t0
  lw $t1, -52($fp)
  move $t1, $a0
  li $a0, 55
  lw $t2, -56($fp)
  move $t2, $a0
  move $a1, $t2
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
  jal setInit_abc
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
  lw $t3, -60($fp)
  move $t3, $v0
  move $a0, $t0
  lw $t4, -64($fp)
  move $t4, $a0
  li $a0, 6
  lw $t5, -68($fp)
  move $t5, $a0
  li $a0, 2
  lw $t6, -72($fp)
  move $t6, $a0
  move $a2, $t6
  move $a1, $t5
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
  jal addLog_abc
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
  lw $t7, -76($fp)
  move $t7, $v0
  move $a0, $t0
  lw $t0, -80($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -80($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -84($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  move $a2, $t0
  sw $t0, -88($fp)
  lw $t0, -84($fp)
  move $a1, $t0
  lw $t0, -80($fp)
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
  jal addLog_abc
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
  lw $t0, -92($fp)
  move $t0, $v0
  sw $t0, -92($fp)
  addi $t0, $fp, -48
  move $a0, $t0
  lw $t0, -96($fp)
  move $t0, $a0
  li $a0, 20
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  li $a0, 4
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  move $a2, $t0
  sw $t0, -104($fp)
  lw $t0, -100($fp)
  move $a1, $t0
  lw $t0, -96($fp)
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
  jal addLog_abc
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
  lw $t0, -108($fp)
  move $t0, $v0
  sw $t0, -108($fp)
  addi $t0, $fp, -48
  move $a0, $t0
  lw $t0, -112($fp)
  move $t0, $a0
  li $a0, 4
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -116($fp)
  lw $t0, -120($fp)
  move $t0, $a0
  move $a2, $t0
  sw $t0, -120($fp)
  lw $t0, -116($fp)
  move $a1, $t0
  lw $t0, -112($fp)
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
  jal addLog_abc
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
  lw $t0, -124($fp)
  move $t0, $v0
  sw $t0, -124($fp)
  addi $t0, $fp, -48
  move $a0, $t0
  lw $t0, -128($fp)
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
  jal weight_Now_abc
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
  sw $t0, -128($fp)
  lw $t0, -132($fp)
  move $t0, $v0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -132($fp)
  addi $t0, $fp, -48
  move $a0, $t0
  lw $t0, -136($fp)
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
  jal average_Lose_abc
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
  sw $t0, -136($fp)
  lw $t0, -140($fp)
  move $t0, $v0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  sw $t0, -140($fp)
  lw $t0, -144($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -52($fp)
  sw $t2, -56($fp)
  sw $t3, -60($fp)
  sw $t4, -64($fp)
  sw $t5, -68($fp)
  sw $t6, -72($fp)
  sw $t7, -76($fp)
  sw $t0, -144($fp)
  jr $ra
