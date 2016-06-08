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
  addi $sp, $sp, -252
  li $a0, 0
  lw $t0, -24($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -32($fp)
  move $t2, $a0
  move $a0, $t2
  lw $t3, -36($fp)
  move $t3, $a0
  sw $t0, -24($fp)
  sw $t1, -28($fp)
  sw $t2, -32($fp)
  sw $t3, -36($fp)
label1:
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
  blt $a1, $a2, label2
  j label3
label2:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -48($fp)
  move $t1, $a0
  li $a0, 0
  lw $t2, -52($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -48($fp)
  sw $t2, -52($fp)
  beq $a1, $a2, label4
  j label5
label4:
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t1, -56($fp)
  move $t1, $a0
  lw $t2, -28($fp)
  move $a0, $t2
  lw $t3, -60($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -64($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -68($fp)
  move $t5, $a0
  li $a0, 9
  lw $t6, -72($fp)
  move $t6, $a0
  move $a0, $t6
  sw $a0, 0($t5)
  sw $t1, -56($fp)
  sw $t3, -60($fp)
  sw $t4, -64($fp)
  sw $t5, -68($fp)
  sw $t6, -72($fp)
  j label6
label5:
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t1, -76($fp)
  move $t1, $a0
  lw $t2, -28($fp)
  move $a0, $t2
  lw $t3, -80($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -84($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -88($fp)
  move $t5, $a0
  move $a0, $t2
  lw $t6, -92($fp)
  move $t6, $a0
  move $a0, $t2
  lw $t7, -96($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  mul $a0, $a1, $a2
  lw $t0, -100($fp)
  move $t0, $a0
  li $a0, 3
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -104($fp)
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
  sw $t0, -112($fp)
  lw $t0, -100($fp)
  move $a1, $t0
  lw $t0, -112($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -116($fp)
  move $t0, $a0
  sw $t0, -116($fp)
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t0, -120($fp)
  move $t0, $a0
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
  sub $a0, $a1, $a2
  lw $t0, -132($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  mul $a0, $a1, $a2
  sw $t0, -132($fp)
  lw $t0, -136($fp)
  move $t0, $a0
  sw $t0, -136($fp)
  lw $t0, -120($fp)
  move $a1, $t0
  lw $t0, -136($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -140($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -140($fp)
  lw $t0, -144($fp)
  move $t0, $a0
  sw $t0, -144($fp)
  lw $t0, -116($fp)
  move $a1, $t0
  lw $t0, -144($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -148($fp)
  move $t0, $a0
  li $a0, 5
  sw $t0, -148($fp)
  lw $t0, -152($fp)
  move $t0, $a0
  sw $t0, -152($fp)
  lw $t0, -148($fp)
  move $a1, $t0
  lw $t0, -152($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -156($fp)
  move $t0, $a0
  move $a0, $t0
  sw $a0, 0($t5)
  sw $t1, -76($fp)
  sw $t3, -80($fp)
  sw $t4, -84($fp)
  sw $t5, -88($fp)
  sw $t6, -92($fp)
  sw $t7, -96($fp)
  sw $t0, -156($fp)
label6:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -160($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -164($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -168($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  sw $t0, -28($fp)
  sw $t1, -160($fp)
  sw $t2, -164($fp)
  sw $t3, -168($fp)
  j label1
label3:
  li $a0, 0
  lw $t0, -172($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -28($fp)
  move $t1, $a0
  sw $t1, -28($fp)
  sw $t0, -172($fp)
label7:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -176($fp)
  move $t1, $a0
  li $a0, 5
  lw $t2, -180($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -176($fp)
  sw $t2, -180($fp)
  blt $a1, $a2, label8
  j label9
label8:
  addi $t0, $fp, -20
  move $a0, $t0
  lw $t1, -184($fp)
  move $t1, $a0
  lw $t2, -28($fp)
  move $a0, $t2
  lw $t3, -188($fp)
  move $t3, $a0
  move $a1, $t3
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t4, -192($fp)
  move $t4, $a0
  move $a1, $t1
  move $a2, $t4
  add $a0, $a1, $a2
  lw $t5, -196($fp)
  move $t5, $a0
  lw $a0, 0($t5)
  lw $t6, -200($fp)
  move $t6, $a0
  li $a0, 10
  lw $t7, -204($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  sw $t1, -184($fp)
  sw $t3, -188($fp)
  sw $t4, -192($fp)
  sw $t5, -196($fp)
  sw $t6, -200($fp)
  sw $t7, -204($fp)
  bgt $a1, $a2, label10
  j label11
label10:
  lw $t0, -36($fp)
  move $a0, $t0
  lw $t1, -208($fp)
  move $t1, $a0
  addi $t2, $fp, -20
  move $a0, $t2
  lw $t3, -212($fp)
  move $t3, $a0
  lw $t4, -28($fp)
  move $a0, $t4
  lw $t5, -216($fp)
  move $t5, $a0
  move $a1, $t5
  li $a2, 4
  mul $a0, $a1, $a2
  lw $t6, -220($fp)
  move $t6, $a0
  move $a1, $t3
  move $a2, $t6
  add $a0, $a1, $a2
  lw $t7, -224($fp)
  move $t7, $a0
  lw $a0, 0($t7)
  lw $t0, -228($fp)
  move $t0, $a0
  move $a1, $t1
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -228($fp)
  lw $t0, -232($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -232($fp)
  lw $t0, -36($fp)
  move $t0, $a0
  sw $t0, -36($fp)
  sw $t1, -208($fp)
  sw $t3, -212($fp)
  sw $t5, -216($fp)
  sw $t6, -220($fp)
  sw $t7, -224($fp)
label11:
  lw $t0, -28($fp)
  move $a0, $t0
  lw $t1, -236($fp)
  move $t1, $a0
  li $a0, 1
  lw $t2, -240($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  add $a0, $a1, $a2
  lw $t3, -244($fp)
  move $t3, $a0
  move $a0, $t3
  move $t0, $a0
  sw $t0, -28($fp)
  sw $t1, -236($fp)
  sw $t2, -240($fp)
  sw $t3, -244($fp)
  j label7
label9:
  lw $t0, -36($fp)
  move $a0, $t0
  lw $t1, -248($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  lw $t2, -252($fp)
  move $t2, $a0
  move $sp, $fp
  move $v0, $t2
  sw $t1, -248($fp)
  sw $t2, -252($fp)
  jr $ra
