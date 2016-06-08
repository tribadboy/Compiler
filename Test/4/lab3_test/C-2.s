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
  addi $sp, $sp, -192
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
  li $a0, 0
  lw $t3, -16($fp)
  move $t3, $a0
  move $a1, $t2
  move $a2, $t3
  sw $t0, -4($fp)
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  blt $a1, $a2, label1
  j label2
label1:
  li $a0, 1
  lw $t0, -20($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -24($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -20($fp)
  sw $t1, -24($fp)
  j label18
label2:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  li $a0, 10
  lw $t2, -32($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -28($fp)
  sw $t2, -32($fp)
  blt $a1, $a2, label4
  j label5
label4:
  li $a0, 1
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -36($fp)
  j label18
label5:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -40($fp)
  move $t1, $a0
  li $a0, 10
  lw $t2, -44($fp)
  move $t2, $a0
  move $a0, $t0
  lw $t3, -48($fp)
  move $t3, $a0
  li $a0, 10
  lw $t4, -52($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  div $a1, $a2
  mflo $a0
  lw $t5, -56($fp)
  move $t5, $a0
  move $a1, $t2
  move $a2, $t5
  mul $a0, $a1, $a2
  lw $t6, -60($fp)
  move $t6, $a0
  move $a1, $t1
  move $a2, $t6
  sub $a0, $a1, $a2
  lw $t7, -64($fp)
  move $t7, $a0
  li $a0, 0
  lw $t0, -68($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  sw $t1, -40($fp)
  sw $t2, -44($fp)
  sw $t3, -48($fp)
  sw $t4, -52($fp)
  sw $t5, -56($fp)
  sw $t6, -60($fp)
  sw $t7, -64($fp)
  sw $t0, -68($fp)
  beq $a1, $a2, label7
  j label8
label7:
  li $a0, 1
  lw $t0, -72($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -76($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -72($fp)
  sw $t1, -76($fp)
  j label18
label8:
  li $a0, 0
  lw $t0, -80($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -84($fp)
  move $t1, $a0
  sw $t0, -80($fp)
  sw $t1, -84($fp)
label10:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -88($fp)
  move $t1, $a0
  lw $t2, -84($fp)
  move $a0, $t2
  lw $t3, -92($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -88($fp)
  sw $t3, -92($fp)
  bgt $a1, $a2, label11
  j label12
label11:
  lw $t0, -84($fp)
  move $a0, $t0
  lw $t1, -96($fp)
  move $t1, $a0
  li $a0, 10
  lw $t2, -100($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -104($fp)
  move $t3, $a0
  lw $t4, -8($fp)
  move $a0, $t4
  lw $t5, -108($fp)
  move $t5, $a0
  move $a1, $t3
  move $a2, $t5
  add $a0, $a1, $a2
  lw $t6, -112($fp)
  move $t6, $a0
  li $a0, 10
  lw $t7, -116($fp)
  move $t7, $a0
  move $a0, $t4
  lw $t0, -120($fp)
  move $t0, $a0
  li $a0, 10
  sw $t0, -120($fp)
  lw $t0, -124($fp)
  move $t0, $a0
  sw $t0, -124($fp)
  lw $t0, -120($fp)
  move $a1, $t0
  lw $t0, -124($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -128($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  mul $a0, $a1, $a2
  sw $t0, -128($fp)
  lw $t0, -132($fp)
  move $t0, $a0
  move $a1, $t6
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -132($fp)
  lw $t0, -136($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -136($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  move $a0, $t4
  sw $t0, -84($fp)
  lw $t0, -140($fp)
  move $t0, $a0
  li $a0, 10
  sw $t0, -140($fp)
  lw $t0, -144($fp)
  move $t0, $a0
  sw $t0, -144($fp)
  lw $t0, -140($fp)
  move $a1, $t0
  lw $t0, -144($fp)
  move $a2, $t0
  div $a1, $a2
  mflo $a0
  lw $t0, -148($fp)
  move $t0, $a0
  move $a0, $t0
  move $t4, $a0
  sw $t4, -8($fp)
  sw $t1, -96($fp)
  sw $t2, -100($fp)
  sw $t3, -104($fp)
  sw $t5, -108($fp)
  sw $t6, -112($fp)
  sw $t7, -116($fp)
  sw $t0, -148($fp)
  j label10
label12:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -152($fp)
  move $t1, $a0
  lw $t2, -84($fp)
  move $a0, $t2
  lw $t3, -156($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -152($fp)
  sw $t3, -156($fp)
  beq $a1, $a2, label13
  j label14
label13:
  li $a0, 1
  lw $t0, -160($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -160($fp)
  j label18
label14:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -164($fp)
  move $t1, $a0
  lw $t2, -84($fp)
  move $a0, $t2
  lw $t3, -168($fp)
  move $t3, $a0
  li $a0, 10
  lw $t4, -172($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  div $a1, $a2
  mflo $a0
  lw $t5, -176($fp)
  move $t5, $a0
  move $a1, $t1
  move $a2, $t5
  sw $t1, -164($fp)
  sw $t3, -168($fp)
  sw $t4, -172($fp)
  sw $t5, -176($fp)
  beq $a1, $a2, label16
  j label17
label16:
  li $a0, 1
  lw $t0, -180($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -180($fp)
  j label18
label17:
  li $a0, 1
  lw $t0, -184($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -188($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -184($fp)
  sw $t1, -188($fp)
label18:
  li $a0, 0
  lw $t0, -192($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -192($fp)
  jr $ra
