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
  addi $sp, $sp, -528
  li $a0, 0
  lw $t0, -28($fp)
  move $t0, $a0
  move $a0, $t0
  lw $t1, -32($fp)
  move $t1, $a0
  addi $t2, $fp, -24
  move $a0, $t2
  lw $t3, -36($fp)
  move $t3, $a0
  li $a0, 0
  lw $t4, -40($fp)
  move $t4, $a0
  move $a1, $t4
  li $a2, 8
  mul $a0, $a1, $a2
  lw $t5, -44($fp)
  move $t5, $a0
  move $a1, $t3
  move $a2, $t5
  add $a0, $a1, $a2
  lw $t6, -48($fp)
  move $t6, $a0
  move $a0, $t6
  lw $t7, -52($fp)
  move $t7, $a0
  move $a0, $t7
  sw $t0, -28($fp)
  lw $t0, -56($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -56($fp)
  lw $t0, -60($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -60($fp)
  lw $t0, -56($fp)
  sw $a0, 0($t0)
  move $a0, $t2
  lw $t0, -64($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -64($fp)
  lw $t0, -68($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
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
  li $a0, 3
  sw $t0, -84($fp)
  lw $t0, -88($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -88($fp)
  lw $t0, -92($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -92($fp)
  lw $t0, -84($fp)
  sw $a0, 0($t0)
  move $a0, $t2
  lw $t0, -96($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -96($fp)
  lw $t0, -100($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -100($fp)
  lw $t0, -104($fp)
  move $t0, $a0
  sw $t0, -104($fp)
  lw $t0, -96($fp)
  move $a1, $t0
  lw $t0, -104($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -108($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -108($fp)
  lw $t0, -112($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -112($fp)
  lw $t0, -116($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -116($fp)
  lw $t0, -120($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -120($fp)
  lw $t0, -124($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
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
  lw $a0, 0($t0)
  sw $t0, -136($fp)
  lw $t0, -140($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -140($fp)
  lw $t0, -144($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -144($fp)
  lw $t0, -116($fp)
  sw $a0, 0($t0)
  move $a0, $t2
  lw $t0, -148($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -148($fp)
  lw $t0, -152($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
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
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -164($fp)
  lw $t0, -168($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -168($fp)
  lw $t0, -172($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -172($fp)
  lw $t0, -176($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -176($fp)
  lw $t0, -180($fp)
  move $t0, $a0
  sw $t0, -180($fp)
  lw $t0, -172($fp)
  move $a1, $t0
  lw $t0, -180($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -184($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -184($fp)
  lw $t0, -188($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -188($fp)
  lw $t0, -192($fp)
  move $t0, $a0
  move $a0, $t2
  sw $t0, -192($fp)
  lw $t0, -196($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -196($fp)
  lw $t0, -200($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -200($fp)
  lw $t0, -204($fp)
  move $t0, $a0
  sw $t0, -204($fp)
  lw $t0, -196($fp)
  move $a1, $t0
  lw $t0, -204($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -208($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -208($fp)
  lw $t0, -212($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -212($fp)
  lw $t0, -216($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -216($fp)
  lw $t0, -220($fp)
  move $t0, $a0
  sw $t0, -220($fp)
  lw $t0, -192($fp)
  move $a1, $t0
  lw $t0, -220($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -224($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -224($fp)
  lw $t0, -168($fp)
  sw $a0, 0($t0)
  move $a0, $t2
  lw $t0, -228($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -228($fp)
  lw $t0, -232($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -232($fp)
  lw $t0, -236($fp)
  move $t0, $a0
  sw $t0, -236($fp)
  lw $t0, -228($fp)
  move $a1, $t0
  lw $t0, -236($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -240($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -240($fp)
  lw $t0, -244($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -244($fp)
  lw $t0, -248($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -248($fp)
  lw $t0, -252($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -252($fp)
  lw $t0, -248($fp)
  sw $a0, 0($t0)
  move $a0, $t2
  lw $t0, -256($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -256($fp)
  lw $t0, -260($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -260($fp)
  lw $t0, -264($fp)
  move $t0, $a0
  sw $t0, -264($fp)
  lw $t0, -256($fp)
  move $a1, $t0
  lw $t0, -264($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -268($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -268($fp)
  lw $t0, -272($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -272($fp)
  lw $t0, -276($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -276($fp)
  lw $t0, -280($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -280($fp)
  lw $t0, -276($fp)
  sw $a0, 0($t0)
  sw $t1, -32($fp)
  sw $t3, -36($fp)
  sw $t4, -40($fp)
  sw $t5, -44($fp)
  sw $t6, -48($fp)
  sw $t7, -52($fp)
label1:
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t1, -284($fp)
  move $t1, $a0
  li $a0, 2
  lw $t2, -288($fp)
  move $t2, $a0
  move $a1, $t1
  move $a2, $t2
  sw $t1, -284($fp)
  sw $t2, -288($fp)
  blt $a1, $a2, label2
  j label3
label2:
  addi $t0, $fp, -24
  move $a0, $t0
  lw $t1, -292($fp)
  move $t1, $a0
  li $a0, 2
  lw $t2, -296($fp)
  move $t2, $a0
  move $a1, $t2
  li $a2, 8
  mul $a0, $a1, $a2
  lw $t3, -300($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -304($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -308($fp)
  move $t5, $a0
  move $a0, $t5
  lw $t6, -312($fp)
  move $t6, $a0
  move $a0, $t0
  lw $t7, -316($fp)
  move $t7, $a0
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t0, -320($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -320($fp)
  lw $t0, -324($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -324($fp)
  lw $t0, -328($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -328($fp)
  lw $t0, -332($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -332($fp)
  lw $t0, -336($fp)
  move $t0, $a0
  sw $t0, -336($fp)
  addi $t0, $fp, -24
  move $a0, $t0
  lw $t0, -340($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -340($fp)
  lw $t0, -344($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -344($fp)
  lw $t0, -348($fp)
  move $t0, $a0
  sw $t0, -348($fp)
  lw $t0, -340($fp)
  move $a1, $t0
  lw $t0, -348($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -352($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -352($fp)
  lw $t0, -356($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -356($fp)
  lw $t0, -360($fp)
  move $t0, $a0
  sw $t0, -360($fp)
  lw $t0, -336($fp)
  move $a1, $t0
  lw $t0, -360($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -364($fp)
  move $t0, $a0
  move $a0, $t0
  sw $a0, 0($t6)
  sw $t0, -364($fp)
  addi $t0, $fp, -24
  move $a0, $t0
  lw $t0, -368($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -368($fp)
  lw $t0, -372($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -372($fp)
  lw $t0, -376($fp)
  move $t0, $a0
  sw $t0, -376($fp)
  lw $t0, -368($fp)
  move $a1, $t0
  lw $t0, -376($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -380($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -380($fp)
  lw $t0, -384($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -384($fp)
  lw $t0, -388($fp)
  move $t0, $a0
  li $a0, 0
  sw $t0, -388($fp)
  lw $t0, -392($fp)
  move $t0, $a0
  sw $t0, -392($fp)
  addi $t0, $fp, -24
  move $a0, $t0
  lw $t0, -396($fp)
  move $t0, $a0
  sw $t0, -396($fp)
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t0, -400($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -400($fp)
  lw $t0, -404($fp)
  move $t0, $a0
  sw $t0, -404($fp)
  lw $t0, -396($fp)
  move $a1, $t0
  lw $t0, -404($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -408($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -408($fp)
  lw $t0, -412($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -412($fp)
  lw $t0, -416($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -416($fp)
  lw $t0, -420($fp)
  move $t0, $a0
  sw $t0, -420($fp)
  lw $t0, -392($fp)
  move $a1, $t0
  lw $t0, -420($fp)
  move $a2, $t0
  sub $a0, $a1, $a2
  lw $t0, -424($fp)
  move $t0, $a0
  li $a1, 0
  move $a2, $t0
  sub $a0, $a1, $a2
  sw $t0, -424($fp)
  lw $t0, -428($fp)
  move $t0, $a0
  sw $t0, -428($fp)
  addi $t0, $fp, -24
  move $a0, $t0
  lw $t0, -432($fp)
  move $t0, $a0
  li $a0, 2
  sw $t0, -432($fp)
  lw $t0, -436($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -436($fp)
  lw $t0, -440($fp)
  move $t0, $a0
  sw $t0, -440($fp)
  lw $t0, -432($fp)
  move $a1, $t0
  lw $t0, -440($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -444($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -444($fp)
  lw $t0, -448($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -448($fp)
  lw $t0, -452($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -452($fp)
  lw $t0, -456($fp)
  move $t0, $a0
  sw $t0, -456($fp)
  lw $t0, -428($fp)
  move $a1, $t0
  lw $t0, -456($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -460($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -460($fp)
  lw $t0, -388($fp)
  sw $a0, 0($t0)
  lw $t0, -32($fp)
  move $a0, $t0
  lw $t0, -464($fp)
  move $t0, $a0
  li $a0, 1
  sw $t0, -464($fp)
  lw $t0, -468($fp)
  move $t0, $a0
  sw $t0, -468($fp)
  lw $t0, -464($fp)
  move $a1, $t0
  lw $t0, -468($fp)
  move $a2, $t0
  add $a0, $a1, $a2
  lw $t0, -472($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -472($fp)
  lw $t0, -32($fp)
  move $t0, $a0
  sw $t0, -32($fp)
  sw $t1, -292($fp)
  sw $t2, -296($fp)
  sw $t3, -300($fp)
  sw $t4, -304($fp)
  sw $t5, -308($fp)
  sw $t6, -312($fp)
  sw $t7, -316($fp)
  j label1
label3:
  addi $t0, $fp, -24
  move $a0, $t0
  lw $t1, -476($fp)
  move $t1, $a0
  li $a0, 2
  lw $t2, -480($fp)
  move $t2, $a0
  move $a1, $t2
  li $a2, 8
  mul $a0, $a1, $a2
  lw $t3, -484($fp)
  move $t3, $a0
  move $a1, $t1
  move $a2, $t3
  add $a0, $a1, $a2
  lw $t4, -488($fp)
  move $t4, $a0
  move $a0, $t4
  lw $t5, -492($fp)
  move $t5, $a0
  lw $a0, 0($t5)
  lw $t6, -496($fp)
  move $t6, $a0
  move $a0, $t6
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  move $a0, $t0
  lw $t7, -500($fp)
  move $t7, $a0
  li $a0, 2
  lw $t0, -504($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 8
  mul $a0, $a1, $a2
  sw $t0, -504($fp)
  lw $t0, -508($fp)
  move $t0, $a0
  move $a1, $t7
  move $a2, $t0
  add $a0, $a1, $a2
  sw $t0, -508($fp)
  lw $t0, -512($fp)
  move $t0, $a0
  move $a0, $t0
  sw $t0, -512($fp)
  lw $t0, -516($fp)
  move $t0, $a0
  move $a1, $t0
  li $a2, 4
  add $a0, $a1, $a2
  sw $t0, -516($fp)
  lw $t0, -520($fp)
  move $t0, $a0
  lw $a0, 0($t0)
  sw $t0, -520($fp)
  lw $t0, -524($fp)
  move $t0, $a0
  move $a0, $t0
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal write
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  li $a0, 0
  sw $t0, -524($fp)
  lw $t0, -528($fp)
  move $t0, $a0
  move $sp, $fp
  move $v0, $t0
  sw $t1, -476($fp)
  sw $t2, -480($fp)
  sw $t3, -484($fp)
  sw $t4, -488($fp)
  sw $t5, -492($fp)
  sw $t6, -496($fp)
  sw $t7, -500($fp)
  sw $t0, -528($fp)
  jr $ra
