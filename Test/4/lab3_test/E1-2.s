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

sum_Score_abc:
  move $fp, $sp
  addi $sp, $sp, -68
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
  move $a0, $t0
  lw $t7, -32($fp)
  move $t7, $a0
  move $a1, $t7
  li $a2, 8
  add $a0, $a1, $a2
  lw $t0, -36($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  move $a1, $t6
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -40($fp)
  lw $t0, -44($fp)
  move $t0, $a0
  sw $t0, -44($fp)
  lw $t0, -4($fp)
  move $a0, $t0
  lw $t0, -48($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 12
  add $a0, $a1, $a2
  sw $t0, -48($fp)
  lw $t0, -52($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -52($fp)
  lw $t0, -56($fp)
  move $t0, $a0
  sw $t0, -56($fp)
  lw $t0, -44($fp)
  move $a1, $t0
  lw $t0, -56($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -60($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -60($fp)
  lw $t0, -64($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -64($fp)
  lw $t0, -68($fp)
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
  sw $t0, -68($fp)
  jr $ra

ave_Score_abc:
  move $fp, $sp
  addi $sp, $sp, -52
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
  move $a0, $t0
  lw $t7, -32($fp)
  move $t7, $a0
  move $a1, $t7
  li $a2, 8
  add $a0, $a1, $a2
  lw $t0, -36($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  move $a1, $t6
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -40($fp)
  lw $t0, -44($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -44($fp)
  lw $t0, -48($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -48($fp)
  lw $t0, -52($fp)
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
  sw $t0, -52($fp)
  jr $ra

compare_abc:
  move $fp, $sp
  addi $sp, $sp, -60
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
  jal ave_Score_abc
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
  move $a0, $t2
  lw $t3, -20($fp)
  move $t3, $a0
  lw $t4, -8($fp)
  move $a0, $t4
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
  jal ave_Score_abc
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
  move $a0, $t3
  lw $t0, -36($fp)
  move $t0, $a0
  move $a0, $t7
  sw $t0, -36($fp)
  lw $t0, -40($fp)
  move $t0, $a0
  sw $t0, -40($fp)
  lw $t0, -36($fp)
  move $a1, $t0
  lw $t0, -40($fp)
  move $a2, $t0
  sw $t1, -12($fp)
  sw $t2, -16($fp)
  sw $t3, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  blt $a1, $a2, label1
  j label2
label1:
  li $a0, 1
  lw $t0, -44($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -44($fp)
  jr $ra
  j label6
label2:
  lw $t0, -20($fp)
  move $a0, $t0
  lw $t1, -48($fp)
  move $t1, $a0
  lw $t2, -32($fp)
  move $a0, $t2
  lw $t3, -52($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -48($fp)
  sw $t3, -52($fp)
  beq $a1, $a2, label4
  j label5
label4:
  li $a0, 2
  lw $t0, -56($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -56($fp)
  jr $ra
  j label6
label5:
  li $a0, 3
  lw $t0, -60($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -60($fp)
  jr $ra
label6:

main:
  move $fp, $sp
  addi $sp, $sp, -352
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t1, -36($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -40($fp)
  move $t2, $a0
  move $a1, $t2
  li $a2, 16
  mul $a0, $a1, $a2
  lw $t3, -44($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -48($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -52($fp)
  move $t5, $a0
  move $a0, $t5
  lw $t6, -56($fp)
  move $t6, $a0
  li $a0, 98
  lw $t7, -60($fp)
  move $t7, $a0
  move $a0, $t7
  sw $a0, 0($t6)
  move $a0, $t0
  lw $t0, -64($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -68($fp)
  lw $t0, -72($fp)
  move $t0, $a0
  sw $t0, -72($fp)
  lw $t0, -64($fp)
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
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -80($fp)
  lw $t0, -84($fp)
  move $t0, $a0
  li $a0, 92
  sw $t0, -84($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -88($fp)
  lw $t0, -84($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -92($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -92($fp)
  lw $t0, -96($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  sw $t0, -100($fp)
  lw $t0, -92($fp)
  move $a1, $t0
  lw $t0, -100($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -104($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -104($fp)
  lw $t0, -108($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  add $a0, $a1, $a2
  sw $t0, -108($fp)
  lw $t0, -112($fp)
  move $t0, $a0
  li $a0, 89
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -116($fp)
  lw $t0, -112($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -120($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -120($fp)
  lw $t0, -124($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -124($fp)
  lw $t0, -128($fp)
  move $t0, $a0
  sw $t0, -128($fp)
  lw $t0, -120($fp)
  move $a1, $t0
  lw $t0, -128($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -132($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -132($fp)
  lw $t0, -136($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 12
  add $a0, $a1, $a2
  sw $t0, -136($fp)
  lw $t0, -140($fp)
  move $t0, $a0
  li $a0, 55
  sw $t0, -140($fp)
  lw $t0, -144($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -144($fp)
  lw $t0, -140($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -148($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -148($fp)
  lw $t0, -152($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -152($fp)
  lw $t0, -156($fp)
  move $t0, $a0
  sw $t0, -156($fp)
  lw $t0, -148($fp)
  move $a1, $t0
  lw $t0, -156($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -160($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -160($fp)
  lw $t0, -164($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -164($fp)
  lw $t0, -168($fp)
  move $t0, $a0
  li $a0, 97
  sw $t0, -168($fp)
  lw $t0, -172($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -172($fp)
  lw $t0, -168($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -176($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -176($fp)
  lw $t0, -180($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -180($fp)
  lw $t0, -184($fp)
  move $t0, $a0
  sw $t0, -184($fp)
  lw $t0, -176($fp)
  move $a1, $t0
  lw $t0, -184($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -188($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -188($fp)
  lw $t0, -192($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -192($fp)
  lw $t0, -196($fp)
  move $t0, $a0
  li $a0, 99
  sw $t0, -196($fp)
  lw $t0, -200($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -200($fp)
  lw $t0, -196($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -204($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -204($fp)
  lw $t0, -208($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -208($fp)
  lw $t0, -212($fp)
  move $t0, $a0
  sw $t0, -212($fp)
  lw $t0, -204($fp)
  move $a1, $t0
  lw $t0, -212($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -216($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -216($fp)
  lw $t0, -220($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  add $a0, $a1, $a2
  sw $t0, -220($fp)
  lw $t0, -224($fp)
  move $t0, $a0
  li $a0, 80
  sw $t0, -224($fp)
  lw $t0, -228($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -228($fp)
  lw $t0, -224($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -232($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -232($fp)
  lw $t0, -236($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -236($fp)
  lw $t0, -240($fp)
  move $t0, $a0
  sw $t0, -240($fp)
  lw $t0, -232($fp)
  move $a1, $t0
  lw $t0, -240($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -244($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -244($fp)
  lw $t0, -248($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 12
  add $a0, $a1, $a2
  sw $t0, -248($fp)
  lw $t0, -252($fp)
  move $t0, $a0
  li $a0, 58
  sw $t0, -252($fp)
  lw $t0, -256($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -256($fp)
  lw $t0, -252($fp)
  sw $a0, 0($t0)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -260($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -260($fp)
  lw $t0, -264($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -264($fp)
  lw $t0, -268($fp)
  move $t0, $a0
  sw $t0, -268($fp)
  lw $t0, -260($fp)
  move $a1, $t0
  lw $t0, -268($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -272($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -272($fp)
  lw $t0, -276($fp)
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
  jal sum_Score_abc
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
  sw $t0, -276($fp)
  lw $t0, -280($fp)
  move $t0, $v0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -280($fp)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -284($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -284($fp)
  lw $t0, -288($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -288($fp)
  lw $t0, -292($fp)
  move $t0, $a0
  sw $t0, -292($fp)
  lw $t0, -284($fp)
  move $a1, $t0
  lw $t0, -292($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -296($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -296($fp)
  lw $t0, -300($fp)
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
  jal sum_Score_abc
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
  sw $t0, -300($fp)
  lw $t0, -304($fp)
  move $t0, $v0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -304($fp)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -308($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -308($fp)
  lw $t0, -312($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -312($fp)
  lw $t0, -316($fp)
  move $t0, $a0
  sw $t0, -316($fp)
  lw $t0, -308($fp)
  move $a1, $t0
  lw $t0, -316($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -320($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -320($fp)
  lw $t0, -324($fp)
  move $t0, $a0
  sw $t0, -324($fp)
  addi $t0, $fp, -32
  move $a0, $t0
  lw $t0, -328($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -328($fp)
  lw $t0, -332($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 16
  mul $a0, $a1, $a2
  sw $t0, -332($fp)
  lw $t0, -336($fp)
  move $t0, $a0
  sw $t0, -336($fp)
  lw $t0, -328($fp)
  move $a1, $t0
  lw $t0, -336($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -340($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -340($fp)
  lw $t0, -344($fp)
  move $t0, $a0
  move $a1, $t0
  sw $t0, -344($fp)
  lw $t0, -324($fp)
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
  jal compare_abc
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
  lw $t0, -348($fp)
  move $t0, $v0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  sw $t0, -348($fp)
  lw $t0, -352($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -36($fp)
  sw $t2, -40($fp)
  sw $t3, -44($fp)
  sw $t4, -48($fp)
  sw $t5, -52($fp)
  sw $t6, -56($fp)
  sw $t7, -60($fp)
  sw $t0, -352($fp)
  jr $ra
