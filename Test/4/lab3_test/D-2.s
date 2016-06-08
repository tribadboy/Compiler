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

power_abc:
  move $fp, $sp
  addi $sp, $sp, -140
  sw $a0, -4($fp)
  sw $a1, -8($fp)
  li $a0, 1
  lw $t0, -12($fp)
  move $t0, $a0
  lw $t1, -8($fp)
  move $a0, $t1
  lw $t2, -16($fp)
  move $t2, $a0
  move $a1, $t0
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -20($fp)
  move $t3, $a0
  move $a0, $t1
  lw $t4, -24($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  sub $a0, $a1, $a2
  lw $t5, -28($fp)
  move $t5, $a0
  move $a0, $t5
  lw $t6, -32($fp)
  move $t6, $a0
  sw $t0, -12($fp)
  sw $t2, -16($fp)
  sw $t3, -20($fp)
  sw $t4, -24($fp)
  sw $t5, -28($fp)
  sw $t6, -32($fp)
label1:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -36($fp)
  move $t1, $a0
  lw $t2, -32($fp)
  move $a0, $t2
  lw $t3, -40($fp)
  move $t3, $a0
  move $a0, $t2
  lw $t4, -44($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  sub $a0, $a1, $a2
  lw $t5, -48($fp)
  move $t5, $a0
  li $a0, 90
  lw $t6, -52($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  add $a0, $a1, $a2
  lw $t7, -56($fp)
  move $t7, $a0
  li $a0, 89
  lw $t0, -60($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  sw $t0, -68($fp)
  lw $t0, -64($fp)
  move $a1, $t0
  lw $t0, -68($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -72($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -72($fp)
  lw $t0, -76($fp)
  move $t0, $a0
  sw $t0, -76($fp)
  lw $t0, -72($fp)
  move $a1, $t0
  lw $t0, -76($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -80($fp)
  move $t0, $a0
  move $a1, $t1
  move $a2, $t0
  sw $t1, -36($fp)
  sw $t3, -40($fp)
  sw $t4, -44($fp)
  sw $t5, -48($fp)
  sw $t6, -52($fp)
  sw $t7, -56($fp)
  sw $t0, -80($fp)
  bgt $a1, $a2, label2
  j label3
label2:
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t1, -84($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -88($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  mul $a0, $a1, $a2
  lw $t4, -92($fp)
  move $t4, $a0
  move $a0, $t4
  move $t0, $a0
  li $a0, 2
  lw $t5, -96($fp)
  move $t5, $a0
  li $a0, 1
  lw $t6, -100($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -104($fp)
  move $t7, $a0
  sw $t0, -32($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -108($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  mul $a0, $a1, $a2
  sw $t0, -108($fp)
  lw $t0, -112($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  sw $t0, -116($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -120($fp)
  move $t0, $a0
  sw $t0, -120($fp)
  lw $t0, -116($fp)
  move $a1, $t0
  lw $t0, -120($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -124($fp)
  move $t0, $a0
  sw $t0, -124($fp)
  lw $t0, -112($fp)
  move $a1, $t0
  lw $t0, -124($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -128($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -128($fp)
  lw $t0, -132($fp)
  move $t0, $a0
  sw $t0, -132($fp)
  lw $t0, -128($fp)
  move $a1, $t0
  lw $t0, -132($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -136($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -136($fp)
  lw $t0, -8($fp)
  move $t0, $a0
  sw $t0, -8($fp)
  sw $t1, -84($fp)
  sw $t3, -88($fp)
  sw $t4, -92($fp)
  sw $t5, -96($fp)
  sw $t6, -100($fp)
  sw $t7, -104($fp)
  j label1
label3:
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t1, -140($fp)
  move $t1, $a0
  move $sp, $fp
  move $v0, $t1
  sw $t1, -140($fp)
  jr $ra

mod_abc:
  move $fp, $sp
  addi $sp, $sp, -52
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
  move $a0, $t0
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -40($fp)
  lw $t0, -44($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -44($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  sw $t0, -48($fp)
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t0, -52($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -12($fp)
  sw $t2, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  sw $t0, -52($fp)
  jr $ra

getNumDigits_abc:
  move $fp, $sp
  addi $sp, $sp, -88
  sw $a0, -4($fp)
  li $a0, 0
  lw $t0, -8($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -12($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  li $a0, 0
  lw $t4, -20($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  sw $t0, -8($fp)
  sw $t1, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  blt $a1, $a2, label4
  j label5
label4:
  li $a0, 1
  lw $t0, -24($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -28($fp)
  move $t1, $a0
  move $sp, $fp
  move $v0, $t1
  sw $t0, -24($fp)
  sw $t1, -28($fp)
  jr $ra
label5:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -32($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -36($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -32($fp)
  sw $t2, -36($fp)
  bgt $a1, $a2, label7
  j label8
label7:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -40($fp)
  move $t1, $a0
  li $a0, 10
  lw $t2, -44($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  div $a1, $a2
  mflo $a0
  lw $t3, -48($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  lw $t4, -12($fp)
  move $a0, $t4
  lw $t5, -52($fp)
  move $t5, $a0
  li $a0, 2
  lw $t6, -56($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  add $a0, $a1, $a2
  lw $t7, -60($fp)
  move $t7, $a0
  move $a0, $t7
  move $t4, $a0
  move $a0, $t4
  sw $t0, -4($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  sw $t0, -68($fp)
  lw $t0, -64($fp)
  move $a1, $t0
  lw $t0, -68($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -72($fp)
  move $t0, $a0
  move $a0, $t0
  move $t4, $a0
  move $a0, $t4
  sw $t0, -72($fp)
  lw $t0, -76($fp)
  move $t0, $a0
  li $a0, 3
  sw $t0, -76($fp)
  lw $t0, -80($fp)
  move $t0, $a0
  sw $t0, -80($fp)
  lw $t0, -76($fp)
  move $a1, $t0
  lw $t0, -80($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -84($fp)
  move $t0, $a0
  move $a0, $t0
  move $t4, $a0
  sw $t4, -12($fp)
  sw $t1, -40($fp)
  sw $t2, -44($fp)
  sw $t3, -48($fp)
  sw $t5, -52($fp)
  sw $t6, -56($fp)
  sw $t7, -60($fp)
  sw $t0, -84($fp)
  j label5
label8:
  lw $t0, -12($fp)
  move $a0, $t0
  lw $t1, -88($fp)
  move $t1, $a0
  move $sp, $fp
  move $v0, $t1
  sw $t1, -88($fp)
  jr $ra

isNarcissistic_abc:
  move $fp, $sp
  addi $sp, $sp, -128
  sw $a0, -4($fp)
  li $a0, 1
  lw $t0, -8($fp)
  move $t0, $a0
  lw $t1, -4($fp)
  move $a0, $t1
  lw $t2, -12($fp)
  move $t2, $a0
  move $a1, $t0
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -16($fp)
  move $t3, $a0
  li $a0, 1
  lw $t4, -20($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  sub $a0, $a1, $a2
  lw $t5, -24($fp)
  move $t5, $a0
  move $a0, $t5
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
  jal getNumDigits_abc
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
  lw $t6, -28($fp)
  move $t6, $v0
  move $a0, $t6
  lw $t7, -32($fp)
  move $t7, $a0
  li $a0, 0
  sw $t0, -8($fp)
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  move $a0, $t1
  sw $t0, -40($fp)
  lw $t0, -44($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -44($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  sw $t0, -48($fp)
label9:
  lw $t0, -48($fp)
  move $a0, $t0
  lw $t1, -52($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -56($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -52($fp)
  sw $t2, -56($fp)
  bgt $a1, $a2, label10
  j label11
label10:
  lw $t0, -48($fp)
  move $a0, $t0
  lw $t1, -60($fp)
  move $t1, $a0
  li $a0, 10
  lw $t2, -64($fp)
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
  jal mod_abc
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
  lw $t3, -68($fp)
  move $t3, $v0
  move $a0, $t3
  lw $t4, -72($fp)
  move $t4, $a0
  move $a0, $t0
  lw $t5, -76($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -80($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  sub $a0, $a1, $a2
  lw $t7, -84($fp)
  move $t7, $a0
  li $a0, 10
  lw $t0, -88($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  sw $t0, -88($fp)
  lw $t0, -92($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -92($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  sw $t0, -48($fp)
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t0, -96($fp)
  move $t0, $a0
  move $a0, $t4
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  sw $t0, -100($fp)
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t0, -104($fp)
  move $t0, $a0
  move $a1, $t0
  sw $t0, -104($fp)
  lw $t0, -100($fp)
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
  jal power_abc
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
  lw $t0, -96($fp)
  move $a1, $t0
  lw $t0, -108($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -112($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -112($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  sw $t0, -40($fp)
  sw $t1, -60($fp)
  sw $t2, -64($fp)
  sw $t3, -68($fp)
  sw $t4, -72($fp)
  sw $t5, -76($fp)
  sw $t6, -80($fp)
  sw $t7, -84($fp)
  j label9
label11:
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t1, -116($fp)
  move $t1, $a0
  lw $t2, -4($fp)
  move $a0, $t2
  lw $t3, -120($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -116($fp)
  sw $t3, -120($fp)
  beq $a1, $a2, label12
  j label13
label12:
  li $a0, 1
  lw $t0, -124($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -124($fp)
  jr $ra
  j label14
label13:
  li $a0, 0
  lw $t0, -128($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -128($fp)
  jr $ra
label14:

printHexDigit_abc:
  move $fp, $sp
  addi $sp, $sp, -28
  sw $a0, -4($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 10
  lw $t2, -12($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  blt $a1, $a2, label15
  j label16
label15:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -16($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t1, -16($fp)
  j label17
label16:
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t1, -20($fp)
  move $t1, $a0
  li $a1, 0
  move $a2, $t1
  sub $a0, $a1, $a2
  lw $t2, -24($fp)
  move $t2, $a0
  move $a0, $t2
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t1, -20($fp)
  sw $t2, -24($fp)
label17:
  li $a0, 0
  lw $t0, -28($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -28($fp)
  jr $ra

printHex_abc:
  move $fp, $sp
  addi $sp, $sp, -164
  sw $a0, -4($fp)
  li $a0, 0
  lw $t0, -24($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  sw $t0, -24($fp)
  sw $t1, -28($fp)
label18:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -32($fp)
  move $t1, $a0
  li $a0, 4
  lw $t2, -36($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -32($fp)
  sw $t2, -36($fp)
  blt $a1, $a2, label19
  j label20
label19:
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t1, -40($fp)
  move $t1, $a0
  lw $t2, -28($fp)
  move $a0, $t2
  lw $t3, -44($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -48($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -52($fp)
  move $t5, $a0
  lw $t6, -4($fp)
  move $a0, $t6
  lw $t7, -56($fp)
  move $t7, $a0
  li $a0, 16
  lw $t0, -60($fp)
  move $t0, $a0
  move $a1, $t0
  move $a0, $t7
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
  jal mod_abc
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
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $v0
  move $a0, $t0
  sw $a0, 0($t5)
  move $a0, $t6
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  li $a0, 16
  sw $t0, -68($fp)
  lw $t0, -72($fp)
  move $t0, $a0
  sw $t0, -72($fp)
  lw $t0, -68($fp)
  move $a1, $t0
  lw $t0, -72($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -76($fp)
  move $t0, $a0
  move $a0, $t0
  move $t6, $a0
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
  move $a0, $t0
  move $t2, $a0
  sw $t6, -4($fp)
  sw $t2, -28($fp)
  sw $t1, -40($fp)
  sw $t3, -44($fp)
  sw $t4, -48($fp)
  sw $t5, -52($fp)
  sw $t7, -56($fp)
  sw $t0, -88($fp)
  j label18
label20:
  li $a0, 3
  lw $t0, -92($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  sw $t1, -28($fp)
  sw $t0, -92($fp)
label21:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -96($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -100($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -96($fp)
  sw $t2, -100($fp)
  bge $a1, $a2, label22
  j label23
label22:
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t1, -104($fp)
  move $t1, $a0
  lw $t2, -28($fp)
  move $a0, $t2
  lw $t3, -108($fp)
  move $t3, $a0
  li $a0, 18
  lw $t4, -112($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -116($fp)
  move $t5, $a0
  li $a0, 9
  lw $t6, -120($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  sub $a0, $a1, $a2
  lw $t7, -124($fp)
  move $t7, $a0
  li $a0, 9
  lw $t0, -128($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -128($fp)
  lw $t0, -132($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  mul $a0, $a1, $a2
  sw $t0, -132($fp)
  lw $t0, -136($fp)
  move $t0, $a0
  move $a1, $t1
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -136($fp)
  lw $t0, -140($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -140($fp)
  lw $t0, -144($fp)
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
  jal printHexDigit_abc
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
  sw $t0, -144($fp)
  lw $t0, -148($fp)
  move $t0, $v0
  move $a0, $t2
  sw $t0, -148($fp)
  lw $t0, -152($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -152($fp)
  lw $t0, -156($fp)
  move $t0, $a0
  sw $t0, -156($fp)
  lw $t0, -152($fp)
  move $a1, $t0
  lw $t0, -156($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -160($fp)
  move $t0, $a0
  move $a0, $t0
  move $t2, $a0
  sw $t2, -28($fp)
  sw $t1, -104($fp)
  sw $t3, -108($fp)
  sw $t4, -112($fp)
  sw $t5, -116($fp)
  sw $t6, -120($fp)
  sw $t7, -124($fp)
  sw $t0, -160($fp)
  j label21
label23:
  li $a0, 0
  lw $t0, -164($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -164($fp)
  jr $ra

main:
  move $fp, $sp
  addi $sp, $sp, -128
  li $a0, 0
  lw $t0, -4($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -8($fp)
  move $t1, $a0
  li $a0, 2900
  lw $t2, -12($fp)
  move $t2, $a0
  li $a0, 7100
  lw $t3, -16($fp)
  move $t3, $a0
  move $a1, $t2
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -20($fp)
  move $t4, $a0
  li $a0, 1000
  lw $t5, -24($fp)
  move $t5, $a0
  move $a1, $t4
  move $a2, $t5
  sub $a0, $a1, $a2
  lw $t6, -28($fp)
  move $t6, $a0
  li $a0, 440
  lw $t7, -32($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  add $a0, $a1, $a2
  sw $t0, -4($fp)
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  sw $t0, -40($fp)
label24:
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t1, -44($fp)
  move $t1, $a0
  li $a0, 9501
  lw $t2, -48($fp)
  move $t2, $a0
  li $a0, 9123
  lw $t3, -52($fp)
  move $t3, $a0
  move $a1, $t2
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -56($fp)
  move $t4, $a0
  li $a0, 9123
  lw $t5, -60($fp)
  move $t5, $a0
  move $a1, $t4
  move $a2, $t5
  sub $a0, $a1, $a2
  lw $t6, -64($fp)
  move $t6, $a0
  li $a0, 9
  lw $t7, -68($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -72($fp)
  move $t0, $a0
  li $a0, 10
  sw $t0, -72($fp)
  lw $t0, -76($fp)
  move $t0, $a0
  sw $t0, -76($fp)
  lw $t0, -72($fp)
  move $a1, $t0
  lw $t0, -76($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -80($fp)
  move $t0, $a0
  move $a1, $t1
  move $a2, $t0
  sw $t1, -44($fp)
  sw $t2, -48($fp)
  sw $t3, -52($fp)
  sw $t4, -56($fp)
  sw $t5, -60($fp)
  sw $t6, -64($fp)
  sw $t7, -68($fp)
  sw $t0, -80($fp)
  blt $a1, $a2, label25
  j label26
label25:
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t1, -84($fp)
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
  jal isNarcissistic_abc
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
  lw $t2, -88($fp)
  move $t2, $v0
  li $a0, 1
  lw $t3, -92($fp)
  move $t3, $a0
  move $a1, $t2
  move $a2, $t3
  sw $t1, -84($fp)
  sw $t2, -88($fp)
  sw $t3, -92($fp)
  beq $a1, $a2, label27
  j label28
label27:
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t1, -96($fp)
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
  jal printHex_abc
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
  lw $t2, -100($fp)
  move $t2, $v0
  lw $t3, -8($fp)
  move $a0, $t3
  lw $t4, -104($fp)
  move $t4, $a0
  li $a0, 1
  lw $t5, -108($fp)
  move $t5, $a0
  move $a1, $t4
  move $a2, $t5
  add $a0, $a1, $a2
  lw $t6, -112($fp)
  move $t6, $a0
  move $a0, $t6
  move $t3, $a0
  sw $t3, -8($fp)
  sw $t1, -96($fp)
  sw $t2, -100($fp)
  sw $t4, -104($fp)
  sw $t5, -108($fp)
  sw $t6, -112($fp)
label28:
  lw $t0, -40($fp)
  move $a0, $t0
  lw $t1, -116($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -120($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -124($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  sw $t0, -40($fp)
  sw $t1, -116($fp)
  sw $t2, -120($fp)
  sw $t3, -124($fp)
  j label24
label26:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -128($fp)
  move $t1, $a0
  move $sp, $fp
  move $v0, $t1
  sw $t1, -128($fp)
  jr $ra
