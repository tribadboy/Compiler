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
  addi $sp, $sp, -124
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
  li $a0, 2
  lw $t2, -12($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  li $a0, 1
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
label1:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  lw $t2, -8($fp)
  move $a0, $t2
  lw $t3, -32($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -28($fp)
  sw $t3, -32($fp)
  ble $a1, $a2, label2
  j label3
label2:
  li $a0, 1
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -24($fp)
  move $t1, $a0
  sw $t1, -24($fp)
  sw $t0, -36($fp)
label4:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -40($fp)
  move $t1, $a0
  lw $t2, -16($fp)
  move $a0, $t2
  lw $t3, -44($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -40($fp)
  sw $t3, -44($fp)
  bne $a1, $a2, label7
  j label6
label7:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -48($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -52($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -48($fp)
  sw $t2, -52($fp)
  beq $a1, $a2, label5
  j label6
label5:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -56($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -60($fp)
  move $t2, $a0
  lw $t3, -16($fp)
  move $a0, $t3
  lw $t4, -64($fp)
  move $t4, $a0
  move $a1, $t2
  move $a2, $t4
  div $a1, $a2
  mflo $a0
  lw $t5, -68($fp)
  move $t5, $a0
  move $a0, $t3
  lw $t6, -72($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -76($fp)
  move $t7, $a0
  move $a1, $t1
  move $a2, $t7
  sub $a0, $a1, $a2
  lw $t0, -80($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -80($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  sw $t0, -84($fp)
  lw $t0, -80($fp)
  move $a1, $t0
  lw $t0, -84($fp)
  move $a2, $t0
  sw $t1, -56($fp)
  sw $t2, -60($fp)
  sw $t4, -64($fp)
  sw $t5, -68($fp)
  sw $t6, -72($fp)
  sw $t7, -76($fp)
  beq $a1, $a2, label8
  j label9
label8:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -88($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t2, -8($fp)
  move $a0, $t2
  lw $t3, -92($fp)
  move $t3, $a0
  move $a0, $t0
  lw $t4, -96($fp)
  move $t4, $a0
  move $a1, $t3
  move $a2, $t4
  div $a1, $a2
  mflo $a0
  lw $t5, -100($fp)
  move $t5, $a0
  move $a0, $t5
  move $t2, $a0
  sw $t2, -8($fp)
  sw $t1, -88($fp)
  sw $t3, -92($fp)
  sw $t4, -96($fp)
  sw $t5, -100($fp)
  j label10
label9:
  li $a0, 0
  lw $t0, -104($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -24($fp)
  move $t1, $a0
  sw $t1, -24($fp)
  sw $t0, -104($fp)
label10:
  j label4
label6:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -108($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -112($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -116($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  sw $t0, -16($fp)
  sw $t1, -108($fp)
  sw $t2, -112($fp)
  sw $t3, -116($fp)
  j label1
label3:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -120($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  lw $t2, -124($fp)
  move $t2, $a0
  move $sp, $fp
  move $v0, $t2
  sw $t1, -120($fp)
  sw $t2, -124($fp)
  jr $ra
