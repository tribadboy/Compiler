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
  addi $sp, $sp, -544
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
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t2, -12($fp)
  move $t2, $v0
  move $a0, $t2
  lw $t3, -16($fp)
  move $t3, $a0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t4, -20($fp)
  move $t4, $v0
  move $a0, $t4
  lw $t5, -24($fp)
  move $t5, $a0
  move $a0, $t1
  lw $t6, -28($fp)
  move $t6, $a0
  move $a0, $t5
  lw $t7, -32($fp)
  move $t7, $a0
  move $a1, $t6
  move $a2, $t7
  sw $t0, -4($fp)
  sw $t1, -8($fp)
  sw $t2, -12($fp)
  sw $t3, -16($fp)
  sw $t4, -20($fp)
  sw $t5, -24($fp)
  sw $t6, -28($fp)
  sw $t7, -32($fp)
  ble $a1, $a2, label3
  j label14
label3:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -36($fp)
  move $t1, $a0
  lw $t2, -24($fp)
  move $a0, $t2
  lw $t3, -40($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -36($fp)
  sw $t3, -40($fp)
  ble $a1, $a2, label1
  j label14
label1:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -44($fp)
  move $t1, $a0
  lw $t2, -16($fp)
  move $a0, $t2
  lw $t3, -48($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -52($fp)
  move $t4, $a0
  lw $t5, -24($fp)
  move $a0, $t5
  lw $t6, -56($fp)
  move $t6, $a0
  move $a1, $t4
  move $a2, $t6
  sw $t1, -44($fp)
  sw $t3, -48($fp)
  sw $t4, -52($fp)
  sw $t6, -56($fp)
  ble $a1, $a2, label4
  j label5
label4:
  li $a0, 1
  lw $t0, -60($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -64($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -60($fp)
  sw $t1, -64($fp)
  j label14
label5:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -68($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -72($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -76($fp)
  move $t3, $a0
  lw $t4, -16($fp)
  move $a0, $t4
  lw $t5, -80($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -84($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -88($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -92($fp)
  move $t0, $a0
  sw $t0, -92($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -96($fp)
  move $t0, $a0
  sw $t0, -96($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -100($fp)
  move $t0, $a0
  sw $t0, -100($fp)
  lw $t0, -96($fp)
  move $a1, $t0
  lw $t0, -100($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -104($fp)
  move $t0, $a0
  sw $t0, -104($fp)
  lw $t0, -92($fp)
  move $a1, $t0
  lw $t0, -104($fp)
  move $a2, $t0
  sw $t1, -68($fp)
  sw $t2, -72($fp)
  sw $t3, -76($fp)
  sw $t5, -80($fp)
  sw $t6, -84($fp)
  sw $t7, -88($fp)
  beq $a1, $a2, label7
  j label8
label7:
  li $a0, 1
  lw $t0, -108($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -108($fp)
  j label14
label8:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -112($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -116($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -120($fp)
  move $t3, $a0
  lw $t4, -16($fp)
  move $a0, $t4
  lw $t5, -124($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -128($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -132($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -136($fp)
  move $t0, $a0
  sw $t0, -136($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -140($fp)
  move $t0, $a0
  sw $t0, -140($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -144($fp)
  move $t0, $a0
  sw $t0, -144($fp)
  lw $t0, -140($fp)
  move $a1, $t0
  lw $t0, -144($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -148($fp)
  move $t0, $a0
  sw $t0, -148($fp)
  lw $t0, -136($fp)
  move $a1, $t0
  lw $t0, -148($fp)
  move $a2, $t0
  sw $t1, -112($fp)
  sw $t2, -116($fp)
  sw $t3, -120($fp)
  sw $t5, -124($fp)
  sw $t6, -128($fp)
  sw $t7, -132($fp)
  bgt $a1, $a2, label10
  j label11
label10:
  li $a0, 2
  lw $t0, -152($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -152($fp)
  j label14
label11:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -156($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -160($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -164($fp)
  move $t3, $a0
  lw $t4, -16($fp)
  move $a0, $t4
  lw $t5, -168($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -172($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -176($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -180($fp)
  move $t0, $a0
  sw $t0, -180($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -184($fp)
  move $t0, $a0
  sw $t0, -184($fp)
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t0, -188($fp)
  move $t0, $a0
  sw $t0, -188($fp)
  lw $t0, -184($fp)
  move $a1, $t0
  lw $t0, -188($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -192($fp)
  move $t0, $a0
  sw $t0, -192($fp)
  lw $t0, -180($fp)
  move $a1, $t0
  lw $t0, -192($fp)
  move $a2, $t0
  sw $t1, -156($fp)
  sw $t2, -160($fp)
  sw $t3, -164($fp)
  sw $t5, -168($fp)
  sw $t6, -172($fp)
  sw $t7, -176($fp)
  blt $a1, $a2, label13
  j label14
label13:
  li $a0, 3
  lw $t0, -196($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -196($fp)
label14:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -200($fp)
  move $t1, $a0
  lw $t2, -16($fp)
  move $a0, $t2
  lw $t3, -204($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -200($fp)
  sw $t3, -204($fp)
  ble $a1, $a2, label17
  j label28
label17:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -208($fp)
  move $t1, $a0
  lw $t2, -16($fp)
  move $a0, $t2
  lw $t3, -212($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -208($fp)
  sw $t3, -212($fp)
  ble $a1, $a2, label15
  j label28
label15:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -216($fp)
  move $t1, $a0
  lw $t2, -24($fp)
  move $a0, $t2
  lw $t3, -220($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -224($fp)
  move $t4, $a0
  lw $t5, -16($fp)
  move $a0, $t5
  lw $t6, -228($fp)
  move $t6, $a0
  move $a1, $t4
  move $a2, $t6
  sw $t1, -216($fp)
  sw $t3, -220($fp)
  sw $t4, -224($fp)
  sw $t6, -228($fp)
  ble $a1, $a2, label18
  j label19
label18:
  li $a0, 1
  lw $t0, -232($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -236($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -232($fp)
  sw $t1, -236($fp)
  j label28
label19:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -240($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -244($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -248($fp)
  move $t3, $a0
  lw $t4, -24($fp)
  move $a0, $t4
  lw $t5, -252($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -256($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -260($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -264($fp)
  move $t0, $a0
  sw $t0, -264($fp)
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t0, -268($fp)
  move $t0, $a0
  sw $t0, -268($fp)
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t0, -272($fp)
  move $t0, $a0
  sw $t0, -272($fp)
  lw $t0, -268($fp)
  move $a1, $t0
  lw $t0, -272($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -276($fp)
  move $t0, $a0
  sw $t0, -276($fp)
  lw $t0, -264($fp)
  move $a1, $t0
  lw $t0, -276($fp)
  move $a2, $t0
  sw $t1, -240($fp)
  sw $t2, -244($fp)
  sw $t3, -248($fp)
  sw $t5, -252($fp)
  sw $t6, -256($fp)
  sw $t7, -260($fp)
  beq $a1, $a2, label21
  j label22
label21:
  li $a0, 1
  lw $t0, -280($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -280($fp)
  j label28
label22:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -284($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -288($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -292($fp)
  move $t3, $a0
  lw $t4, -24($fp)
  move $a0, $t4
  lw $t5, -296($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -300($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -304($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -308($fp)
  move $t0, $a0
  sw $t0, -308($fp)
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t0, -312($fp)
  move $t0, $a0
  sw $t0, -312($fp)
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t0, -316($fp)
  move $t0, $a0
  sw $t0, -316($fp)
  lw $t0, -312($fp)
  move $a1, $t0
  lw $t0, -316($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -320($fp)
  move $t0, $a0
  sw $t0, -320($fp)
  lw $t0, -308($fp)
  move $a1, $t0
  lw $t0, -320($fp)
  move $a2, $t0
  sw $t1, -284($fp)
  sw $t2, -288($fp)
  sw $t3, -292($fp)
  sw $t5, -296($fp)
  sw $t6, -300($fp)
  sw $t7, -304($fp)
  bgt $a1, $a2, label24
  j label25
label24:
  li $a0, 2
  lw $t0, -324($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -324($fp)
  j label28
label25:
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t1, -328($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -332($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -336($fp)
  move $t3, $a0
  lw $t4, -24($fp)
  move $a0, $t4
  lw $t5, -340($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -344($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -348($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -352($fp)
  move $t0, $a0
  sw $t0, -352($fp)
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t0, -356($fp)
  move $t0, $a0
  sw $t0, -356($fp)
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t0, -360($fp)
  move $t0, $a0
  sw $t0, -360($fp)
  lw $t0, -356($fp)
  move $a1, $t0
  lw $t0, -360($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -364($fp)
  move $t0, $a0
  sw $t0, -364($fp)
  lw $t0, -352($fp)
  move $a1, $t0
  lw $t0, -364($fp)
  move $a2, $t0
  sw $t1, -328($fp)
  sw $t2, -332($fp)
  sw $t3, -336($fp)
  sw $t5, -340($fp)
  sw $t6, -344($fp)
  sw $t7, -348($fp)
  blt $a1, $a2, label27
  j label28
label27:
  li $a0, 3
  lw $t0, -368($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -368($fp)
label28:
  lw $t0, -16($fp)
  move $a0, $t0
  lw $t1, -372($fp)
  move $t1, $a0
  lw $t2, -8($fp)
  move $a0, $t2
  lw $t3, -376($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -372($fp)
  sw $t3, -376($fp)
  ble $a1, $a2, label31
  j label42
label31:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -380($fp)
  move $t1, $a0
  lw $t2, -8($fp)
  move $a0, $t2
  lw $t3, -384($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  sw $t1, -380($fp)
  sw $t3, -384($fp)
  ble $a1, $a2, label29
  j label42
label29:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -388($fp)
  move $t1, $a0
  lw $t2, -16($fp)
  move $a0, $t2
  lw $t3, -392($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -396($fp)
  move $t4, $a0
  lw $t5, -8($fp)
  move $a0, $t5
  lw $t6, -400($fp)
  move $t6, $a0
  move $a1, $t4
  move $a2, $t6
  sw $t1, -388($fp)
  sw $t3, -392($fp)
  sw $t4, -396($fp)
  sw $t6, -400($fp)
  ble $a1, $a2, label32
  j label33
label32:
  li $a0, 1
  lw $t0, -404($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t1, -408($fp)
  move $t1, $a0
  move $a0, $t1
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -404($fp)
  sw $t1, -408($fp)
  j label42
label33:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -412($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -416($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -420($fp)
  move $t3, $a0
  lw $t4, -16($fp)
  move $a0, $t4
  lw $t5, -424($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -428($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -432($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -436($fp)
  move $t0, $a0
  sw $t0, -436($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -440($fp)
  move $t0, $a0
  sw $t0, -440($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -444($fp)
  move $t0, $a0
  sw $t0, -444($fp)
  lw $t0, -440($fp)
  move $a1, $t0
  lw $t0, -444($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -448($fp)
  move $t0, $a0
  sw $t0, -448($fp)
  lw $t0, -436($fp)
  move $a1, $t0
  lw $t0, -448($fp)
  move $a2, $t0
  sw $t1, -412($fp)
  sw $t2, -416($fp)
  sw $t3, -420($fp)
  sw $t5, -424($fp)
  sw $t6, -428($fp)
  sw $t7, -432($fp)
  beq $a1, $a2, label35
  j label36
label35:
  li $a0, 1
  lw $t0, -452($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -452($fp)
  j label42
label36:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -456($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -460($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -464($fp)
  move $t3, $a0
  lw $t4, -16($fp)
  move $a0, $t4
  lw $t5, -468($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -472($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -476($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -480($fp)
  move $t0, $a0
  sw $t0, -480($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -484($fp)
  move $t0, $a0
  sw $t0, -484($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -488($fp)
  move $t0, $a0
  sw $t0, -488($fp)
  lw $t0, -484($fp)
  move $a1, $t0
  lw $t0, -488($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -492($fp)
  move $t0, $a0
  sw $t0, -492($fp)
  lw $t0, -480($fp)
  move $a1, $t0
  lw $t0, -492($fp)
  move $a2, $t0
  sw $t1, -456($fp)
  sw $t2, -460($fp)
  sw $t3, -464($fp)
  sw $t5, -468($fp)
  sw $t6, -472($fp)
  sw $t7, -476($fp)
  bgt $a1, $a2, label38
  j label39
label38:
  li $a0, 2
  lw $t0, -496($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -496($fp)
  j label42
label39:
  lw $t0, -24($fp)
  move $a0, $t0
  lw $t1, -500($fp)
  move $t1, $a0
  move $a0, $t0
  lw $t2, -504($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  mul $a0, $a1, $a2
  lw $t3, -508($fp)
  move $t3, $a0
  lw $t4, -16($fp)
  move $a0, $t4
  lw $t5, -512($fp)
  move $t5, $a0
  move $a0, $t4
  lw $t6, -516($fp)
  move $t6, $a0
  move $a1, $t5
  move $a2, $t6
  mul $a0, $a1, $a2
  lw $t7, -520($fp)
  move $t7, $a0
  move $a1, $t3
  move $a2, $t7
  add $a0, $a1, $a2
  lw $t0, -524($fp)
  move $t0, $a0
  sw $t0, -524($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -528($fp)
  move $t0, $a0
  sw $t0, -528($fp)
  lw $t0, -8($fp)
  move $a0, $t0
  lw $t0, -532($fp)
  move $t0, $a0
  sw $t0, -532($fp)
  lw $t0, -528($fp)
  move $a1, $t0
  lw $t0, -532($fp)
  move $a2, $t0
  mul $a0, $a1, $a2
  lw $t0, -536($fp)
  move $t0, $a0
  sw $t0, -536($fp)
  lw $t0, -524($fp)
  move $a1, $t0
  lw $t0, -536($fp)
  move $a2, $t0
  sw $t1, -500($fp)
  sw $t2, -504($fp)
  sw $t3, -508($fp)
  sw $t5, -512($fp)
  sw $t6, -516($fp)
  sw $t7, -520($fp)
  blt $a1, $a2, label41
  j label42
label41:
  li $a0, 3
  lw $t0, -540($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  sw $t0, -540($fp)
label42:
  li $a0, 0
  lw $t0, -544($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t0, -544($fp)
  jr $ra
